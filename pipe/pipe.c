#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>

char  buf[] = "yolo polo";
char buf2[256];

int main() {
	
	int fd[2];
	
	pipe(fd);
	// qui sopra, abbiamo creato fd[0] per la lettura e fd[1] per la scrittura.
	
	pid_t pid = fork();
	
	if(pid != 0){
		close(fd[0]);
		write(fd[1], buf, sizeof(buf));
		wait(NULL);
		
	}else{
		close(fd[1]);
		read(fd[0], buf2, sizeof(buf));
		printf("%s\n", buf2);
	}	
	


	return 0;
}
