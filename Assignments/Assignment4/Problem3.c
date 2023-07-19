/*
Problem Statement:Write a program which accept two file names from user and check whether contents of that two files are equal are not.
Author Name: Akshay Mandalik
Last Modified: 19 July 2023
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#define MAXSIZE 1024
int main(int args, char * argv[]){

    char buffer1[MAXSIZE]={"\0"};
    char buffer2[MAXSIZE]={"\0"};
    int fd1 = 0;
    int fd2 = 0;
    struct stat sObj,sObj1;
    int ret = 0;

    if(args!=3){
        printf("Error: Invalid Arguments\n");
        return -1;
    }

    stat(argv[1],&sObj);
    stat(argv[2],&sObj1);
    
    if(sObj.st_size != sObj1.st_size){
        printf("Files are different\n");
        return -1;
    }

    fd1 = open(argv[1],O_RDONLY);
    if(fd1 == -1){
        printf("Error: Unable to open %s",argv[1]);
        return -1;
    }

    fd2 = open(argv[2],O_RDONLY);
    if(fd2 == -1){
        printf("Error: Unable to open %s",argv[2]);
        return -1;
    }
    
    while((ret = read(fd1,buffer1,MAXSIZE))!=0){

        read(fd2,buffer2,MAXSIZE);
        if(memcmp(buffer1,buffer2,ret)!=0){
            break;
        }
    }
    if(ret == 0){
        printf("Files are Identical\n");
    }
    else{
        printf("File are Different\n");
        return -1;
    }

    return 0;
}