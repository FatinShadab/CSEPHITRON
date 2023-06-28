from django.apps import AppConfig
from django.db.models.signals import pre_delete
from .signals import pre_borrowed_book_delete


class BookManagmentSystemConfig(AppConfig):
    default_auto_field = 'django.db.models.BigAutoField'
    name = 'book_managment_system'

    def ready(self):
        pre_delete.connect(pre_borrowed_book_delete, sender='book_managment_system.BorrowedBook')
