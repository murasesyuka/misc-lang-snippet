require 'sinatra'

get '/' do
  'Hello world!'
end

get '/hello/:name' do
  "Hello #{params[:name]}"
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


