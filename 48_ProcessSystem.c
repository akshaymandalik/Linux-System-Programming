#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void fun(){
    printf("Runnig process PID:%d\n",getpid());
}

int main(){ 

    
    int ret = 0;
    ret = fork();

    if(ret == 0){
        fun();
    }else{
        fun();
    }
     

    return 0;

}