#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;
  char msg[BUFSIZ];
  char str[BUFSIZ];
  from_client = server_handshake( &to_client );
  mkfifo(from_client);
  while(1){
	printf("Input message to server: ");
   	scanf("%s", str);
	if(!strcmp(str,"exit")){
	printf("closing server");
	break;
	}
	read(to_client,msg,sizeof(msg));
	
	write();
  }
}
