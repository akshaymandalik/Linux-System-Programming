#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){

    int fd = 0;
    int fdnew = 0;
    struct stat sObj,sObj1;

    fd = open("demo.txt",O_RDONLY);
    printf("File opened with fd:%d\n",fd);

    fdnew = dup(fd);
    printf("Duplicate fd is:%d\n",fdnew);

    fstat(fd,&sObj);
    printf("Filesize:%d",sObj.st_mode);

    fstat(fdnew,&sObj1);
    printf("Filesize:%d",sObj1.st_mode);

    //Same filetable la point karata donhi fd.

    return 0;
}