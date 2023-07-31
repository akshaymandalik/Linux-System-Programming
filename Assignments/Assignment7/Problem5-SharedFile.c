#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>

int fileInfo(char *fileName){

    struct stat sObj;
    int isExists = 0;

    isExists = access(fileName,F_OK);
    if(isExists == 0){

            stat(fileName,&sObj);
            printf("File Name:%s",fileName);
            printf("File size:%lld",sObj.st_size);
            printf("File INode:%llu",sObj.st_ino);
            printf("File Mode:%d",sObj.st_mode);
    }
    else{
        return -1;
    }

    return 0;
}