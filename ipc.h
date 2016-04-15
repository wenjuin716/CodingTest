#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/un.h>		// sockaddr_un for AF_UNIX
#include <unistd.h>		// for close()

#define SOCKET_NAME "tmp.socket"
#define BUFFER_SIZE 64

void socket_server(void);
void socket_client(void);
