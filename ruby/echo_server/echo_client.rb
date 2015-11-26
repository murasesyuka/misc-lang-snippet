require 'socket'

s = Socket.new(Socket::AF_UNIX, Socket::SOCK_STREAM)
s.connect(Socket.pack_sockaddr_un("/tmp/socket"))
s.send("hello, pyhton echo server", 0)

puts "Received, #{s.recv(1024)}"
s.close
