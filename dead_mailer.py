#!/usr/bin/env python3

import boto3

client = boto3.client('ses')

client.send_email(
	Source='david@severski.net',
	Message={
		'Subject': {
			'Data': 'Here!',
		},
		'Body': {
			'Text': {
				'Data': "I'm not dead yet!",
			}
		}
	},
	Destination={'ToAddresses': ['davidski@deadheaven.com']}
)

