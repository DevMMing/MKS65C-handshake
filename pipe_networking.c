#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
  int client_to_server;
   char *myfifo = "/tmp/client_to_server_fifo";

   int server_to_client;
   char *myfifo2 = "/tmp/server_to_client_fifo";

   char buf[BUFSIZ];

   /* create the FIFO (named pipe) */
   mkfifo(myfifo, 0777);
   mkfifo(myfifo2, 0777);

   /* open, read, and display the message from the FIFO */
   client_to_server = open(myfifo, O_RDONLY);
   server_to_client = open(myfifo2, O_WRONLY);

   printf("Server ON.\n");

   while (1)
   {
      read(client_to_server, buf, BUFSIZ);

      if (strcmp("exit",buf)==0)
      {
         printf("Server OFF.\n");
         break;
      }

      else if (strcmp("",buf)!=0)
      {
         printf("Received: %s\n", buf);
         printf("Sending back...\n");
         write(server_to_client,buf,BUFSIZ);
      }

      /* clean buf from any data */
      memset(buf, 0, sizeof(buf));
   }

   close(client_to_server);
   close(server_to_client);

   remove(myfifo);
   remove(myfifo2);
   *to_client=server_to_client;
   return client_to_server;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
	   int client_to_server;
   char *myfifo = "/tmp/client_to_server_fifo";

   int server_to_client;
   char *myfifo2 = "/tmp/server_to_client_fifo";

   char str[BUFSIZ];
   printf("Input message to server: ");
   scanf("%s", str);


   /* write str to the FIFO */
   client_to_server = open(myfifo, O_WRONLY);
   server_to_client = open(myfifo2, O_RDONLY);
   write(client_to_server, str, sizeof(str));
   read(server_to_client,str,sizeof(str));
   printf("...received from the server: %s\n",str);
   close(client_to_server);
   close(server_to_client);

	*to_server=client_to_server;
   return server_to_client;
	}
