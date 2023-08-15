#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#define MAXSIZE 512

int main(){

    int fd = 0;
    char buffer[MAXSIZE];
    char *path = "/tmp/mypipe";

    printf("Client is Running...\n");
    fd = open(path,O_RDONLY);

    read(fd,buffer,sizeof(buffer));

    unlink(path);

    printf("Message from Server:%s",buffer);

    return 0;
}