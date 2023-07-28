#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dlfcn.h>
#include "Problem2-SharedFile.h"

int main(int args, char *argv[]){

    void *ptr = NULL;
    int (*fptr)(char *);
    int ret = 0;


    if(args != 3){
        printf("Error: Invalid Arguments\n");
        printf("Usage: Name_of_Executable[space]Name_of_file1[space]Name_of_file2");
        return -1;
    }

    ptr = dlopen("sharedLibrary.so",RTLD_LAZY);
    if(ptr == NULL){
        printf("Error: Unable to load Library\n");
        return -1;
    }

    fptr = dlsym(ptr,"CompareContent");
    if(fptr == NULL){
        printf("Error: Unable to load the address of function\n");
        return -1;
    }

    ret = fptr(argv);
    if(ret == -1){
        printf("Result: Files are Different\n");
        return -1;
    }

    printf("Result: Files are Identical\n");

    return 0;
}

