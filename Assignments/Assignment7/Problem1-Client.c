#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dlfcn.h>
int main(){

    void * ptr = NULL;
    void (*fptr)();
    int choice = 0;
    
    ptr = dlopen("sharedLibrary.so",RTLD_LAZY);
    if(ptr == NULL){
        printf("Unable to load library\n");
        return -1;
    }

    printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
    printf("Enter your Choice:");
    scanf("%d",&choice);
    switch(choice){

        case 1: fptr = dlsym(ptr,"addition");
                    if(fptr == NULL){
                         printf("Unable to load the address of function\n");
                         return -1;
                    }
                break; 
        case 2: fptr = dlsym(ptr,"subtraction");
                    if(fptr == NULL){
                         printf("Unable to load the address of function\n");
                         return -1;
                    }
                break;        
        case 3: fptr = dlsym(ptr,"multiplication");
                    if(fptr == NULL){
                         printf("Unable to load the address of function\n");
                         return -1;
                    }
                break; 
        case 4: fptr = dlsym(ptr,"division");
                    if(fptr == NULL){
                         printf("Unable to load the address of function\n");
                         return -1;
                    }
                break; 

        default: printf("Invalid Choice\n");
                                          
    }

    

    fptr();
    return 0;
}