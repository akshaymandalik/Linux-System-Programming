#include<stdio.h>
#include<stdlib.h>
int main(){
    
    char *arr[7];
    int iCnt = 0;
    arr[1] = (char *)malloc(sizeof(char *));

    if(arr[1] == NULL){
        printf("Unable to allocate Memory\n");
    }
    
    arr[2] ="Pawan";
    arr[3]= NULL;

    while(arr[iCnt] != NULL){
        printf("%s",arr[iCnt]);
        iCnt++;
    } 

    return 0;
}