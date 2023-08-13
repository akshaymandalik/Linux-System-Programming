#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<string.h>

int main(){

    int fd[2];
    int iRet = 0;
    char Arr[]="Mandalik Groups";
    char buffer[512];
    int status = 0;

    pipe(fd);

    iRet = fork();

    if(iRet == 0){
            
            printf("Child Process Scheduled for Reading from pipe\n");
            close(fd[0]);
            write(fd[1],Arr,strlen(Arr));
            exit(0);
    }
    else{

            printf("Parent Process Scheduled for Reading from pipe\n");
            
            close(fd[1]);
            read(fd[0],buffer,sizeof(buffer));
            printf("Data From pipe:%s\n",buffer);
    }

    wait(&status);

    return 0;
}

