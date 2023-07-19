/*
Problem Statement: Write program which accept directory name from user and delete all empty files from that directory.
Author Name: Akshay Mandalik
Last Modified: 19 July 2023
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int args, char * argv[]){

    DIR *dir = NULL;
    struct dirent *entry = NULL;
    struct stat sObj;
    char path[50]={"\0"};

    if(args!=2){
        printf("Error: Invalid Arguments\n");
        return -1;
    }

    dir = opendir(argv[1]);
    if(dir == NULL ){
        printf("Error: Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dir))!=NULL){

        sprintf(path,"%s/%s",argv[1],entry->d_name);
        stat(path,&sObj);
        if(S_ISREG(sObj.st_mode)){

             if(sObj.st_size == 0){
                 remove(path);
             }
        }
    }


    closedir(dir);
    return 0;
}
