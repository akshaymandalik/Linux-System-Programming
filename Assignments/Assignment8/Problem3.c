#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{

    int iRet = 0;

    iRet = fork();
    if(iRet == 0){
        execl("./Problem2",NULL,NULL);
    }
    else{
        printf("Problem 3 is Running\n");
    }

    return 0;
}