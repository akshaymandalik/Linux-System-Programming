#include<unistd.h>
#include<sys/resource.h>
#include<stdio.h>
int main(){

    int iRet = 0;
    iRet = nice(0);

    printf("Current Priority of Process is:%d\n",iRet);

    iRet = nice(10);

    printf("Current Priority of Process is:%d\n",iRet);

    return 0;
}