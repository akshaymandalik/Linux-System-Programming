#include<stdio.h>
#include<unistd.h>

int main(){

    int fd[2];
    int iRet = 0;
    char Buffer[512]={"\0"};
    char readBuffer[1024] = {"\0"};
    int childId = 0;

    pipe(fd);
    childId = fork();

    if(childId == 0){
        close(fd[0]);
        printf("Enter Some Data:");
        scanf(" %[^\n]s",Buffer);
        write(fd[1],Buffer,sizeof(Buffer));
    }
    else{
        close(fd[1]);
        iRet = read(fd[0],readBuffer,sizeof(Buffer));
        printf("Data from Child:%s\n",readBuffer);
    }


    return 0;
}