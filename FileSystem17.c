#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main(int args, char *argv[]){
		
	struct stat sobj;
	int fd = 0;	
	if(args!=2){
		printf("Error: Insufficient Arguments\n");
		return -1;
	}	

	
	fd = open(argv[1],O_RDONLY);
	fstat(fd,&sobj);	

	printf("\nFile Name:%s",argv[1]);
	printf("\nFile Size:%d",sobj.st_size);
	printf("\nNumber of links:%d",sobj.st_nlink);
	printf("\nInode Number:%d",sobj.st_ino);
	printf("\nFile System No: %d",sobj.st_dev);
	printf("\nSize of Block:%d",sobj.st_blksize);
	printf("\nNumber of blocks:%d",sobj.st_blocks);
	
	return 0;
}
