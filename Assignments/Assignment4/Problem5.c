/*
    Problem Statement: Write a program which accept file name and position from user and read 20 bytes from that position.
    Author Name:Akshay Mandalik
    Last Modified: 19 July 2023
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int args,char *argv[]){

    
    int sourcefd = 0;
    char buffer[20]={"\0"};
    int ret = 0;

    if(args!=3){
        printf("Error:Invalid Arguments\n");
        return -1;
    }

    sourcefd = open(argv[1],O_RDONLY);
    if(sourcefd == -1){
        printf("Error:Unable to open %s",argv[1]);
        return -1;
    }

    lseek(sourcefd,atoi(argv[2]),SEEK_CUR);
    ret = read(sourcefd,buffer,20);
    write(1,buffer,ret);


    return 0;
}