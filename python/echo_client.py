import socket

s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
s.connect("/tmp/socket")
s.send('Hello, world')
data = s.recv(1024)
s.close()
print 'Received', repr(data)
