import socket

s = socket.socket()

host = "afsaccess1.njit.edu"
port = 50007

s.connect((host, port))

msg = input('Client: ')

s.send(msg.encode())

print (s.recv(1024).decode())

s.close
print ('Client: Connection closed')
