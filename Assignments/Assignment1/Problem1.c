/*
Problem Statement: Write a program which accept file name from user and open that file.
Author Name: Akshay Mandalik
Last Modified: Thursday,13 July 11:22 PM
*/

#include<stdio.h>
#include<fcntl.h>
int main(int args, char *argv[]){

    int fd = 0;

    if(args!= 2){
        printf("Error: Invalid Arguments!!\n");
        printf("Usage: Name_of_Executable[space]Name_of_to_open\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1){
        printf("Error: Unable to open specified file\n");
        return -1;
    }

    printf("%s opened successfully with fd: %d\n",argv[1],fd);

    return 0;   
}