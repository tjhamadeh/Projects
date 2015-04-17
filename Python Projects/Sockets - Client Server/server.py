import socket
import sys

s = socket.socket()

host = ''
port = 50007

try:
	s.bind((host, port))
except (s.error, msg):
	print ('Bind failed. Error Code: ' + str(msg[0]) + ' Message ' + msg[1])
	sys.exit()
	
print ('Socket bind complete')
s.listen(1)

while True:
	client, addr = s.accept()
	
	print ('Got connection from', addr)
	msg = 'Server: You are connected'
	client.send(msg.encode())
	msg = client.recv(1024).decode()
	print('Client: ', msg)
	
	client.close()
	break;
