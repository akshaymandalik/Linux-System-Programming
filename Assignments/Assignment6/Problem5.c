#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file_name> <offset>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    int offset = atoi(argv[2]);

    int fd = open(file_name, O_RDWR);
    if (fd == -1) {
        printf("Error opening file");
        return -1;
    }

    // Set the file offset to the specified position
    if (lseek(fd, offset, SEEK_SET) == -1) {
        printf("Error setting file offset");
        close(fd);
        return -1;
    }

    // Truncate the file from the specified offset
    if (ftruncate(fd, offset) == -1) {
        printf("Error truncating file");
        close(fd);
        return -1;
    }

    close(fd);
    printf("Data removed from offset %d in file '%s'\n", offset, file_name);

    return 0;
}
