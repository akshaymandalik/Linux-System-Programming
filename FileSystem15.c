#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define BLOCKSIZE 1024
int main(int args,char * argv[]){

	int ret = 0;
	char buffer[BLOCKSIZE]={"\0"};
	int fdSource = 0;
	int fdDest = 0;
		
	if(args != 3){
		printf("Insufficient Arguments\n");
	}	

	fdSource = open(argv[1],O_RDONLY);
	if(fdSource == -1){
		printf("Unable to open source file\n");
		return -1;
	}
	
	fdDest = creat(argv[2],0777);
	if(fdDest == -1){
		printf("Unable to create destination file\n");
		close(fdSource);
		return -1;
	}
	
	while((ret = read(fdSource,buffer,sizeof(buffer)))!=0){
		
		write(fdDest,buffer,ret);
		memset(buffer,0,sizeof(buffer));
	}
	
	close(fdSource);
	close(fdDest);

	return 0;
}
