#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#define MAXSIZE 512

int main(){

    int fd = 0; 
    char *path = "/tmp/mypipe";
    char Message[MAXSIZE];

    fd = mkfifo(path,0666);
    if(fd == -1){
        printf("Error: Failed to create Pipe\n");
        return -1;
    }

    printf("Server is Running...\n");

    fd = open(path,O_WRONLY);

    printf("Enter Message:");

    scanf(" %[^\n]s",Message);

    write(fd,Message,sizeof(Message));

    close(fd);

    unlink(path);

    printf("Data fetched..\n");


    return 0;
}