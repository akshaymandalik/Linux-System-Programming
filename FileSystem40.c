/*
Problem Statement:
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int args, char *argv[]){

    int fd = 0;
    int ret = 0;
    char buffer[20]={"\0"};

    if(args!=3){
        printf("Insufficient Arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1){
        printf("Error: Unable to open\n");
        return -1;
    }
    
    lseek(fd,atoi(argv[2]),0);
    ret = read(fd,buffer,20);
    printf("Data from file is:\n");
    write(1,buffer,ret);    
    return 0;
}