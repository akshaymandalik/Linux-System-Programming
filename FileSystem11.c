#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(int args,char *argv[]){
	
	
	int fd = 0;
	char Buffer[20]={"\0"};
	int ret = 0;

	printf("Usage: Name_Of_Executable Name Of File to Create.\n");

	if(args!=2){
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
	
	ret = read(fd,Buffer,10);
	if(ret == 0){
		printf("Unable to read data\n");
	}
	printf("%d",ret);
	printf("Data Of File:%s",Buffer);

	return 0;
}
