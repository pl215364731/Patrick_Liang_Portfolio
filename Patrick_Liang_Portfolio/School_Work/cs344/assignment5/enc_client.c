#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>  // ssize_t
#include <sys/socket.h> // send(),recv()
#include <netdb.h>      // gethostbyname()

/**
* Client code
* 1. Create a socket and connect to the server specified in the command arugments.
* 2. Prompt the user for input and send that input as a message to the server.
* 3. Print the message received from the server and exit the program.
*/

// Error function used for reporting issues
void error(const char *msg) { 
  perror(msg); 
  exit(0); 
} 

// Set up the address struct
void setupAddressStruct(struct sockaddr_in* address, int portNumber, char* hostname){
 
  // Clear out the address struct
  memset((char*) address, '\0', sizeof(*address)); 

  // The address should be network capable
  address->sin_family = AF_INET;
  // Store the port number
  address->sin_port = htons(portNumber);

  // Get the DNS entry for this host name
  struct hostent* hostInfo = gethostbyname(hostname); 
  if (hostInfo == NULL) { 
    fprintf(stderr, "CLIENT: ERROR, no such host\n"); 
    exit(0); 
  }
  // Copy the first IP address from the DNS entry to sin_addr.s_addr
  memcpy((char*) &address->sin_addr.s_addr, 
        hostInfo->h_addr_list[0],
        hostInfo->h_length);
}

//Arguments: enc_client plain_text key port
int main(int argc, char *argv[]) {
  int socketFD, portNumber, charsWritten, charsRead;
  struct sockaddr_in serverAddress;
  char buffer[70000];
  // Check usage & args
  if (argc < 4) { 
    fprintf(stderr,"USAGE: %s hostname port\n", argv[0]); 
    exit(0); 
  }

  char key[70000];
  char plainText[70000];

  //open file with key
  FILE* keyFile = fopen(argv[2], "r");
  if(keyFile == NULL){
    fprintf(stderr,"Error: File '%s' does not exist\n", argv[2]); 
    exit(0); 
  }
  fgets(key, sizeof(key) - 1, keyFile);
  key[strcspn(key, "\n")] = '\0';
  fclose(keyFile);

  //open file with plaintext
  FILE* plainTextFile = fopen(argv[1], "r");
  if(plainTextFile == NULL){
    fprintf(stderr,"Error: File '%s' does not exist\n", argv[1]); 
    exit(0); 
  }
  fgets(plainText, sizeof(plainText) - 1, keyFile);
  plainText[strcspn(plainText, "\n")] = '\0';
  fclose(plainTextFile);

  //Check for error in key and text, check for their size
  if(strlen(key) < strlen(plainText)){
    fprintf(stderr,"Error: key '%s' is too short\n", argv[2]); 
    exit(1); 
  }
  for(int i = 0; i < strlen(plainText); i++){
    if(((int)plainText[i] < 65 || (int)plainText[i] > 90) && (int)plainText[i] != 32) {
      fprintf(stderr,"Error: Bad character in '%s'\n", argv[1]);
      exit(1); 
    }
  }

  // Create a socket
  socketFD = socket(AF_INET, SOCK_STREAM, 0); 
  if (socketFD < 0){
    error("CLIENT: ERROR opening socket");
  }

  // Set up the server address struct
  setupAddressStruct(&serverAddress, atoi(argv[3]), "localhost");

  // Connect to server
  if (connect(socketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
    error("CLIENT: ERROR connecting");
  }
  
  memset(buffer, '\0', sizeof(buffer));
  charsRead = recv(socketFD, buffer, sizeof(buffer) - 1, 0); 
  if (charsRead < 0){
    error("CLIENT: ERROR reading from socket");
  }
  if(strcmp(buffer, "enc_server")){
    printf("Error: could not connect enc_server on port %s\n", argv[3]);
    exit(1);
  }

  // Send key to server, only send enough key to encrypt the text
  charsWritten = send(socketFD, key, strlen(plainText), 0); 
  if (charsWritten < 0){
    error("CLIENT: ERROR writing to socket");
  }

  usleep(1000);
  // Send text to server
  charsWritten = send(socketFD, plainText, strlen(plainText), 0); 
  if (charsWritten < 0){
    error("CLIENT: ERROR writing to socket");
  }
  if (charsWritten < strlen(plainText)){
    printf("CLIENT: WARNING: Not all data written to socket!\n");
  }

  // Get return message from server
  // Clear out the buffer again for reuse
  memset(buffer, '\0', sizeof(buffer));
  // Read data from the socket, leaving \0 at end
  charsRead = recv(socketFD, buffer, sizeof(buffer) - 1, 0); 
  if (charsRead < 0){
    error("CLIENT: ERROR reading from socket");
  }
  printf("%s\n", buffer);

  // Close the socket
  close(socketFD); 
  return 0;
}