/*
Problem Statement:
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#define TRUE 1
#define FALSE 2
int main(int args, char *argv[]){

    int sourcefd = 0;
    int destfd = 0;
    struct stat obj1,obj2;
    char buffer1[1024]={"\0"};
    char buffer2[1024]={"\0"};
    int ret = 0;
    int iCnt = 0;

    if(args!=3){
        printf("Insufficient Arguments\n");
        return -1;
    }

    sourcefd = open(argv[1],O_RDONLY);
    destfd = open(argv[2],O_RDONLY);
    if(sourcefd ==-1 |destfd == -1){

        printf("Unable to open\n");
        return -1;
    }

    fstat(sourcefd,&obj1);
    fstat(destfd,&obj2);
    if(obj1.st_size != obj2.st_size){

        printf("Files are different\n");
        return -1;
    }

    while((ret = read(sourcefd,buffer1,sizeof(buffer2)))!=0){

        iCnt++;
        ret = read(destfd,buffer2,sizeof(buffer2));
        if(memcmp(buffer1,buffer2,ret)!=0){
            break;
        }
    }
    if(ret == 0){
        printf("No. of iterations:%d",iCnt);
        printf("Files are identical\n");
    }
    else{
        printf("File are Different\n");
    }
    
    return 0;
}