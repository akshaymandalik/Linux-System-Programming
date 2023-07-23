#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int no = 10;

void fun(){

    no++;
    printf("Runnig process PID:%d and value of no is %d\n",getpid(),no);
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