#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#define BUFSIZE 1024
int main(){

	int iRet = 0;
	int fd[2];
	int childId = 0;
	char buffer[] = "Akshay Mandalik";
	char readBuffer[BUFSIZE];

	pipe(fd);

	childId = fork();
	if(childId == 0){
		
		close(fd[0]);
		printf("Child Process Initiates..\n");
		write(fd[1],buffer,sizeof(buffer));
	}
	else{
		close(fd[1]);
		printf("Parent Accessing Data..\n");
		iRet = read(fd[0],readBuffer,sizeof(readBuffer));
		printf("The Data Pass from child is: %s\n",readBuffer);
	}

	return 0;

}
