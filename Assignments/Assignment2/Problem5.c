/*
Problem Statement: Write a program which accept directory name from user and print name of such a file having largest size.
Author Name: Akshay Mandalik
Last Modified:16 July 2023 3:08PM
*/
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
int main(int args, char * argv[]){

    DIR *dir = NULL;
    struct dirent *entry = NULL;
    struct stat sObj;
    int iMax =0;
    char fileName[20]={"\0"};
    char largestFile[20]={"\0"};

    if(args!= 2){
        printf("Error: Invalid Arguments\n");
        return -1;
    }

    dir = opendir(argv[1]);
    if(dir == NULL){
        printf("Error: Unable to open Directory\n");
        closedir(dir);
        return -1;
    }

    while( (entry = readdir(dir)) != NULL){

        sprintf(fileName,"%s/%s",argv[1],entry->d_name);
        stat(fileName,&sObj);
        if(S_ISREG(sObj.st_mode)){

             if(iMax <sObj.st_size){

                iMax = sObj.st_size;
                strcpy(largestFile,fileName);
             }
        }
    }

    printf("%s is largest file with %d byte size",largestFile,iMax);

    return 0;
}