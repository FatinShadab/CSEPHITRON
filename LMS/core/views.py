from django.shortcuts import render, HttpResponse, redirect

def home(request):
    if not request.user.is_authenticated:
        return render(request, template_name='home.html', context={"user":request.user})
    else:
        return redirect('catalog')