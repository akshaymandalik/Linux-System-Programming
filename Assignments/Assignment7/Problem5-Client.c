#include<stdio.h>
#include"problem5-SharedFile.h"

int main(int args, char *argv[]){

    int ret = 0;
    
    if(args !=2){
        printf("Error: Invalid Arguments\n");
        return -1;
    }

    ret = fileInfo(argv[1]);

    if(ret == -1){
        printf("Error: File Does not Exists");
        return -1;
    }

    return 0;
}