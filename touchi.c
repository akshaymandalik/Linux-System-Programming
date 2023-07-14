#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int args,char * argv[]){
	

	int fd = 0;
	
	if(args != 2){
	
		printf("Error: Insufficient Arguments\n");
		return -1;
	}	
	
	fd = creat(argv[1],0777);
	if(fd == -1){
		printf("Error:Unable to create your File\n");
		return -1;
	}

	return 0;
}
