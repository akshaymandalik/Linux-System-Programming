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

    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char path[50]={"\0"}; 

    if(args!=3){
        printf("Insufficient Arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL){
        printf("Unable to open directory\n");
        return -1;
    }
    while((entry=readdir(dp))!=NULL){

        if(strcmp(argv[2],entry->d_name)==0){

            printf("File is Present in the directory\n");
            sprintf(path,"%s/%s",argv[1],argv[2]);
            remove(path);
            printf("File Deleted Successfully\n");
            break;
        }
    }

    if(entry == NULL){
        printf("There is no such file\n");
        return -1;
    }

    closedir(dp);
    
    return 0;
}