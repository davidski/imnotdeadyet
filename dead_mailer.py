#!/usr/bin/env python

import boto3
from random import sample

def acknowledge_send():
	print "Acknowledge"


def indicate_failure():
	print "Failure"


def set_message_body(selection):
	switcher = {
		'0': "I'm here!",
		'1': "Brrrraaaaains!",
		'2': "Arrived!"
	}
	return switcher.get(str(selection), 'nothing')


if __name__ == "__main__":

	client = boto3.client('ses')

	# read input
	selection  = sample([0, 1, 2], 1)[0]
	#selection = 1

	# set message body
	message_body = set_message_body(selection)

	# send email
	response = client.send_email(
		Source='david@severski.net',
		Message={
			'Subject': {
				'Data': 'Here!',
			},
			'Body': {
				'Text': {
					'Data': message_body,
				}
			}
		},
		Destination={'ToAddresses': ['davidski@deadheaven.com']}
	)

	# check response
	if 'MessageId' in response:
		print('Sent, with a message ID of {}'.format(response['MessageId']))
		acknowledge_send()
	else:
		print('Could not find a valid response')
		print response
		indicate_failure()
