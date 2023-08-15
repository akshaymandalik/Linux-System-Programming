#include<stdio.h>
#include<sys/mman.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){

    int fd = 0;
    void *fileData;
    struct stat sObj;

    fd = open("Demo.txt",O_RDONLY);
    if(fd == -1){
        printf("Error:Failed to open Demo file\n");
        return 1;
    }

    if(stat("input.txt",&sObj) == -1){
        printf("Error:Enable to get File Size");
        close(fd);
        return 1;
    }

    fileData = mmap(NULL,sObj.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(fileData == MAP_FAILED){
        printf("Error:Unable to Map File\n");
        close(fd);
        return 1;
    }

    printf("Data in the file is:\n%s",(char *)fileData);
    
    munmap(fileData,sObj.st_size);

    close(fd);

    return 0;
}