from django.db import models
from .utils import GENRE_CHOICES, PER_DAY_FINE_TK, MAX_DUE_DAYS
from datetime import datetime, timedelta
from django.utils import timezone
from django.contrib.auth.models import User


class Book(models.Model):
    title = models.CharField(max_length=100, null=False, blank=False)
    author = models.CharField(max_length=100, null=False, blank=False)
    isbn = models.IntegerField(null=False, blank=False, unique=True)
    publication_data = models.DateField(null=False, blank=False)
    genre = models.CharField(max_length=100, choices=GENRE_CHOICES, null=False, blank=False)
    available = models.BooleanField(null=False, blank=False)
    stock_quantity = models.IntegerField(null=False, blank=False)

    def reduce_quantity(self, amount=1):
        self.stock_quantity -= amount
        self.save()

    def increase_quantity(self, amount=1):
        self.stock_quantity += amount
        self.save()

    def alter_available_status(self):
        if self.stock_quantity > 0:
            self.available = True
        else:
            self.available = False
            
        self.save()

    def save(self, *args, **kwargs):
        from account.models import Notification

        super().save(*args, **kwargs)

        reservations = Reservation.objects.all().filter(book=self)
        
        [Notification(user=reservation.user, msg=f"{self.title} is now available ! stock quantity {self.stock_quantity}", reservation=reservation).save() for reservation in reservations if self.available]

    def __str__(self):
        return self.title


class BorrowedBook(models.Model):
    class Meta:
        unique_together = (("user", "book"),)

    user = models.ForeignKey(User, on_delete=models.CASCADE, related_name="borrowed_book")
    book = models.ForeignKey(Book, on_delete=models.CASCADE, related_name="borrowed_book")
    borrowed_date = models.DateTimeField(auto_now_add=True)
    return_date = models.DateField(default=datetime.now() + timedelta(days=MAX_DUE_DAYS))

    def calculate_fine(self):
        fine = 0
        due_date = self.borrowed_date + timedelta(days=MAX_DUE_DAYS)
        current_datetime = timezone.now()

        if current_datetime > due_date:
            days_overdue = (current_datetime - due_date).days
            fine += days_overdue * PER_DAY_FINE_TK

        return fine

    def save(self, *args, **kwargs):
        from account.models import Notification

        self.book.reduce_quantity()

        if self.book.stock_quantity == 0:
            self.book.alter_available_status()

        super().save(*args, **kwargs)

        Notification(user=self.user, msg=f"You have less than 3 days to return the book : {self.book.title}", borrowed_book=self).save()

    def __str__(self):
        return f"{self.book.title} - {self.user.username}"


class Reservation(models.Model):
    class Meta:
        unique_together = (("user", "book"),)
        
    user = models.ForeignKey(User, on_delete=models.CASCADE, related_name="reserve_books")
    book = models.ForeignKey(Book, on_delete=models.CASCADE, related_name="reserve_books")

    def __str__(self):
        return f"{self.book.title} - {self.user.username}"