"""
Author  : Ibrahim Elsaid Saad & Ahmed Fathy Elsaka
program : we send mail to the mail server by using smtp 
		  protocol this program deals with (gmail and outlook)
		  in the gmail you need first support in the sender mail
		  (allow less secure apps to access in settings) 
		  to can send message to anthor mail server.
"""
import smtplib
import sys
import getpass
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

class MailClient(object):
	def __init__(self):
		pass

	def startservce(self):
		print("**Write $ at the end of message to end it")
		while True:
			# Get info about the sender and the reciever persons
			self.GetInfo() 
			#compose the message
			self.Compose()
			# send the message to the target      
			problems = self.sendemail(self.Smtpserver())
			while self.sendemail(self.Smtpserver()):
				if input('is your Info is right [y/n]: ') == 'n':
					break
			if input('Send New Message [y/n] :') == 'n':
				break
		pass

	def GetInfo(self):
			self.sendEmail  = input('Your Email : ')
			self.sendPasswd = getpass.getpass('Your PassWord : ')
			self.toEmail    = input('Send_To : ')
			self.subject    = input('Subject : ')
			print('Message (Enter at the end $ to refer to the end of the msg): ')

			self.message = ''
			while True:
				line = input()
				if(line.find('$') == len(line)-1):
					self.message = self.message + line[:len(line)-1]
					break
				else:
					self.message = self.message + line + '\n'

	def Smtpserver(self):
		if self.message.find('gmail') != len(self.message):
			return 'smtp.gmail.com:587'
		elif self.message.find('outlook') != len(self.message):
			return 'smtp-mail.outlook.com:587'
		else:
			return 'we do not support this mail'
			sys.exit(0)
		pass
	def Compose(self):
		self.header  = ('From: %s\n' % self.sendEmail)
		self.header += ('To: %s\n' % ','.join(self.toEmail))
		self.header += ('Subject: %s\n\n' % self.subject)
		self.message = self.header + self.message

	def sendemail(self, smtpserver):
		#start stmp connection 
		self.server = smtplib.SMTP(smtpserver)
		#encrypt messages and commands
		self.server.starttls()
		#login to the server
		try:
			self.server.login(self.sendEmail, self.sendPasswd)
		except:
			print('authentication fails')
			return
		#send the message
		problems = self.server.sendmail(self.sendEmail, self.toEmail, self.message)
		#quit the server
		self.server.quit()
		return problems


def main():
	mailclient = MailClient()
	mailclient.startservce()

	pass
if __name__ == '__main__':
	main()