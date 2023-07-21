/*
    Problem Statement: Write a program which accept directory name from user 
                       and write information of all regular file in and then read the contents from that file.
    Author Name: Akshay Mandalik
    Last Modified: 21 July 2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#pragma pack(1)
struct FileInfo {
    char fName[256];
    int fileSize;
    int iNodeno;
};

int main(int argc, char *argv[]) {
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    struct FileInfo fileEntry;
    struct stat sObj;
    char filePath[256] = {0};
    int destfd = 0;
    int ret = 0;

    if (argc != 2) {
        printf("Error: Invalid Arguments\n");
        return -1;
    }

    dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error: Unable to open Directory\n");
        return -1;
    }

    destfd = open("fileinfo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (destfd == -1) {
        printf("Error: Unable to create File\n");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        sprintf(filePath, "%s/%s", argv[1], entry->d_name);
        if (stat(filePath, &sObj) == -1) {
            printf("Error: Unable to get file information for %s\n", entry->d_name);
            continue;
        }

        memset(&fileEntry, 0, sizeof(fileEntry));
        if (S_ISREG(sObj.st_mode)) {
            strncpy(fileEntry.fName, entry->d_name, sizeof(fileEntry.fName) - 1);
            fileEntry.fileSize = sObj.st_size;
            fileEntry.iNodeno = sObj.st_ino;
            write(destfd, &fileEntry, sizeof(fileEntry));
        }
    }

    closedir(dir);
    close(destfd);

    // Read and display the contents of "fileinfo.txt"
    destfd = open("fileinfo.txt", O_RDONLY);
    if (destfd == -1) {
        printf("Error: Unable to open File\n");
        return -1;
    }

    printf("Reading data.....\n");

    while ((ret = read(destfd, &fileEntry, sizeof(fileEntry))) != 0) {
        printf("FileName: %s\n", fileEntry.fName);
        printf("FileSize: %d\n", fileEntry.fileSize);
        printf("File Inode: %d\n", fileEntry.iNodeno);
        printf("\n");
    }

    if (ret == -1) {
        printf("Error: Unable to read File\n");
    }

    close(destfd);

    return 0;
}
