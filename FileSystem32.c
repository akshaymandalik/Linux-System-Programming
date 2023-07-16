/*
Problem Statement:
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int args, char *argv[]){

    int fd = 0;
    if(args!=2){
        printf("Error: Invalid Arguments\n");
        return -1;
    }

    fd = creat(argv[1],0777);
    if(fd != -1){
        printf("File is succeefully created with fd %d",fd);
    }
    else{
        printf("Unable to create file\n");
    }

    close(fd);
    
    return 0;
}