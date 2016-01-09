import pymongo
from bson.objectid import ObjectId
import datetime
from itertools import chain

class myMongo():
	def get_db(self):
		from pymongo import MongoClient
		client = MongoClient('localhost:27017')
		db = client.myFirstMongoDB
		return db

	def print_incoming_messages(self):
		db = self.get_db()
		cursor = db.incoming_messages.find()
		for message_data in cursor:
			print message_data

	def print_outgoing_messages(self):
		db = self.get_db()
		cursor = db.outgoing_messages.find()
		for message_data in cursor:
			print message_data

	def insert_incoming_message(self, phone, message, data_type = 'text'):
		db = self.get_db()
		db.incoming_messages.insert({'phone': phone, 'message':message, 'created_at':datetime.datetime.utcnow(), 'type':data_type})
		self.print_incoming_messages()

	def insert_outgoing_message(self, phone, message, data_type = 'text'):
		db = self.get_db()
		db = get_db()
		db.outgoing_messages.insert({'phone': phone, 'message':message, 'created_at':datetime.datetime.utcnow(), 'type':data_type})
		self.print_outgoing_messages()


	def get_last_messages(self, phone, n_msg):
		db = self.get_db()
		cursor_in = db.incoming_messages.find().sort('created_at', pymongo.DESCENDING).limit(n_msg)
		cursor_out = db.outgoing_messages.find().sort('created_at', pymongo.DESCENDING).limit(n_msg)
		all_messages = {'incoming': cursor_in.toArray(), 'outgoing': cursor_out.toArray()}
		return all_messages