#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){ 

    int ret = 0;
    ret = fork();

    if(ret == 0){
        
            execl("./Childprocess",NULL,NULL);
    }else{
        printf("Parent Process is Running with pid %d\n",getpid());
        printf("PID of Child Process is:%d\n",ret);
    }

    return 0;

}