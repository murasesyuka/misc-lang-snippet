
# Echo server program
import socket,os

s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)

s.bind("/tmp/socket")
s.listen(1)
conn, addr = s.accept()

while 1:
    data = conn.recv(1024)
    if not data: break
    conn.send(data)
    
conn.close()
