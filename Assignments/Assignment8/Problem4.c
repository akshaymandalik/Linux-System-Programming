#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){

    int iRet = 0,iRet1 = 0;
    int status = 0;
    iRet = fork();
    if(iRet == 0){
        execl("./Problem2",NULL,NULL);
    }
    else{
        printf("Problem 4 Running\n");
    }

    iRet1 = fork();
    if(iRet1 == 0){
        execl("./Problem1",NULL,NULL);
    }
    else{
        printf("Problem 4 Running\n");
    }

    waitpid(iRet,NULL,0);
    waitpid(iRet1,NULL,0);

    return 0;
}