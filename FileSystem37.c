/*
Problem Statement:
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>
int main(int args, char *argv[]){

    DIR *source = NULL;
    DIR *dest = NULL;
    struct dirent *entry = NULL;
    char oldfile[50]={"\0"};
    char newfile[50]={"\0"}; 

    if(args!=3){
        printf("Insufficient Arguments\n");
        return -1;
    }

    source = opendir(argv[1]);
    if(source==NULL){
        printf("Error: Unable to open Directory\n");
        closedir(source);
        return -1;
    }

    while((entry = readdir(source))!=NULL){

        sprintf(oldfile,"%s/%s",argv[1],entry->d_name);
        sprintf(newfile,"%s/%s",argv[2],entry->d_name);
        rename(oldfile,newfile);
    }
    
    closedir(source);
    
    return 0;
}