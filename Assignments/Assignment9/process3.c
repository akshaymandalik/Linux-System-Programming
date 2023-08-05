#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#define MAXSIZE 1024
int main(){

    int fd1 = 0,iCnt1 = 0,iRet = 0,fd2 = 0;
    char buffer[MAXSIZE];
    int iCnt = 0;

    fd1 = open("hello.txt",O_RDONLY);
    if(fd1 == -1){
        printf("Error: Unable to open Demo.txt");
        return -1;
    }

    fd2 = open("count.txt",O_WRONLY);
    if(fd2 == -1){
        printf("Error: Unable to open Count.txt");
        return -1;
    }

    while((iRet = read(fd1,buffer,MAXSIZE)) != 0){

        iCnt = 0;
        while(buffer[iCnt] != '\0'){
            
            if(buffer[iCnt]>='A' && buffer[iCnt]<='Z'){

                iCnt1++;
            }
            iCnt++;
        }
    }

    printf("No of Capital Characters Are:%d\n",iCnt1);
    write(fd2,&iCnt1,sizeof(iCnt1));

    close(fd1);
    close(fd2);

    return 0;
}