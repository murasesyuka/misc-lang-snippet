require 'sinatra'
require 'rack-livereload'
require "sinatra/reloader" if development?
use Rack::LiveReload


get '/' do
  'Hello world!'
end

get %r{/hello/([\w]+)} do
  "Hello, #{params[:captures].first}!"
end

get '/say/*/to/*' do
  # matches /say/hello/to/world
  params[:splat] #=> ["hello", "world"]
end

get '/download/*.*' do |path, ext|
  # matches /download/path/to/file.xml
  [path, ext] #=> ["path/to/file", "xml"]
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


