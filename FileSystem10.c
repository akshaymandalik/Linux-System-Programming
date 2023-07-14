#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main(int args,char *argv[]){
	
	
	int fd = 0;

	printf("Usage: Name_Of_Executable Name Of File to Create.\n");

	if(args!=2){
		printf("Invalid Number Of Arguments\n");
		return -1;
	}
	
	
	fd = creat(argv[1],0777);
	if(fd == -1){
		printf("Unable to open File\n");
		return -1;	
        }
	else{
	 
		printf("File Opened Successfully with FD:%d\n",fd);
	
        }

	return 0;
}
