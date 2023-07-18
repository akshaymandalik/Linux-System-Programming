/*
Problem Statement: Write a program which accept two file names from user and copy the contents of an existing file into newly created file.
Author Name: Akshay Mandalik
Last Modified: 18 July 2023 
*/
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#define MAXSIZE 1024
int main(int args,char *argv[]){

    int sourcefd = 0,destfd = 0;
    int isExists = -1;
    int isReadable = -1;
    char buffer[MAXSIZE]={"\0"};
    int ret = 0;

    if(args!=3){            //Checks if given argumets are less/more.
        printf("Error: Invalid Arguments\n");
        printf("Usage: Name_of_Executable[space]Name_of_File_to_Copy[space]Name_of_new_file\n");
        return -1;
    }

    isExists = access(argv[1],F_OK);
    if(isExists == 0){                  // Checks if given file exists or not.

        isReadable = access(argv[1],R_OK);
        if(isReadable == 0){            // Checks if given file is Readable or not.

            sourcefd = open(argv[1],O_RDONLY);
            if(sourcefd == -1){              // Checks if is there any issue in opening given file.
                printf("Unable to open file\n");
                return -1;
            }

            destfd = creat(argv[2],0777);
            if(destfd == -1){               // Checks if there is any issue in creating new file.
                printf("Unable to create file\n");
                return -1;
            }

            while((ret = read(sourcefd,buffer,MAXSIZE)) != 0){  //Reads data from existing file.

                write(destfd,buffer,ret);       //Writes data to the new file.
            }

            close(sourcefd);                //Closing file descriptor of opened file.
            printf("Content Copied Successfully\n");
            
        }else if(errno == EACCES){
            printf("You don't have permission to read this file\n");  //Error message existing file does not read permission.
            return -1;
        }


    }else if(errno == ENOENT){
        printf("%s does not exists in current directory\n",argv[1]); //Error message existing file does not exists.
            
        return -1;
    }


    return 0;
}