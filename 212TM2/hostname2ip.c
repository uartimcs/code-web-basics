#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char* argv[])
{

struct hostent *server_name;
struct sockaddr_in server_info;

if ((server_name = gethostbyname(argv[1]))== NULL)
{
perror("gethostbyname error");
exit;
}

server_info.sin_addr = *((struct in_addr *)server_name->h_addr);
printf(" IP=%s \n", inet_ntoa(server_info.sin_addr));

return 0;
}

