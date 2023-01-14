// Use the command "make client" to compile this program.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "md5.h"
#include "wisdom.h"
#define LOADSIZE 512
int main(int argc, char **argv) {
    // Check 3 inputs before execution, otherwise exit.
  if (argc != 4)
   {
    printf("Usuage: wisdom server_ip_address user_name password\n");
    exit(0);
   }
    // To build a socket
     int sockfd;
     char ip_address[50];
     char user_name[MAX_USER_NAME_LENGTH];
     char password[50];

     strcpy(ip_address, argv[1]);
     strcpy(user_name, argv[2]);
     strcpy(password, argv[3]);

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if (sockfd == -1)
    {
     printf("Could not establish a socket\n");
     exit(1);
    }
    // server connection
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);
    serv_addr.sin_port = htons(SERVER_PORT);
    bzero(&(serv_addr.sin_zero), 8);

    int connect_status;
    connect_status = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (connect_status == -1)
    { 
     printf("Cannot connect to the server, please try later\n");
     exit(2);
    }
    // After all verification, start define variables
     char msg[MAX_MESSAGE_LENGTH];
     char challenge[200];

    // send(... user_name ...);
       send(sockfd, user_name, MAX_USER_NAME_LENGTH,0);
       printf("[SENT] %s\n", user_name);
    // recv(... challenge ...);
        recv(sockfd, challenge, 512, 0);
        printf("[RECV] %s\n", challenge);

    // input = challenge + user_name + password 
       char input_to_hash[MAX_MESSAGE_LENGTH];
       strcpy(input_to_hash, challenge);
       strcat(input_to_hash, user_name);
       strcat(input_to_hash, password);
       char hash[MD5_STRING_LENGTH];
       md5(input_to_hash, hash);
      
    // send... response ...
       send(sockfd, hash, MD5_STRING_LENGTH, 0);
       printf("[SENT] %s\n", hash);

    // recv proverbs
       char proverbs[512];
       recv(sockfd, proverbs,512, 0);
       printf("%s\n",proverbs);
close(sockfd);
}
