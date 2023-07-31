#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){

    int fd = 0; 
    char Buffer[512]={"\0"};
    int iCnt = 0;
    int iRet = 0,i=0;

    fd = open("Demo.txt",O_RDONLY);
    if(fd == -1){
        printf("Error: Unable to open file\n");
        return -1;
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0){

        for(i = 0;i<iRet;i++){
            if((Buffer[i]>='a') && (Buffer[i]<='z')){
                iCnt++;
            }
        }
    }

    printf("No.of small characters are:%d\n",iCnt);

    close(fd);
    return 0;
}