/*
    Problem Statement: Write a program which accept directory name from user and combine all contents of file from that directory into one file named as AllCombine.
    Author Name: Akshay Mandalik
    Last Modified: 21 July 2023
*/


#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#define MAXSIZE 1024
int main(int args, char *argv[]){

    DIR *dir = NULL;
    struct dirent *entry = NULL;
    int destfd = 0;
    int tempfd = 0;
    char buffer[1024]={"\0"};
    char filePath[256]={"\0"};
    int ret = 0;

    if(args != 2){
        printf("Error: Insufficient Arguments\n");
        return -1;
    }

    destfd = open("Allcombine.txt",O_WRONLY | O_CREAT | O_TRUNC,0777);
    if(destfd == -1){
        printf("Error: Unable to create/open All Combine File\n");
        return -1;
    }

    close(destfd);

    dir  = opendir(argv[1]);
    if(dir == NULL){
        printf("Error: Unable to open Directory\n");
        return -1;
    }

    destfd = open("AllCombine.txt",O_WRONLY);
    if(destfd == -1){
        printf("Error: Unable to open file\n");
        return -1;
    }

    while((entry = readdir(dir))!= NULL){

        sprintf(filePath,"%s/%s",argv[1],entry->d_name);
        tempfd = open(entry->d_name,O_RDONLY);

        if(tempfd == -1){
            printf("Unable to read %s file.",filePath);
        }

        while((ret = read(tempfd,buffer,MAXSIZE)) > 0){
            write(destfd,buffer,ret);
        }
        close(tempfd);
    }
    

    close(destfd);
    return 0;
}