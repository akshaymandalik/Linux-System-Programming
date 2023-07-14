#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#define BLOCKSIZE 1024
int main(int args,char *argv[]){
	
	
	int fd = 0;
	int ret = 0;
	char buffer[BLOCKSIZE];
	if(args!=2){
		printf("Invalid Number Of Arguments\n");
		return -1;
	}
	
	
	
	fd = open(argv[1],O_RDONLY);
	if(fd == -1){
		printf("Unable to open File\n");
		return -1;	
        }
		
	while((ret = read(fd,buffer,sizeof(buffer)))!= 0){
		write(1,buffer,ret);
	}

	close(fd);


	return 0;
}
