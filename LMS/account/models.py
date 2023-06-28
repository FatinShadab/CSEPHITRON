from django.db import models
from django.contrib.auth.models import User
from book_managment_system.models import Book, BorrowedBook, Reservation

class Wishlist(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE, related_name='wishlist')
    books = models.ManyToManyField(Book, blank=True, related_name='wishlists')

    def __str__(self):
        return f"Wishlist for {self.user.username}"


class Notification(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE, related_name="notifications")
    msg = models.CharField(max_length=300, null=False, blank=False)
    borrowed_book = models.OneToOneField(BorrowedBook, on_delete=models.CASCADE, null=True, blank=True)
    reservation = models.OneToOneField(Reservation, on_delete=models.CASCADE, null=True, blank=True)

    def __str__(self):
        return f"{self.msg[:50]} - {self.user.username}"
