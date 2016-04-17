#include "myipc.h"

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
		printf("%sCreate socket error.\n", SERVER);
		goto stop;
	}else{
		printf("%sCreate socket, fd=%d\n", SERVER, serverfd);
	}

	memset(&name, 0, sizeof(struct sockaddr_un));
	/* Bind socket to socket name. */

	name.sun_family = AF_UNIX;
	strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path) - 1);

	ret = bind(serverfd, (const struct sockaddr *) &name,
		  sizeof(struct sockaddr_un));
	if (ret == -1) {
	   printf("%ssocket bind error\n", SERVER);
	   goto stop;
	}

	/*
	* Prepare for accepting connections. The backlog size is set
	* to 20. So while one request is being processed other requests
	* can be waiting.
	*/

	ret = listen(serverfd, 20);
	if (ret == -1) {
	   printf("%ssocket listen error\n", SERVER);
	   goto stop;
	}

	printf("####### %ssocket waiting client connect.....\n\n", SERVER);

	/* Wait for incoming connection. */
	readfd=accept(serverfd, NULL, NULL);
	if(-1 == readfd){
		printf("%saccept error.\n", SERVER);
		goto stop;
	}

	printf("####### %ssocket accept succcess and waiting receive data\n\n", SERVER);
	ret = write(readfd, "Hi client, Notice: server will terminate when receive \"END\"", BUFFER_SIZE);

	if (ret == -1) {
		printf("%swrite data error\n", SERVER);
		goto stop;
	}

	/* TODO */
	/* we should implement receive client data loop here */
	for(;;){
		ret = read(readfd, buffer, BUFFER_SIZE);
		if(-1 == ret){
			printf("%sread data error.\n", SERVER);
			goto stop;
		}

		printf("%sreceive: %s\n", SERVER, buffer);

		if (!strncmp(buffer, "END", BUFFER_SIZE)) {
			printf("%sreceive END, server terminate....\n", SERVER);
			break;
		}
	}

stop:
	close(readfd);
        close(serverfd);

	/* Unlink the socket. */
	unlink(SOCKET_NAME);
	printf("####### %sfinish socket loop\n\n", SERVER);
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
		printf("%sCreate socket error.\n", CLIENT);
		goto stop;
	}else{
		printf("%sCreate socket, fd=%d\n", CLIENT, clientfd);
	}

	memset(&addr, 0, sizeof(struct sockaddr_un));
	/* Bind socket to socket name. */

	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);

	ret = connect(clientfd, (const struct sockaddr *) &addr,
		  sizeof(struct sockaddr_un));
	if (ret == -1) {
	   printf("%ssocket bind error\n", CLIENT);
	   goto stop;
	}

	ret = read(clientfd, buffer, BUFFER_SIZE);
	if (ret == -1) {
		printf("%sread data error\n", CLIENT);
		goto stop;
	}

	printf("%s\n\n", buffer);

	for(;;){
		/* TODO */
		memset(buffer, 0, BUFFER_SIZE);
		printf("%sEnter the message:", CLIENT);
		gets(buffer);
		
		ret = write(clientfd, buffer, BUFFER_SIZE);
		if (ret == -1) {
			printf("%swrite data error\n", CLIENT);
			goto stop;
		}
	}
stop:
	close(clientfd);
	return;
}
#endif

#if 1
key_t key = 9999;
#define SHMSZ 27
char *server_status[3]={
	{"[SERVER]Waiting Client.\0"},
	{"[SERVER]Got your message.\0"},
	{"[SERVER]Finish daemon.\0"}};
char *client_status[3]={
        {"[CLIENT]This is Client.\0"},
        {"[CLIENT]Finish daemon.\0"},
	{"*\0"}};

void shareMem_Server(void){
	int shmid;
	int index=0;
	char *shm=NULL;
	
	/*
	 * Create the segment.
	 */
	if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
		printf("%sshmget error.\n", SERVER);
		return;
	}

	/*
	 * Now we attach the segment to our data space.
	 */
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		printf("%sshmat error, it can not attach SHM.\n", SERVER);
		return;
	}	


	/* init sHM */
	memset(shm, 0, SHMSZ);

	/*
	 * Now put some things into the memory for the
	 * other process to read.
	 */
	strncpy(shm, server_status[index], strlen(server_status[index]));
	printf("%swrite SHM:%s\n", SERVER, shm);
	
	/*
	 * Finally, we wait until the other process 
	 * changes the first character of our memory
	 * to '#', indicating that it has read what 
	 * we put there.
	 */
	while (*shm != '*'){
		if(strcmp(shm, client_status[index]) == 0){
			printf("%sRead SHM:%s\n", SERVER, shm);
			index++;

			/* init sHM */
			memset(shm, 0, SHMSZ);

			strncpy(shm, server_status[index], strlen(server_status[index]));
			printf("%swrite SHM:%s\n", SERVER, shm);
		}
		sleep(3);
	}

	return;
}

void shareMem_Client(void){
	int shmid;
	int index=0;
	char *shm=NULL;

	/*
	 * Locate the segment.
	 */
	if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
		printf("%sshmget error.\n", CLIENT);
		return;
	}

	/*
	 * Now we attach the segment to our data space.
	 */
	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		printf("%sshmat error\n", CLIENT);
		return;
	}

        /*
         * Finally, we wait until the other process 
         * changes the first character of our memory
         * to '*', indicating that it has read what 
         * we put there.
         */
        while (*shm != '*'){
                if(strcmp(shm, server_status[index]) == 0){
                        printf("%sRead SHM:%s\n", CLIENT, shm);

			/* init sHM */
			memset(shm, 0, SHMSZ);

                        strncpy(shm, client_status[index], strlen(client_status[index]));
                        printf("%swrite SHM:%s\n", CLIENT, shm);
			index++;
                }
                sleep(3);
        }

	return;
}
#endif
