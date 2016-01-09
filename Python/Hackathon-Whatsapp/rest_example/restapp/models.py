from django.db import models
from djangotoolbox import fields
from django_mongodb_engine.contrib import MongoDBManager

class OutgoingMessage(models.Model):
	objects = MongoDBManager()
	primary_id = models.IntegerField(primary_key = True)
	phone = models.TextField()
	message = models.TextField()
	message_type = models.TextField()
	created_at = models.DateTimeField()

class IncomingMessage(models.Model):
	primary_id = models.IntegerField(primary_key = True)
	phone = models.TextField()
	message = models.TextField()
	message_type = models.TextField()
	created_at = models.DateTimeField()
	objects = MongoDBManager()
	
