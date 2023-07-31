#include<unistd.h>
#include<sys/resource.h>
#include<stdio.h>
int main(){

    int iRet = 0;
    iRet = getpriority(PRIO_PROCESS,0);

    printf("Priority of Process is:%d\n",iRet);

    return 0;
}