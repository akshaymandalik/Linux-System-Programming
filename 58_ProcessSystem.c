#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){ 

    int ret = 0;
    int cpid = 0;
    int Exit_status = 0;
    ret = fork();

    if(ret == 0){
        
            execl("./Childprocess","NULL",NULL);
    }else{
        printf("Parent Process is Running with pid %d\n",getpid());
        cpid = wait(&Exit_status);
        printf("Child process terminated having PID %d with exit status %d",cpid,Exit_status);
    }

    return 0;

}