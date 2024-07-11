#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define bufsize 1024

/*
 * TODO: this function doesn't work properly, curl continuosly
 *       prints an error message. Maybe it's because of the
 *       HTTP 0.9 protocol response, or something else?
 *
 * TODO: fix this function and make snprintf work properly
 * */

void *handle_client(void *arg){
  int client_fd = *((int *)arg);
  char *buffer = (char *)malloc(sizeof(char) * bufsize);

  // Receive request
  printf("[+] Waiting for request\n");
  // save request in buffer
  ssize_t received_bytes = recv(client_fd, buffer, bufsize, 0); 

  printf("[+] Request received:\n\n%s", buffer);
  // Create the header and the body 
  snprintf(buffer, 
           bufsize,
           "HTTP/1.1 200 OK\r\n"
           "Content-Type: text/html\r\n"
           "\r\n");

  char body[] = "<html><body><h1>Hello World!</h1></body></html>";
  
  // Concat
  int body_length = strlen(body);
  
  if (body_length >= bufsize) {
    fprintf(stderr, "Combined header and body too large for buffer\n");
    close(client_fd);
    return NULL;
  }

  int header_length = strlen(buffer);
  memcpy(buffer + header_length, body, body_length + 1);

  printf("[+] Response: patata");
  // Send response
  send(client_fd, buffer, strlen(buffer), 0);
  printf("[+] Response sent\n");
 
  free(buffer);
  close(client_fd);
  return NULL;
}

int main(){
  int server_fd;
  struct sockaddr_in server_address;

  /*
   * Create Socket
   */
  if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    perror("socket creation failed\n");
    exit(EXIT_FAILURE);
  }

  if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0){
    perror("setsockopt failed\n");
    exit(EXIT_FAILURE);
  }

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // Bind socket to address and listen to the port 
  if(bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0){
    perror("bind failed\n");
    exit(EXIT_FAILURE);
  }

  if(listen(server_fd, 20) < 0){
    perror("listen failed\n");
    exit(EXIT_FAILURE);
  }

  printf("[+] Server listening on port: %d\n", PORT);
  
  // Server loop for connection
  while(1){
    struct sockaddr_in client_address;
    socklen_t client_addrlen = sizeof(client_address);
    int *client_fd_ptr = malloc(sizeof(int));

    if((*client_fd_ptr = accept(server_fd, 
                          (struct sockaddr *)&client_address, 
                           &client_addrlen)) < 0){
      perror("accept failed\n");
      exit(EXIT_FAILURE);
      continue;
    } 
    
    // Check when new client is connected
    printf("[+] New Client Connection\n");
    printf("[+] Connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
  
    // Create new thread for client
    pthread_t client_thread;
    if(pthread_create(&client_thread, NULL, handle_client, (void *)client_fd_ptr) != 0){
      perror("pthread_create failed\n");
      exit(EXIT_FAILURE);
    }
    pthread_detach(client_thread);
  }

  close(server_fd);
  return 0;
}
