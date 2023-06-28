from django.shortcuts import render, redirect, HttpResponse
from django.contrib.auth import authenticate, login, logout
from .forms import SignupForm, LoginForm
from book_managment_system.models import BorrowedBook, Reservation
from .models import Notification, Wishlist
from datetime import datetime, timedelta
from django.utils import timezone


def signup(request):
    form = SignupForm()

    if request.method == 'POST':
        form = SignupForm(request.POST)
        if form.is_valid():
            form.save(commit=True)
            user = authenticate(request, username=form.cleaned_data['username'], password=form.cleaned_data['password2'])
            login(request, user)
            return redirect("profile")

    return render(request, template_name="signup.html", context={"user":request.user, "form":form})

def user_login(request):
    form = LoginForm()
    if request.method == 'POST':
        form = LoginForm(request, data=request.POST)
        if form.is_valid():
            user = authenticate(request, username=form.cleaned_data['username'], password=form.cleaned_data['password'])
            login(request, user)
            return redirect("profile")

    return render(request, template_name="login.html", context={"user":request.user, "form":form})

def user_logout(request):
    logout(request)
    return redirect('home')

def profile(request):
    try:
        # fall safe for admin acoount created by terminal
        wishlist = request.user.wishlist.books.all()
    except:
            wishlist = Wishlist(user=request.user)
            wishlist.save()
            wishlist = request.user.wishlist.books.all()
        
    fine = 0

    user_borrowed_books = BorrowedBook.objects.filter(user=request.user)

    for book in user_borrowed_books:
        fine += book.calculate_fine()

    notifications = []

    current_date = timezone.now().date()
    three_days_from_now = current_date + timedelta(days=3)

    for notification in Notification.objects.all().filter(user=request.user):
        if notification.borrowed_book == None:
            notifications.append(notification)
        else:
            return_date = notification.borrowed_book.return_date

            if return_date is not None and return_date <= three_days_from_now:
                notifications.append(notification)

    context = {
            "user":request.user,
            "borrowed_books": user_borrowed_books,
            "reserve_books": Reservation.objects.filter(user=request.user),
            "wishlist_books": wishlist,
            "notifications": notifications,
            "fine": fine
        }

    return render(request, template_name='profile.html', context=context)

def delete_notification(request, pk):
    notification = Notification.objects.all().filter(user=request.user, pk=pk)
    notification.delete()
    return redirect(request.META.get('HTTP_REFERER'))