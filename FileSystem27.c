/*
Problem Statement:
Author Name: Akshay Mandalik
Last Modified: Sat 15 July 10:02 AM
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>



int main(int args, char *argv[]){

    char dirName[20] = {"\0"};
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30]={"\0"};
    struct stat sObj;
    int iMax = 0;
    char nameCopy[20]={"\0"};

    printf("Enter Name of Directory:");
    scanf("%s",dirName);

    dp = opendir(dirName);
    if(dp == NULL){
        printf("Unable to open Directory\n");
        return -1;
    }

    printf("Empty Files Are:");
    while((entry = readdir(dp)) != NULL){

        sprintf(name,"%s/%s",dirName,entry->d_name);
        stat(name,&sObj);
        if(S_ISREG(sObj.st_mode)){

                if(sObj.st_size == 0){
                    printf("%s",name);
                }
        }
    }

    printf("Name of Largest file is %s with filesize %d\n",nameCopy,iMax);


    closedir(dp);

    return 0;
}