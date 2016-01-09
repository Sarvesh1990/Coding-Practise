from django.conf.urls import patterns, include, url
from django.contrib import admin

from restapp import views

admin.autodiscover()
urlpatterns = patterns('',
url(r'^admin/', include(admin.site.urls)),
url(r'^message/', views.message_list),
url(r'^conversation/', views.conversation_list),)
