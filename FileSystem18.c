#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main(int args, char *argv[]){
		
	struct stat sobj;
	
	if(args!=2){
		printf("Error: Insufficient Arguments\n");
		return -1;
	}	

	stat(argv[1],&sobj);
	
	if(S_ISREG(sobj.st_mode)){
		printf("Its a regular File\n");
	}
	if(S_ISDIR(sobj.st_mode)){
		printf("Its a directory\n");
	}
	if(S_ISLNK(sobj.st_mode)){
		
		printf("Its a Link\n");
	}
	
	return 0;
}
