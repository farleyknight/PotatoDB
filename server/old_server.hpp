#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

const size_t buffer_length = 256;
#define PORT_NUMBER 7878

// Function designed for chat between client and server.
void server_func(int sockfd) {
  char buff[buffer_length];
  // int n;
  // infinite loop for chat
  for (;;) {
    bzero(buff, buffer_length);

    printf("Reading from socket into buffer\n");
    // read the message from client and copy it in buffer
    int read_result = read(sockfd, buff, sizeof(buff));
    if (read_result < 1) {
      printf("Got an error! %d\n", read_result);
      break;
    }
    // print buffer which contains the client contents
    printf("Reading from client: %s\t\n", buff);

    // TODO: Act on the data in `buff`

    // TODO: This should just be a static string for now?
    // copy server message in the buffer
    bzero(buff, buffer_length);
    strcpy(buff, "Response to your request!");

    // n = 0;
    // while ((buff[n++] = getchar()) != '\n');

    printf("Writing to client: %s\n", buff);
    // and send that buffer to client
    int write_result = write(sockfd, buff, sizeof(buff));
    // TODO: Handle possible errors via write_result
  }
}

// Driver function
int run_server() {
  int sockfd, connfd;
  socklen_t len;
  struct sockaddr_in servaddr, cli;

  // socket create and verification
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("socket creation failed...\n");
    exit(0);
  } else {
    printf("Socket successfully created..\n");
  }

  bzero(&servaddr, sizeof(servaddr));

  // assign IP, PORT
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT_NUMBER);

  // Binding newly created socket to given IP and verification
  if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
    printf("socket bind failed...\n");
    exit(0);
  } else {
    printf("Socket successfully binded..\n");
  }

  // Now server is ready to listen and verification
  if ((listen(sockfd, 5)) != 0) {
    printf("Listen failed...\n");
    exit(0);
  } else {
    printf("Server listening..\n");
  }

  len = sizeof(cli);

  for (;;) {
    // Accept the data packet from client and verification
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
    if (connfd < 0) {
      printf("server accept failed...\n");
      exit(0);
    } else {
      printf("server accept the client...\n");
    }

    // Function for chatting between client and server
    server_func(connfd);
  }

  // After chatting close the socket
  close(sockfd);

  return 0;
}
