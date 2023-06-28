from django.db.models.signals import pre_delete
from django.dispatch import receiver

@receiver(pre_delete, sender='book_managment_system.BorrowedBook')
def pre_borrowed_book_delete(sender, instance, **kwargs):
    instance.book.increase_quantity()
    instance.book.alter_available_status()
