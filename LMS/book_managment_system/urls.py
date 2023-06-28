from django.urls import path
from . import views

urlpatterns = [
    path('catalog/', views.catalog, name="catalog"),
    path('book_detail/<int:isbn>/', views.book_details, name="book_detail"),
    path('reserve/<int:isbn>/', views.reserve, name="reserve"),
    path('unresrve/<int:isbn>', views.unresrve, name="unresrve"),
    path('borrow/<int:isbn>/', views.borrow, name="borrow"),
    path('return/<int:isbn>/', views.return_book, name="return"),
    path('add_to_wishlist/<int:isbn>/', views.add_to_wishlist, name="add_to_wishlist"),
    path('remove_from_wishlist/<int:isbn>/', views.remove_from_wishlist, name="remove_from_wishlist")
]
