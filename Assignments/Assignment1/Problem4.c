/*
Problem Statement: Write a program which accept file name from user and print all information about that file.
Author Name: Akshay Mandalik
Last Modified:15 July 4:59 PM
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/stat.h>

int main(int args,char *argv[]){

    int isExists = -1;
    struct stat sObj;

    if(args!=2){
        printf("Error: Invalid Arguments!!\n");
        printf("Usage:Name_of_Executable[space]Name_of_file");
        return -1;
    }

    isExists = access(argv[1],F_OK);
    if(isExists == 0 ){

        stat(argv[1],&sObj);
        

    }else if(errno == ENOENT){
        printf("File Does not exists!!\n");
        return -1;
    }
    printf("File Name:%s\n",argv[1]);
    printf("File INode:%d\n",sObj.st_ino);
    printf("File Size:%d\n",sObj.st_size);
    printf("File Block Size :%d\n",sObj.st_blksize);
    printf("File Mode:%d\n",sObj.st_mode);
    


    return 0;
}