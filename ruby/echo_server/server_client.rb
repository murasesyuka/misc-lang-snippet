require 'socket'

UNIXServer.open("/tmp/sock") {|serv|
  UNIXSocket.open("/tmp/sock") {|c|
    s = serv.accept
    s.puts "hi"
    s.close
    p c.read #=> "hi\n"
  }
}


