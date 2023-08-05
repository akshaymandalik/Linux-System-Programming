#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){

    DIR *dir = NULL;
    struct dirent *entry = NULL;
    int fd = 0;
    char fileName[256];
    int length = 0;

    dir = opendir("/Users/akshay/Desktop");
    if(dir == NULL){
        printf("Error: Unable to open Desktop\n");
        return -1;
    }

    fd = creat("Demo.txt",0777);
    if(fd == -1){
        printf("Error: Unable to create demo file\n");
        closedir(dir);
        return -1;
    }

    while((entry= readdir(dir))!= NULL){

        strcpy(fileName,entry->d_name);
        length = strlen(fileName);
        fileName[sizeof(fileName)-1] = '\0';
        write(fd,fileName,strlen(fileName));
        write(fd,"\n",1);

    }

    close(fd);

    return 0;   
}