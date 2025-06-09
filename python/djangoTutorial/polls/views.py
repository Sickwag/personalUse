from django.shortcuts import render
from django.http import HttpResponse

def index(requeest):
    return HttpResponse("hello from django")

# Create your views here.
