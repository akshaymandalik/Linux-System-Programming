#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
int main(int args, char *argv[]){
		
	DIR *dp = NULL;
	
	struct dirent *entry = NULL;
		
	if(args !=2){
		 printf("Insufficient Arguments\n");
		return -1;
	}
	dp = opendir(argv[1]);
	
	if(dp == NULL){
		printf("Unable to open directory\n");
		return -1;
	}
	
	printf("Entries from directory file are:\n");
	printf("File Name: \tInode Number");
	while((entry = readdir(dp))!= NULL){
	
		printf("%20s: %d \n",entry->d_name,entry->d_ino);
	}
	
	closedir(dp);
	return 0;
}
