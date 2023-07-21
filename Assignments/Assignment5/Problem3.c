/*
    Problem Statement: Write a program which accept directory name from user 
                       and write information of all regular file in and then read the contents from that file.
    Author Name: Akshay Mandalik
    Last Modified: 21 July 2023
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

struct FileInfo{
    char fName[50];
    int fileSize;
    int iNodeno;
}

int main(int args, char *argv[]){

    DIR *dir = NULL;
    struct dirent *entry = NULL;
    struct FileInfo fileEntry;
    struct stat sObj;
    char filePath[50]={"\0"};

    if(args != 2){

        printf("Error: Invalid Arguuments\n");
        return -1;
    }

    dir = opendir(argv[1]);
    if(dir == NULL){
        printf("Error: Unable to open Directory\n");
        return -1;
    }

    

    while((entry = readdir(dir))!=NULL){


        sprintf(filePath,"%s/%s",argv[1],entry->d_name);
        stat(filePath,&sObj);
        if(S_ISREG(sObj.st_mode)){
            strcpy(fileEntry.fName,entry->d_name);
            fileEntry.fileSize = sObj.st_size;
            fileEntry.iNodeno = sObj.st_ino;
        }


    }


    return 0;
}