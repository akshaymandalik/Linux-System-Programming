/*
Problem Statement: Search File in given folder.
Author Name: Akshay Mandalik
Last Modified: Sunday 9 July,06:27 PM
*/

// Adding necessary header files and micro-expansions.
      
#include<stdio.h> 
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#define TRUE 1
#define FALSE 2
#define ERROR1 "Insufficient Arguments\n"
#define ERROR2 "Unable to find the directory\n"
#define SUCCESS1 "File Found !!\n"
#define FAILURE1 "Sorry, File not found!!\n"

int main(int argc,char* argv[]){
	
		
	DIR *dir = NULL;
	int flag = FALSE;
	
	
	struct dirent *entry = NULL;

	if(argc!=3){
		write(1,ERROR1,sizeof(ERROR1));
		return -1;
	}
	
	dir = opendir(argv[1]);
	
	if(dir == NULL){
		write(1,ERROR2,sizeof(ERROR2));
		return -1;
	}

	while((entry = readdir(dir))!=NULL){
		
		if(strcmp(argv[2],entry->d_name)==0){
			
			flag = TRUE;
			return 0;
		}
	}
	
	if(flag == TRUE){
		write(1,SUCCESS1,sizeof(SUCCESS1));
	}
	else{
		write(1,FAILURE1,sizeof(FAILURE1));
	}
	
	return 0;
}
