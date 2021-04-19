#include <ruby.h>
#include <sys/socket.h>

#include <netdb.h>
#include <netinet/in.h>

#include "extconf.h"

#define PORT_NUMBER 7878

VALUE mPotatoDB, cPotatoDBClient;

typedef struct {
  int sockfd;
} potatodb_client_t;

static void potatodb_client_free(void *p) {
  xfree(p);
}

static VALUE potatodb_client_alloc(VALUE klass) {
  potatodb_client_t *client;
  client = ALLOC(potatodb_client_t);

  return Data_Wrap_Struct(cPotatoDBClient, 0, potatodb_client_free, client);
}


// https://www.tutorialspoint.com/unix_sockets/socket_client_example.htm
static VALUE potatodb_client_init(VALUE self, VALUE hostname) {
  Check_Type(hostname, T_STRING);

  int sockfd;

  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Create the socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    rb_raise(rb_eRuntimeError, "ERROR: Could not create socket!");
    return self;
  }

  char *hostname_c_str = StringValueCStr(hostname);
  // TODO: Check if the variable `hostname` needs to be released?
  // Might be a memory leak here!
  server = gethostbyname(hostname_c_str);
  if (server == NULL) {
    rb_raise(rb_eRuntimeError, "ERROR: Could not resolve host!");
    return self;
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;

  // After connecting to server, copy server info
  bcopy((char *)server->h_addr,
        (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);
  serv_addr.sin_port = htons(PORT_NUMBER);

  // Now connect to the server
  if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    rb_raise(rb_eRuntimeError, "ERROR: Could not connect to host!");
    return self;
  }

  // After we've connected, we can save the `sockfd` and use it in other methods
  potatodb_client_t *client;
  Data_Get_Struct(self, potatodb_client_t, client);
  client->sockfd = sockfd;

  return self;
}

const size_t buffer_length = 256;

static VALUE potatodb_client_request(VALUE self, VALUE payload) {
  potatodb_client_t *client;
  Data_Get_Struct(self, potatodb_client_t, client);
  int sockfd = client->sockfd;

  char buffer[buffer_length];
  bzero(buffer, buffer_length);

  // TODO: Copy data into buffer
  char *data_c_str = StringValueCStr(payload);
  strcpy(buffer, data_c_str);

  // Send message to the server
  long write_error_code = write(sockfd, buffer, strlen(buffer));

  if (write_error_code < 0) {
    rb_raise(rb_eRuntimeError, "ERROR: Could not write to socket!");
    return Qnil;
  }

  // Now read server response
  bzero(buffer, buffer_length);
  long read_error_code = read(sockfd, buffer, buffer_length);

  if (read_error_code < 0) {
    rb_raise(rb_eRuntimeError, "ERROR: Could not read from socket!");
    return Qnil;
  }

  // TODO: Figure out if we have a memory leak here!
  VALUE response = rb_str_new(buffer, strlen(buffer));

  return response;
}

static VALUE get_version(VALUE _self) {
  char version[] = "PotatoDB Client (0.1.0)";
  VALUE result = rb_str_new(version, strlen(version));
  return result;
}

void Init_potatodb_client() {
  mPotatoDB = rb_define_module("PotatoDB");
  rb_define_module_function(mPotatoDB, "version", get_version, 0);

  cPotatoDBClient = rb_define_class_under(mPotatoDB, "Client", rb_cObject);
  rb_define_alloc_func(cPotatoDBClient, potatodb_client_alloc);

  rb_define_method(cPotatoDBClient, "initialize", potatodb_client_init, 1);
  rb_define_method(cPotatoDBClient, "request", potatodb_client_request, 1);
}
