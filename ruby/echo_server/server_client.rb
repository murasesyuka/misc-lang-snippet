require 'socket'
require 'fileutils'

PathSock = "/tmp/sock"

FileUtils.rm PathSock if File.exist? PathSock

UNIXServer.open(PathSock) {|serv|
  UNIXSocket.open(PathSock) {|c|
    s = serv.accept
    s.puts "hi"
    s.close
    p c.read #=> "hi\n"
  }
}


