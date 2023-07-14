#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(int args,char *argv[]){
	
	
	int fd = 0;
	char *buffer=NULL;
	int ret = 0;

	if(args!=3){
		printf("Invalid Number Of Arguments\n");
		return -1;
	}
	
	
	
	fd = open(argv[1],O_RDONLY);
	if(fd == -1){
		printf("Unable to open File\n");
		return -1;	
        }
	else{
	 
		printf("File Opened Successfully with FD:%d\n",fd);
	
        }
	
	buffer = (char *)malloc(sizeof(char) * atoi(argv[2]));
	
	ret = read(fd,buffer,atoi(argv[2]));
	if(ret == 0){
		printf("Unable to read data\n");
	}

	printf("\nData Of File:\n");
	write(1,buffer,ret);

	return 0;
}
