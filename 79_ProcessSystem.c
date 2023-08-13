#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<string.h>
#include<sys/stat.h>
/*
        Server for Named Pipe
*/

int main(){

    int fd = 0;
    char *path = "/tmp/mypipe";

    fd = mkfifo(path,0666);
    if(fd == -1){
        printf("Error:Unable to create Named Pipe\n");
    }

    return 0;
}

