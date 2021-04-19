
require './potatodb_client'

puts PotatoDB.version

client = PotatoDB::Client.new("localhost")

response = client.request("hello!\n")
puts response
