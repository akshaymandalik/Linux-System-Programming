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

    fd = open(argv[1],O_RDONLY);
    if(fd != -1){
        printf("File is succeefully opened with fd %d",fd);
    }
    else{
        printf("Unable to open file\n");
    }

    close(fd);
    
    return 0;
}