from ..mongo                                           import myMongo
from yowsup.layers.interface                           import YowInterfaceLayer, ProtocolEntityCallback
import requests
import json

class EchoLayer(YowInterfaceLayer):

    @ProtocolEntityCallback("message")
    def onMessage(self, messageProtocolEntity):

        if messageProtocolEntity.getType() == 'text':
            self.onTextMessage(messageProtocolEntity)
        elif messageProtocolEntity.getType() == 'media':
            self.onMediaMessage(messageProtocolEntity)

        # self.toLower(messageProtocolEntity.forward(messageProtocolEntity.getFrom()))
        self.toLower(messageProtocolEntity.ack())
        self.toLower(messageProtocolEntity.ack(True))


    @ProtocolEntityCallback("receipt")
    def onReceipt(self, entity):
        self.toLower(entity.ack())

    def onTextMessage(self,messageProtocolEntity):
        # just print info
        print("Echoing again %s to %s" % (messageProtocolEntity.getBody(), messageProtocolEntity.getFrom(False)))

        url = 'http://192.168.1.3:8000/message/'
        data = {'api_type' : 'Incoming', 'phone' : messageProtocolEntity.getFrom(False), 'message' : messageProtocolEntity.getBody(), 'message_type' : 'text'}
        r = requests.post(url,  data=json.dumps(data))
        print r.content

    #### If data type is not text - Image or location or vCard

    def onMediaMessage(self, messageProtocolEntity):
        # just print info
        if messageProtocolEntity.getMediaType() == "image":
            print("Echoing image %s to %s" % (messageProtocolEntity.url, messageProtocolEntity.getFrom(False)))
            url = 'http://localhost:8000/message'
            data = {'phone' : messageProtocolEntity.getFrom(False), 'message' : messageProtocolEntity.url, 'message_type' : 'image'}
            r = requests.post(url,  data=json.dumps(data))
            print r.content

        elif messageProtocolEntity.getMediaType() == "location":
            print("Echoing location (%s, %s) to %s" % (messageProtocolEntity.getLatitude(), messageProtocolEntity.getLongitude(), messageProtocolEntity.getFrom(False)))
            # url = 'http://localhost:8000/message'
            # data = {'primary_id': '6', 'phone' : messageProtocolEntity.getFrom(False), 'message' : messageProtocolEntity.url, 'message_type' : 'image'}
            # r = requests.post(url,  data=json.dumps(data))
            # print r.content