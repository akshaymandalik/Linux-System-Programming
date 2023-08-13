#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<string.h>
#include<sys/stat.h>
/*
        Client for Named Pipe
*/

int main(){

    int fd = 0;
    char *path = "/tmp/mypipe";
    char buffer[100];


    printf("Client is Running...\n");
    fd = open(path,O_RDONLY);

    read(fd,buffer,15);


    unlink(path);

    printf("Data from pipe is:%s\n",buffer);

    return 0;
}

