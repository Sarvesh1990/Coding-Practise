from . import models

from rest_framework import serializers

class OutgoingMessageSerializer(serializers.ModelSerializer):
	class Meta:
		model = models.OutgoingMessage
		fields = ('primary_id', 'phone', 'message', 'message_type', 'created_at')

class IncomingMessageSerializer(serializers.ModelSerializer):
	class Meta:
		model = models.IncomingMessage
		fields = ('primary_id', 'phone', 'message', 'message_type', 'created_at')

class ConversationSerializer(serializers.ModelSerializer):
	class Meta:
		model = models.IncomingMessage
		fields = ('phone', 'message')