#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Error function used for reporting issues
void error(const char *msg) {
  perror(msg);
  exit(1);
} 

void decrypt(char* buffer, char* key, char* text){
  // Here we assume that all the characters in key and text are correct
  for(int i = 0; i < strlen(text); i++){
    int value = (int)text[i] - 65;
    if(value < 0){
      value = 26; //This is the space character
    }
    int keyValue = (int)key[i] - 65;
    if(keyValue < 0){
      keyValue = 26; //This is the space character
    }
    value = (value - keyValue + 27) % 27;
    if(value == 26){
      buffer[i] = ' ';
    } else {
      buffer[i] = (char)(value + 65);
    }
  }
}

int listenSocket;

void* service(){
  while(1){
    struct sockaddr_in clientAddress;
    socklen_t sizeOfClientInfo = sizeof(clientAddress);
    int connectionSocket, charsRead;
    // Accept the connection request which creates a connection socket
    connectionSocket = accept(listenSocket, 
                (struct sockaddr *)&clientAddress, 
                &sizeOfClientInfo); 
    if (connectionSocket < 0){
      error("ERROR on accept");
    }

    printf("SERVER: Connected to client running at host %d port %d\n", 
                          ntohs(clientAddress.sin_addr.s_addr),
                          ntohs(clientAddress.sin_port));

    char* server = "dec_server";
    charsRead = send(connectionSocket, server, strlen(server), 0); 
    if (charsRead < 0){
      error("ERROR writing to socket");
    }
    
    // Get the message from the client and display it
    char key[69333];
    memset(key, '\0', 69333);
    // Read the client's message from the socket
    charsRead = recv(connectionSocket, key, 69332, 0); 
    if (charsRead < 0){
      error("ERROR reading from socket");
    }
    //printf("SERVER: KeyLength: \"%d\"\n", strlen(key));

    char text[69333];
    memset(text, '\0', 69333);
    charsRead = recv(connectionSocket, text, 69332, 0); 
    if (charsRead < 0){
      error("ERROR reading from socket");
    }
    //printf("SERVER: Text: \"%s\"\n", text);


    //do encrpyting here and then send it back
    char output[69333];
    decrypt(output, key, text);


    // Send a Success message back to the client
    charsRead = send(connectionSocket, output, strlen(output), 0); 
    if (charsRead < 0){
      error("ERROR writing to socket");
    }
    // Close the connection socket for this client
    close(connectionSocket); 
  }
  
}

// Set up the address struct for the server socket
void setupAddressStruct(struct sockaddr_in* address, int portNumber){
 
  // Clear out the address struct
  memset((char*) address, '\0', sizeof(*address)); 

  // The address should be network capable
  address->sin_family = AF_INET;
  // Store the port number
  address->sin_port = htons(portNumber);
  // Allow a client at any address to connect to this server
  address->sin_addr.s_addr = INADDR_ANY;
}

int main(int argc, char *argv[]){
  struct sockaddr_in serverAddress;
  

  // Check usage & args
  if (argc < 2) { 
    fprintf(stderr,"USAGE: %s port\n", argv[0]); 
    exit(1);
  } 
  
  // Create the socket that will listen for connections
  listenSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (listenSocket < 0) {
    error("ERROR opening socket");
  }

  // Set up the address struct for the server socket
  setupAddressStruct(&serverAddress, atoi(argv[1]));

  // Associate the socket to the port
  if (bind(listenSocket, 
          (struct sockaddr *)&serverAddress, 
          sizeof(serverAddress)) < 0){
    error("ERROR on binding");
  }

  // Start listening for connetions. Allow up to 5 connections to queue up
  listen(listenSocket, 5); 
  
  // Creating 5 threads to service 5 clients at the same time
  // This is the Pool of Threads approach
  pthread_t t1, t2, t3, t4, t5;
  pthread_create(&t1, NULL, service, NULL);
  pthread_create(&t2, NULL, service, NULL);
  pthread_create(&t3, NULL, service, NULL);
  pthread_create(&t4, NULL, service, NULL);
  pthread_create(&t5, NULL, service, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);
  pthread_join(t5, NULL);
  // Close the listening socket
  close(listenSocket); 
  return 0;
}
