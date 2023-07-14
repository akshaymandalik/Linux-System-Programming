/*
Problem statement: Write a program which accept file name and mode from user and then open that file in specified mode.
Author Name: Akshay Mandalik
Last Modified: Thursday 13 July,11:44 PM
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main(int args,char *argv[]){

    int fd = 0;
    int Mode = 0;

    if(args!=3){
        printf("Error: Invalid Arguments\n");
        printf("Usage: Name_of_executable[space]Name_of_file[space]Mode_to_open_file\n");
        return -1;
    }

    if(strcmp(argv[2],"Read")==0){

        Mode = O_RDONLY;

    }else if(strcmp(argv[2],"Write")==0){

        Mode = O_WRONLY;
    }
    else{
        Mode = O_RDONLY;
    }

    fd = open(argv[1],Mode);
    if(fd == -1){
        printf("Error:Unable to open File\n");
        return -1;
    }
    else{
        printf("File opened successfully with fd %d",fd);
    }

    return 0;
}