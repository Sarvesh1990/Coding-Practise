from .models import OutgoingMessage
from .models import IncomingMessage
from django.http import Http404
from datetime import datetime

from restapp.serializers import OutgoingMessageSerializer
from restapp.serializers import IncomingMessageSerializer
from restapp.serializers import ConversationSerializer
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status

from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt
from rest_framework.renderers import JSONRenderer
from rest_framework.parsers import JSONParser

from hackathon_whatsapp.sendclient.stack import YowsupSendStack
from hackathon_whatsapp import Credentials
from rest_example import settings
import logging

logger = logging.getLogger(__name__)


class JSONResponse(HttpResponse):
	"""
	An HttpResponse that renders its content into JSON.
	"""
	def __init__(self, data, **kwargs):
		content = JSONRenderer().render(data)
		kwargs['content_type'] = 'application/json'
		super(JSONResponse, self).__init__(content, **kwargs)

@csrf_exempt
def message_list(request):
	"""
	List all code snippets, or create a new snippet.
	"""
	limit = settings.PAGE_LIMIT
	pn = 0

	if request.method == 'GET':	
		#Check if page number is sent, if not by default show first page
		if 'pn' in request.GET :
			pn = int(request.GET['pn'])*limit
			limit = pn + limit
		#Check if phone number is sent, if not send message for all phone numbers
		if 'phone' in request.GET :
			number = request.GET['phone']
			outgoingMessages = OutgoingMessage.objects.filter(phone=number).order_by('-created_at')[0:limit]
			incomingMessages = IncomingMessage.objects.filter(phone=number).order_by('-created_at')[0:limit]
		else:
			outgoingMessages = OutgoingMessage.objects.all().order_by('-created_at')[0:limit]
			incomingMessages = IncomingMessage.objects.all().order_by('-created_at')[0:limit]

		serializerOutgoing = OutgoingMessageSerializer(outgoingMessages, many=True)
		serializerIncoming = IncomingMessageSerializer(incomingMessages, many=True)
		
		outgoingData = []
		incomingData = []
		incomingIndex = 0
		outgoingIndex = 0

		#Crawl data and decide out of given limit how many outgoing message and incoming message will be there based on created_at
		for i in range (0, limit):
			if((len(serializerOutgoing.data) > outgoingIndex) and (serializerOutgoing.data[outgoingIndex]['created_at'] > serializerIncoming.data[incomingIndex]['created_at'])):
				if(i >= (limit - settings.PAGE_LIMIT)):
					outgoingData.append(serializerOutgoing.data[outgoingIndex])
				outgoingIndex += 1
			else :
				if(len(serializerIncoming.data) > incomingIndex):
					if(i >= (limit - settings.PAGE_LIMIT)):
						incomingData.append(serializerIncoming.data[incomingIndex])
					incomingIndex += 1

		data = []
		data.append(outgoingData)
		data.append(incomingData)
		return JSONResponse(data)

	elif request.method == 'POST':
		data = JSONParser().parse(request)
		data['created_at'] =  datetime.now().strftime('%Y-%m-%d %H:%M:%S')
		
		#Check to decide whether entry needs to be done in Incoming database of Outgoing
		if (data['api_type'] == 'Incoming'):
			data['primary_id'] = IncomingMessage.objects.count()+1
			serializer = IncomingMessageSerializer(data=data)
		else :
			data['primary_id'] = OutgoingMessage.objects.count()+1
			serializer = OutgoingMessageSerializer(data=data)

			#Call youwsup to send message to user
			a = YowsupSendStack([Credentials.PHONE, Credentials.PASSWORD], [[data['phone'], data['message']]])
			try:
				a.start()
			except KeyboardInterrupt as e:
				logger.info("Keyboard Interrupt")
		
		#Remove api_type which was sent to decide incoming/outgoing
		if 'api_type' in data :
			del data['api_type']
		
		if serializer.is_valid():
			serializer.save()
			return JSONResponse(serializer.data, status=status.HTTP_201_CREATED)
	
		return JSONResponse(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

@csrf_exempt
def conversation_list(request):
	"""
	List all code snippets, or create a new snippet.
	"""
	limit = settings.PAGE_LIMIT
	pn = 0 

	if request.method == 'GET':	
		if 'pn' in request.GET :
			pn = int(request.GET['pn'])*limit
			limit = pn + limit

		conversations = IncomingMessage.objects.all().order_by('-created_at')
		serializerConversation = ConversationSerializer(conversations, many=True)
		
		dataList = []
		
		#Get only distinct phone numbers
		distinctPhone = []
		for data in serializerConversation.data :
			if data['phone'] not in distinctPhone :
				dataList.append(data)
				distinctPhone.append(data['phone'])
		
		return JSONResponse(dataList[pn:limit])
