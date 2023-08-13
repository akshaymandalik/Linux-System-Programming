
/*
Linux Programming Interface:
Chapter 2, 2.7, Page No,34
*/

#include<stdio.h>
#include<unistd.h>
#define EXIT_SUCCESS 0

extern char ** environ;

int main(){

    int iCnt = 0;
    while(environ[iCnt] != NULL){
        printf("[%d]%s\n",iCnt+1,environ[iCnt]);
        iCnt++;
    }

    printf("Jay Ganesh\n");
    _exit(EXIT_SUCCESS);
}