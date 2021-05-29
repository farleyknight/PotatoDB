require './potatodb_client'
require 'sinatra'

puts PotatoDB.version

client = PotatoDB::Client.new("localhost")

get '/' do
  'Put this in your pipe & smoke it!'
end
