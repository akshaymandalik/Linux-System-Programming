/*
    Problem Statement: Write a program which accept directory name from user and copy first 10 bytes from all regular files into newly created file named as Demo.txt.
    Author Name: Akshay Mandalik
    Last Modified: 19 July 2023
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
int main(int args,char * argv[]){

    DIR *dir = NULL;
    struct dirent *entry = NULL;
    int sourcefd = 0;
    int destfd = 0;
    char sourcePath[30] = {"\0"};
    int ret = 0;
    char buffer[10]={"\0"};

    if(args !=3){
        printf("Error: Invalid Arguments\n");
        return -1;
    }

    dir = opendir(argv[1]);
    if(dir == NULL){
        printf("Error: Unable to open %s directory\n",argv[1]);
        return -1;
    }

    destfd = creat(argv[2],0777);
    if(destfd == -1){
        printf("Error: Unable to create file\n");
        return -1;
    }

    while((entry = readdir(dir))!= NULL){
            sprintf(sourcePath,"%s/%s",argv[1],entry->d_name);
            sourcefd = open(sourcePath,O_RDONLY);
            ret = read(sourcefd,buffer,sizeof(buffer));
            write(destfd,buffer,ret);
    }


    return 0;
}