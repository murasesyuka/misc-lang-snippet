require 'sinatra'

get '/' do
  'Hello world!'
end

get '/hello/:name' do |n|
  "Hello #{n}!"
end

get '/say/*/to/*' do
  # matches /say/hello/to/world
  params[:splat] #=> ["hello", "world"]
end

get '/download/*.*' do
  # matches /download/path/to/file.xml
  params[:splat] #=> ["path/to/file", "xml"]
end

post '/' do
  # .. create something
end

put '/' do
  # .. replace something
end

patch '/' do
  # .. modify something
end

delete '/' do
  # .. annihilate something
end

options '/' do
  # .. appease something
end


