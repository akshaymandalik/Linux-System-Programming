/*
Problem Statement: Write a program which accept file name from user and read whole file.
Author Name: Akshay Mandalik
Last Modified: 15 July 08:24PM
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
int main(int args, char *argv[]){

    int isExists=-1;
    int isReadable =-1;
    int fd = 0;
    int ret = 0;
    char buffer[100]={"\0"};

    if(args != 2){
        printf("Error: Invalid Arguments\n");
        printf("Usage: Name_of_executable[space]Name of file");
        return -1;
    }

    isExists = access(argv[1],F_OK);
    
    if(isExists == 0){

        printf("File Exists\n");
        isReadable = access(argv[1],R_OK);
        if(isReadable == 0){


            fd = open(argv[1],O_RDONLY);
            if(fd == -1){
                printf("Error: Unable to open file\n");
                close(fd);
                return -1;
            }

            while((ret = read(fd,buffer,sizeof(buffer)))!=0){
                write(1,buffer,ret);
            }
            
            close(fd);

        }else if(errno == EACCES){
            printf("Error: No permission to read file\n");
            return -1;
        }

    }
    else if(errno == ENOENT)
    {
        printf("Error: File does not exists\n"); 
        return -1;
    }

    return 0;
}