#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

/*
    Demonstration of MultiProcessing
*/
int main(){

    int iRet1 = 0;
    int iRet2 = 0;
    int pid1,pid2;
    int status1,status2;

    iRet1 = fork();
    if(iRet1 == 0){ 
        execl("./process1","NULL",NULL);
    }

    wait(&status1);

    iRet2 = fork();
    if(iRet2 == 0){ 
        execl("./process2","NULL",NULL);
    }

    wait(&status2);

    return 0;
}