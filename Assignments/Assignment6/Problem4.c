#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_name>\n", argv[0]);
        return -1;
    }

    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error opening directory");
        return -1;
    }

    struct dirent *entry;
    struct stat sObj;
    char filePath[256];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current directory and parent directory entries
        }

        snprintf(filePath, sizeof(filePath), "%s/%s", argv[1], entry->d_name);

        if (stat(filePath, &sObj) == -1) {
            printf("Error getting file information");
            continue;
        }

        if (S_ISREG(sObj.st_mode) && sObj.st_size > 100) {
            // Delete the file
            if (unlink(filePath) == -1) {
                perror("Error deleting file");
                continue;
            }
            printf("File '%s' deleted successfully.\n", filePath);
        }
    }

    closedir(dir);
    return 0;
}
