require 'sinatra'
require 'rack-livereload'
require "sinatra/reloader" if development?
use Rack::LiveReload

class Stream
  def each
    100.times {|i| yield "#{i}\n" }
  end
end

get '/' do
  Stream.new
end

get '/', :host_name => /^admin\./ do
  "Admin Area, Access denied!"
end

get '/', :provides => 'html' do
  haml :index
end

get '/', :provides => ['rss', 'atom', 'xml'] do
  builder :feed
end

get '/foo', :agent => /Songbird (\d.\d)[\d\/]*?/ do
  "You're using Songbird version #{params[:agent][0]}"
end

set(:probability){ |value| condition { rand <= value } }

get '/win_a_car', :probability => 0.1 do
  "You won!"
end

get '/win_a_car' do
  "Sorry, you lost"
end

set(:auth) do |*roles|   # <- notice the splat here
  condition do
    unless logged_in? && roles.any? {|role| current_user.in_role? role }
      redirect "/login/", 303
    end
  end
end

get '/my/account/', :auth => [:user, :admin] do
  "Your Account Details"
end

get '/only/admin/', :auth => :admin do
  "Only admins are allowed here!"
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


