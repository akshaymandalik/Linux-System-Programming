#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s input_filename\n", argv[0]);
        return -1;
    }

    int inputFile = open(argv[1], O_RDONLY);
    if (inputFile == -1) {
        printf("Error: Unable to open input file %s\n", argv[1]);
        return 1;
    }

    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    int bytes_read;
    int content_length;
    off_t file_size;

    while ((bytes_read = read(inputFile, filename, MAX_FILENAME_LENGTH)) > 0) {
        // Replace the newline character with null terminator to separate filename and content.
        filename[bytes_read - 1] = '\0';

        content_length = read(inputFile, content, MAX_FILE_CONTENT_LENGTH);
        if (content_length <= 0) {
            printf("Error: Invalid format in input file.\n");
            close(inputFile);
            return 1;
        }

        // Check the size of the file.
        file_size = (off_t)content_length;
        if (file_size > 10) {
            printf("Filename with size greater than 10 bytes: %s\n", filename);
        }
    }

    close(inputFile);

    return 0;
}
