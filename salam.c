#include <stdio.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <string.h>



int main(){

  int clientSocket, newSocket;

  char buffer[1024];

  struct sockaddr_in serverAddr;

  struct sockaddr_storage serverStorage;

  socklen_t addr_size;



  /*---- Create the socket. The three arguments are: ----*/

  /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in 
this case) */

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);

  

  /*---- Configure settings of the server address struct ----*/

  /* Address family = Internet */

  serverAddr.sin_family = AF_INET;

  /* Set port number, using htons function to use proper byte order */

  serverAddr.sin_port = htons(8888);

  /* Set IP address to localhost */

  serverAddr.sin_addr.s_addr = inet_addr("192.168.74.129");

  /* Set all bits of the padding field to 0 */

  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  



  /*---- Bind the address struct to the socket ----*/

  bind(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
  if(listen(clientSocket,5)==0)
    printf("Listening\n");
  else
    printf("Error\n");

  addr_size = sizeof serverStorage;
  newSocket = accept(clientSocket,(struct sockaddr *) &serverStorage, 
  &addr_size);
  
  puts ("Connection Established");
  recv (newSocket, buffer, 50, 0);
  char f[]="Assalammualaikum";
  char g[50];
  strcpy(g, buffer);

  if(strcmp(g, f)==0)
  {
    strcpy(buffer, "Waalaikumsalam");
  }
  else
  {
    strcpy(buffer,"Are you Muslim?\n");
  }
   
  send(newSocket, buffer, 50,0);

return 0;
}
# netsprog
