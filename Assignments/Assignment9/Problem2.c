#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(){

    int iRet = 0,iRet1 = 0,status = 0;
    iRet = fork();
    if(iRet == 0){
        execl("./process2",NULL,NULL);
    }

    wait(&status);

   
    iRet1 = fork();
    if(iRet1 == 0){
            execl("./process3",NULL,NULL);
    }

    wait(&status);

    

    return 0;
}