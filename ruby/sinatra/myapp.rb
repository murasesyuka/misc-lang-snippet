require 'sinatra'
require 'rack-livereload'
require "sinatra/reloader" if development?
use Rack::LiveReload


get '/' do
  'Hello world!'
end

get '/foo', :agent => /Songbird (\d.\d)[\d\/]*?/ do
  "You're using Songbird version #{params[:agent][0]}"
end

get '/foo' do
  # Matches non-songbird browsers
  "You're not using Songbird"
end

get %r{/hello/([\w]+)} do |c|
  "Hello, #{c}!"
end

get '/say/*/to/*' do
  # matches /say/hello/to/world
  params[:splat] #=> ["hello", "world"]
end

get '/download/*.*' do |path, ext|
  # matches /download/path/to/file.xml
  [path, ext] #=> ["path/to/file", "xml"]
end

get '/posts.?:format?' do |ext|
  "format #{ext}" # matches "GET /posts" and any extension "GET /posts.json", "GET /posts.xml" etc.
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


