/*
    Problem Statement: Write a program which accept directory name from user and combine all contents of file from that directory into one file named as AllCombine.
    Author Name: Akshay Mandalik
    Last Modified: 21 July 2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s input_filename\n", argv[0]);
        return 1;
    }

    int inputFile = open(argv[1], O_RDONLY);
    if (inputFile == -1) {
        printf("Error: Unable to open input file %s\n", argv[1]);
        return 1;
    }

    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int outputFile;

    int bytes_read;
    int content_length;

    while ((bytes_read = read(inputFile, filename, MAX_FILENAME_LENGTH)) > 0) {
        // Replace the newline character with null terminator to separate filename and content.
        filename[bytes_read - 1] = '\0';

        content_length = read(inputFile, content, MAX_FILE_CONTENT_LENGTH);
        if (content_length <= 0) {
            printf("Error: Invalid format in input file.\n");
            close(inputFile);
            return 1;
        }

        outputFile = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (outputFile == -1) {
            printf("Error: Unable to create file %s\n", filename);
            close(inputFile);
            return 1;
        }

        // Write the content to the output file using system call.
        write(outputFile, content, content_length);
        close(outputFile);
    }

    close(inputFile);
    printf("All files have been created successfully!\n");

    return 0;
}
