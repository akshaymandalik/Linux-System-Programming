/*
Problem Statement:
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
int main(int args, char *argv[]){

    DIR *dp = NULL;
    struct dirent *entry = NULL;

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