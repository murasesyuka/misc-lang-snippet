require 'sinatra'

get '/' do
  'Hello world!'
end

get '/hello/:name' do |n|
  "Hello #{n}!"
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


