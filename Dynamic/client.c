#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dlfcn.h>
int main(){
    void *ptr = NULL;
    void(*fptr)();

    ptr = dlopen("library.so",RTLD_LAZY);
    if(ptr == NULL){
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"Display");
    if(fptr == NULL){
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr();
    return 0;
}

/*gcc client.c -rdynamic -o myExe

*/