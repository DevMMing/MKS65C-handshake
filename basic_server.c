#include "pipe_networking.h"

void sighand(int sig){

  if (sig == SIGINT){
    remove("well_known_pipe");
    exit(0);
  }

}
char *  rot13(char * str){
  for(int i = 0; str[i]; i++){
    if( str[i] >= 'a' && str[i] < 'n')
      str[i] += 13;       
    else if( str[i] >= 'n' && str[i] <= 'z')
      str[i] -= 13;
  }
  return str;
}

int main() {
  signal(SIGINT,sighand);

  int to_client;
  int from_client;
<<<<<<< HEAD

  char * input = malloc(BUFFER_SIZE);
  char * output = malloc(BUFFER_SIZE);

  while(1){
    from_client = server_handshake( &to_client );
    printf("This server adds 13 to char (rot13)\n");
    while(read(from_client,input,BUFFER_SIZE)){
      input[strlen(input)] = '\0';
      printf("Client has sent: %s\n",input);
      output = rot13(input);
      printf("Client is getting [%s]\n",output);
      write(to_client,output,BUFFER_SIZE);

    }

  }
  return 0;
}
=======
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
>>>>>>> 5113ea9ce25b3205941f6b59f97b67dd830ef3ff
