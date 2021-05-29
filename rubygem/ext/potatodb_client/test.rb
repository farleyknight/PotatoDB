require './potatodb_client'

puts PotatoDB.version

client = PotatoDB::Client.new("localhost")

commands = [
  "CREATE TABLE foo_bar ( colA INTEGER, colB INTEGER )",
  "INSERT INTO foo_bar VALUES (3, 4)",
  "SELECT * FROM foo_bar"
]

commands.each do |command|
  puts "Running command '#{command}'"
  response = client.request(command)
  puts "Response is '#{response}'"
end
