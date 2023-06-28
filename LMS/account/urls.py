from django.urls import path
from . import views

urlpatterns = [
    path('signup/', views.signup, name="signup"),
    path('login/', views.user_login, name="login"),
    path('logout/', views.user_logout, name="logout"),
    path('profile/', views.profile, name="profile"),
    path('notification/<int:pk>', views.delete_notification, name="delete_notification")
]
