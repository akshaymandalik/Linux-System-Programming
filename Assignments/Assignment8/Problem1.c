#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){

    int iRet = 0;
    int status = 0;
    iRet = fork();
    if(iRet == 0){ // Child

        execl("childProcess",NULL,NULL);
    }
    else{  // Parent

            printf("Problem 1 is Running\n");

    }

    wait(&status);


    return 0;
}