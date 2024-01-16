#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	
	int wstatus;
	pid_t pid = fork();
	
	if(pid < 0) {
		perror("fallita la fork");
		return -1;
	}
	
	
	if(pid == 0){
		pid_t thispid = getpid();
		printf("Sono il figlio, con pid #%d\n", thispid);
	}
	
	if(pid > 0){
		pid_t thispid = getpid();
		printf("Sono il padre con pid #%d\n", thispid);
		wait(&wstatus);
	}


	return 0;
}
