
## What is this?

This directory provides a Ruby gem called `PotatoDB_client`.
It makes network calls to a local PotatoDB server instance, and allows for SQL queries.
Much of the code is written in C, with a little bit of Ruby to wrap up everything.

## How to build

At the moment, you can run these steps to build the project

```bash
$ cd ext/
$ make
compiling potatodb_client.c
linking shared-object potatodb_client/potatodb_client.bundle
```

Now open up an IRB session and attempt to load it:

```ruby
$ irb
2.6.0 :001 > require './potatodb_client'
 => true 
2.6.0 :002 > PotatoDB.version
 => "PotatoDB Client (0.1.0)" 
```

For the moment, we only have this one method: `PotatoDB#version`. The next steps is to
allow it to open a connection to a local server to perform queries!

## Future

* Add simple socket client.
  => It should connect to a port, send a string.
  => We should see that string on the server side.
  => If we do, success!
  
* Flesh out the Ruby gem itself:
  => https://tristanpenman.com/blog/posts/2018/08/29/writing-a-gem-with-native-extensions/

* Let's use Valgrind to check for any leaks:
  => http://blog.flavorjon.es/2009/06/easily-valgrind-gdb-your-ruby-c.html
  => https://github.com/jbarnette/hoe-debugging
