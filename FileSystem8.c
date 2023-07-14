#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main(int args,char *argv[]){
	
	
	int fd = 0;
 	int Mode = 0;



	if(args!=3){
		printf("Invalid Number Of Arguments\n");
		return -1;
	}
	
	if(strcmp(argv[2],"Read")== 0){
		Mode = O_RDONLY;
	}
	else if(strcmp(argv[2],"Write")==0){
		Mode = O_WRONLY;
	}
	else{
			Mode= O_RDONLY;
	}
	
	fd = open(argv[1],Mode);
	if(fd == -1){
		printf("Unable to open File\n");
		return -1;	
        }
	else{
	 
		printf("File Opened Successfully with FD:%d\n",fd);
	
        }

	return 0;
}
