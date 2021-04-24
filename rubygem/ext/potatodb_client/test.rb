
require './potatodb_client'

puts PotatoDB.version

client = PotatoDB::Client.new("localhost")

response = client.request("SELECT * FROM foobar")
puts response
