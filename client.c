#include "pipe_networking.h"

static void sighandler( int signum){
  if(signum == SIGINT){
    
  }
}
int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );	
  while(1){
  }
}
