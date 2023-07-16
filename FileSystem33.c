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

    fd = open(argv[1],O_RDWR);
    if(fd != -1){
        printf("File is Existing\n");

    }
    else{

            fd = creat(argv[1],0777);
            if(fd !=-1){
                printf("New File gets Created\n");
            }
    }

    close(fd);
    
    return 0;
}