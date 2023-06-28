from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from django.contrib.auth.models import User
from .models import Wishlist
from django import forms

class SignupForm(UserCreationForm):
    email = forms.EmailField(required=True)

    class Meta:
        model = User
        fields = ('username', 'email', 'password1', 'password2')

    def save(self, commit=True):
        user = super().save(commit=False)
        user.email = self.cleaned_data['email']
        
        if commit:
            user.save()
            wishlist = Wishlist(user=user)
            wishlist.save()

        return user


class LoginForm(AuthenticationForm):
    username = forms.CharField(label="Username", widget=forms.TextInput(attrs={'class': 'form-control'}))
    password = forms.CharField(label="Password", widget=forms.PasswordInput(attrs={'class': 'form-control'}))