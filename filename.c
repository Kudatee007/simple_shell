#include "main.h"


int main(int argc, char *argv[]) {
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char filename[MAX_FILENAME_LENGTH];
    int found = 0;

    if (argc < 2) {
        printf("Usage: %s filename ...\n", argv[0]);
        return 1;
    }

    while (dir != NULL) {
        snprintf(filename, MAX_FILENAME_LENGTH, "%s/%s", dir, argv[1]);
        if (access(filename, F_OK) == 0) {
            printf("%s\n", filename);
            found = 1;
        }
        dir = strtok(NULL, ":");
    }

    if (!found) {
        printf("%s: command not found\n", argv[1]);
        return 1;
    }

    return 0;
}