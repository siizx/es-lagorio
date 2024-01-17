#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>

unsigned int s = 256;
char* buf;
char *buf2;

int main() {
	
	buf = (char*)malloc(s*sizeof(char));
	buf2 = (char*)malloc(s*sizeof(char));
	int fd[2];
	fgets(buf, s , stdin);
	pipe(fd);

	
	pid_t pid = fork();
	
	if(pid != 0){
		close(fd[0]);
		write(fd[1], buf, strlen(buf)+1);
		close(fd[1]);
		wait(NULL);
		
	}else{
		close(fd[1]);
		read(fd[0], buf2, s);
		printf("%s", buf2);
		close(fd[0]);
	}	
	
	free(buf);
	free(buf2);

	return 0;
}
