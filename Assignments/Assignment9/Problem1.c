#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){

    int iRet = 0;
    int status = 0;
    iRet = fork();
    if(iRet == 0){ // Child

        execl("./process1",NULL,NULL);
    }


    wait(&status);


    return 0;
}