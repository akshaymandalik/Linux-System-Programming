#include<stdio.h>
#include<fcntl.h>
int main(int args,char *argv[]){
	
	char FName[20];
	int fd = 0;
 	
	printf("Enter File Name that you want to open:");
	scanf("%s",FName);

	fd = open(FName,O_RDONLY);
	if(fd == -1){
		printf("Unable to open File\n");
		return -1;	
        }
	else{
	 
		printf("File Opened Successfully with FD:%d\n",fd);
	
        }

	return 0;
}
