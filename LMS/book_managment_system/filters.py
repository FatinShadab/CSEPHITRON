import django_filters
from .models import Book

class BookFilter(django_filters.FilterSet):
    title = django_filters.CharFilter(lookup_expr='icontains')

    class Meta:
        model = Book
        fields = ['title']