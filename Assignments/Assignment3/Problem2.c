/*
Problem Statement: Write a program which accept directory name and file name from user and check whether that file is present in that directory or not.
Author Name: Akshay Mandalik
Last Modified: Tuesday,18July,2023.
*/
#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
int main(int args, char *argv[]){

    DIR *dir = NULL;
    struct dirent *entry = NULL;


    if(args!=3){            //Checks if given argumets are less/more.
        printf("Error: Invalid Arguments\n");
        printf("Usage: Name_of_Executable[space]Name_of_Directory[space]Name_of_file\n");
        return -1;
    }

    dir = opendir(argv[1]);
    if(dir == NULL){
        printf("Error: Uanble to open Directory\n");
        return -1;
    }

    while((entry = readdir(dir)) != NULL){

            if(strcmp(argv[2],entry->d_name)==0){
                break;
            }
    }

    if(entry == NULL){
        printf("File Not Found\n");
        return -1;
    }

    printf("File Found\n");

    return 0;
}