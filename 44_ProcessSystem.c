#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){ 

    int ret = 0;
    ret = fork();

    if(ret == 0){
        printf("Child Process is Running\n");
    }else{
        printf("Parent Process is Running\n");
    }

    return 0;

}