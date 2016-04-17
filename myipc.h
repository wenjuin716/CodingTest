#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/un.h>		// sockaddr_un for AF_UNIX
#include <unistd.h>		// for close()
#include <sys/ipc.h>
#include <sys/shm.h>

#define SOCKET_NAME "tmp.socket"
#define BUFFER_SIZE 64

#define SERVER "[SERVER]"
#define CLIENT "[CLIENT]"

void socket_server(void);
void socket_client(void);

#if 1
void shareMem_Server(void);
void shareMem_Client(void);
#endif
