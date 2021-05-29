require './potatodb_client'
require 'sinatra'

################
# TODOs Table! #
################

class TodosTable
  def initialize(client)
    @client = client
  end

  def create_table
    table_schema = "CREATE TABLE IF NOT EXISTS todos ( id INTEGER PRIMARY KEY AUTOINCREMENT, title VARCHAR(32), done BOOLEAN, created_at TIMESTAMP, updated_at TIMESTAMP )"

    puts "SQL is: #{table_schema}"
    response = @client.request(table_schema)
    puts "Response is #{response}"

    # TODO!
    # Parse `response` here
  end

  def list_of_todos
    select_sql = "SELECT * FROM todos ORDER BY created_at"

    puts "SQL is: #{select_sql}"
    response = @client.request(select_sql)
    puts "Response is #{response}"

    if response == "No entries to send"
      return "No todos yet! Go ahead and make one!"
    else
      # TODO!
      # Parse `response` here
      return response
    end

  end

  def insert_todo(name)
    insert_sql = "INSERT INTO todos ( name, done, created_at, updated_at ) VALUES ('#{name}', false, NOW(), NOW() )"

    puts "SQL is: #{insert_sql}"
    response = @client.request(insert_sql)

    puts "Response is #{response}"

    # TODO!
    # Parse `response` here
  end

  def mark_done(id)
    update_sql = "UPDATE todos SET done = true WHERE id = #{id}"

    puts "SQL is: #{insert_sql}"
    response = @client.request(insert_sql)

    puts "Response is #{response}"

    # TODO!
    # Parse `response` here
  end

  def delete_todo(id)
    delete_sql = "DELETE FROM todods WHERE id = #{id}"

    puts "SQL is: #{delete_sql}"
    response = @client.request(delete_sql)
    puts "Response is #{response}"

    # TODO!
    # Parse `response` here
  end
end

#################
# The TODOs app #
#################

puts PotatoDB.version

client = PotatoDB::Client.new("localhost")
$todos = TodosTable.new(client)
$todos.create_table

get '/' do
  # NEXT: Create form for making a new todo
  $todos.list_of_todos
end

