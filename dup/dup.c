#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>




int main(){
	
	const int s = 256;
	int fd = open("pippo.txt", O_CREAT | O_TRUNC | O_WRONLY);

	//char test[256] = "pippoide32";
	char *test = (char*)malloc(s*sizeof(char));
	char *buf = (char*)malloc(s*sizeof(char));
	int input_backup = dup(fileno(stdin));
	if(input_backup < 0){
		perror("dup input");
		exit(EXIT_FAILURE);
	}
	int output_backup = dup(fileno(stdout));
	if(input_backup < 0){
		perror("dup output");
		exit(EXIT_FAILURE);
	}
	printf("Enter a string: ");
	scanf("%s", test);
	printf("\n");
	
	dup2(fd,fileno(stdout));
	fflush(stdout);
	fprintf(stdout, "%s\n", test); // stampa test nel file
	lseek(fd, 0, SEEK_SET);
	
	dup2(input_backup, fileno(stdin));
	dup2(output_backup, fileno(stdout));
	read(fd, buf, strlen(buf));
	close(input_backup);
	close(output_backup);
	close(fd);
	
	printf("cat pippo.txt: %s\n", buf);

	free(test);
	free(buf);
	return 0;
}
