#include<stdio.h>

#include<unistd.h>
#include<sys/resource.h>
int main(){

    int iRet = 0;
    iRet = nice(0);
    printf("Previous Priority of Process:%d",iRet);
    iRet = nice(-5);
    printf("Current Priority of Process:%d",iRet);
    return 0;
}