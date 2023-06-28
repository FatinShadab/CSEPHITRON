from django.shortcuts import render, redirect, HttpResponse, get_object_or_404
from .filters import BookFilter
from .models import Book, BorrowedBook, Reservation
from account.models import Wishlist


def catalog(request):
    book_filter = BookFilter(request.GET, queryset=Book.objects.all())
    books = book_filter.qs

    return render(request, template_name="catalog.html", context={"user": request.user, "Books":books, "filter":book_filter})

def book_details(request, isbn):
    user = request.user
    book = Book.objects.get(isbn=isbn)

    context = {
        "user": user,
        "Book": book,
        "allow_reserve": None,
        "allow_wishlist": None,
        "allow_borrow": None
    }

    if request.user.is_authenticated:
        is_book_reserved = Reservation.objects.filter(book=book, user=user).exists()
        is_book_in_wishlist = Wishlist.objects.filter(books=book, user=user).exists()
        is_book_borrowed = BorrowedBook.objects.filter(user=user, book=book).exists()

        context["allow_reserve"] = not is_book_reserved
        context["allow_wishlist"] = not is_book_in_wishlist
        context["allow_borrow"] = not is_book_borrowed

    return render(request, template_name="book_details.html", context=context)

def reserve(request, isbn):
    user = request.user
    book = Book.objects.get(isbn=isbn)

    is_book_reserved = Reservation.objects.filter(book=book, user=user).exists()

    if not is_book_reserved:
        reservation = Reservation(book=book, user=user)
        reservation.save()

    return redirect('book_detail', isbn)

def unresrve(request, isbn):
    prev_page = request.META.get('HTTP_REFERER')
    user = request.user
    book = get_object_or_404(Book, isbn=isbn)

    reservation = get_object_or_404(Reservation, book=book, user=user)

    reservation.delete()

    return redirect(prev_page)

def borrow(request, isbn):
    user = request.user
    book = get_object_or_404(Book, isbn=isbn)

    reservation = Reservation.objects.filter(book=book, user=user).first()
    if reservation:
        reservation.delete()

    borrowed_book = BorrowedBook(user=request.user, book=Book.objects.get(isbn=isbn))
    borrowed_book.save()

    return redirect('profile')

def return_book(request, isbn):
    book = get_object_or_404(Book, isbn=isbn)
    borrowed_book = get_object_or_404(BorrowedBook, user=request.user, book=book)

    borrowed_book.delete()

    return redirect(request.META.get('HTTP_REFERER'))

def add_to_wishlist(request, isbn):
    user = request.user
    book = Book.objects.get(isbn=isbn)

    wishlist = user.wishlist
    is_book_in_wishlist = wishlist.books.filter(pk=book.pk).exists()

    if not is_book_in_wishlist:
        wishlist.books.add(book)

    return redirect('book_detail', isbn)

def remove_from_wishlist(request, isbn):
    user = request.user
    book = get_object_or_404(Book, isbn=isbn)

    wishlist = user.wishlist
    is_book_in_wishlist = wishlist.books.filter(pk=book.pk).exists()

    if is_book_in_wishlist:
        wishlist.books.remove(book)

    return redirect(request.META.get('HTTP_REFERER'))

