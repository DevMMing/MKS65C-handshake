#include "pipe_networking.h"

<<<<<<< HEAD
void sighand(int sig){

  if (sig == SIGINT){
    exit(0);
  }


=======
static void sighandler( int signum){
  if(signum == SIGINT){
    
  }
>>>>>>> 5113ea9ce25b3205941f6b59f97b67dd830ef3ff
}
int main() {

  signal(SIGINT,sighand);
  int to_server;
  int from_server;

<<<<<<< HEAD
  from_server = client_handshake( &to_server );
  char * input = malloc(BUFFER_SIZE);
  char * output = malloc(BUFFER_SIZE);
  while(1){
    printf("[client]-User Input: ");
    fgets(input,BUFFER_SIZE,stdin);
    strtok(input,"\n");
    write(to_server, input, BUFFER_SIZE);
    read(from_server, output, BUFFER_SIZE);
    printf("[client]-Server Output: %s\n\n", output);
  }
 return 0;
}
=======
  from_server = client_handshake( &to_server );	
  while(1){
  }
}
>>>>>>> 5113ea9ce25b3205941f6b59f97b67dd830ef3ff
