#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dlfcn.h>
#include "Problem3.h"

int main(){

    int iVal = 0;
    void *ptr = NULL;

    int (*fptr)(int)= NULL;
    int choice = 0;
    int ret = 0;
       
    printf("1.Check Prime\n2.Check Perfect\n");
    printf("Enter Your Choice:");
    scanf("%d",&choice);

    switch(choice){

         case 1: printf("Enter No. to check Prime or not:");
                 scanf("%d",&iVal);
                 ptr = dlopen("SharedFile3.so",RTLD_LAZY);
                    if(ptr == NULL){
                         printf("Unable to load Library File\n");
                         return -1;
                    }
                 fptr = dlsym(ptr,"checkPrime");
                 if(fptr == NULL){
                    printf("Error: Unable to call checkPrime\n");
                    return -1;
                 } 
                 ret = fptr(iVal);
                 if(ret == 0)
                    printf("%d is Prime Number\n",iVal);
                 else
                    printf("%d is not Prime Number\n",iVal);

                 break;   

        case 2:  printf("Enter No. to check Perfect or not:");
                 scanf("%d",&iVal);
                 
                 ptr = dlopen("SharedFile3-1.so",RTLD_LAZY);
                    if(ptr == NULL){
                         printf("Unable to load Library File\n");
                         return -1;
                    }

                 fptr = dlsym(ptr,"checkPerfect");
                 if(fptr == NULL){
                    printf("Error: Unable to call checkPerfect\n");
                    return -1;
                 } 

                 ret = fptr(iVal);
                 if(ret == 0)
                    printf("%d is Perfect Number\n",iVal);
                 else
                    printf("%d is not Perfect Number\n",iVal);

                 break;

        default: printf("Error: Invalid Choice\n");                      
    }

    return 0;
}