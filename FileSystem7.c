#include<stdio.h>
#include<fcntl.h>
int main(int args,char *argv[]){
	
	
	int fd = 0;
 	
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

	return 0;
}
