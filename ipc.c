#include "ipc.h"

#if 1
//int socket(int domain, int type, int protocol);
void socket_server(void){
	/*
	**	struct sockaddr_un {
	**	 sa_family_t sun_family;               // AF_UNIX
	**	 char        sun_path[108];            // pathname
	**	};
	*/
	struct sockaddr_un name;
	int serverfd=0, readfd=0;
	int ret=0;
	char buffer[BUFFER_SIZE]={0};

	/*
	 * In case the program exited inadvertently on the last run,
	 * remove the socket.
	 */
	unlink(SOCKET_NAME);


	/*
	**  AF_UNIX is used for local interprocess communication
	**	valid type in AF_UNIX socket as below:
	**	1) SOCK_STREAM for a stream-oriented socket;
	**	2) SOCK_DGRAM, for a datagram-oriented socket that preserves message boundaries
	**	3) SOCK_SEQPACKET, for a sequenced-packet socket that is connection-oriented, preserves message boundaries,
	**	   and delivers messages in the order that they were sent.
	*/
	serverfd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
	if(serverfd == -1){
		printf("Create server socket error.\n");
		goto stop;
	}else{
		printf("Create Server socket, fd=%d\n", serverfd);
	}

	memset(&name, 0, sizeof(struct sockaddr_un));
	/* Bind socket to socket name. */

	name.sun_family = AF_UNIX;
	strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path) - 1);

	ret = bind(serverfd, (const struct sockaddr *) &name,
		  sizeof(struct sockaddr_un));
	if (ret == -1) {
	   printf("server socket bind error\n");
	   goto stop;
	}

	/*
	* Prepare for accepting connections. The backlog size is set
	* to 20. So while one request is being processed other requests
	* can be waiting.
	*/

	ret = listen(serverfd, 20);
	if (ret == -1) {
	   printf("server socket listen error\n");
	   goto stop;
	}

	printf("####### server socket waiting client connect.....\n\n");

	/* Wait for incoming connection. */
	readfd=accept(serverfd, NULL, NULL);
	if(-1 == readfd){
		printf("accept error.\n");
		goto stop;
	}

	printf("####### server socket accept succcess and waiting receive data\n\n");
	ret = write(readfd, "Hi client, Notice: server will terminate when receive \"END\"", BUFFER_SIZE);

	if (ret == -1) {
		printf("write data error\n");
		goto stop;
	}

	/* TODO */
	/* we should implement receive client data loop here */
	for(;;){
		ret = read(readfd, buffer, BUFFER_SIZE);
		if(-1 == ret){
			printf("read data error.\n");
			goto stop;
		}

		printf("server receive: %s\n", buffer);

		if (!strncmp(buffer, "END", BUFFER_SIZE)) {
			printf("receive END, server terminate....\n");
			break;
		}
	}

stop:
	close(readfd);
        close(serverfd);

	/* Unlink the socket. */
	unlink(SOCKET_NAME);
	printf("####### finish server socket loop\n\n");
	return;
}

void socket_client(void){
	int clientfd=0;
	struct sockaddr_un addr;
	char buffer[BUFFER_SIZE]={0};
	int ret=0;

	/*
	**  AF_UNIX is used for local interprocess communication
	**	valid type in AF_UNIX socket as below:
	**	1) SOCK_STREAM for a stream-oriented socket;
	**	2) SOCK_DGRAM, for a datagram-oriented socket that preserves message boundaries
	**	3) SOCK_SEQPACKET, for a sequenced-packet socket that is connection-oriented, preserves message boundaries, 
	**	   and delivers messages in the order that they were sent.
	*/
	clientfd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
	if(clientfd == -1){
		printf("Create client socket error.\n");
		goto stop;
	}else{
		printf("Create client socket, fd=%d\n", clientfd);
	}

	memset(&addr, 0, sizeof(struct sockaddr_un));
	/* Bind socket to socket name. */

	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);

	ret = connect(clientfd, (const struct sockaddr *) &addr,
		  sizeof(struct sockaddr_un));
	if (ret == -1) {
	   printf("client socket bind error\n");
	   goto stop;
	}

	ret = read(clientfd, buffer, BUFFER_SIZE);
	if (ret == -1) {
		printf("read data error\n");
		goto stop;
	}

	printf("%s\n\n", buffer);

	for(;;){
		/* TODO */
		memset(buffer, 0, BUFFER_SIZE);
		printf("Enter the message:");
		gets(buffer);
		
		ret = write(clientfd, buffer, BUFFER_SIZE);
		if (ret == -1) {
			printf("write data error\n");
			goto stop;
		}
	}
stop:
	close(clientfd);
	return;
}
#endif
