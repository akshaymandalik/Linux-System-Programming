#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(){

    int iRet = 0;
    int status = 0;

    iRet = fork();
    if(iRet == 0){

        execl("./Problem1",NULL,NULL);
    }
    else{
        printf("Problem 2 is Running\n");
    }

    wait(&status);

    return 0;
}