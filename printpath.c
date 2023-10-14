#include "main.h"

extern char **environ;

void print_path()
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");

    while (dir != NULL)
    {
        printf("%s\n", dir);
        dir = strtok(NULL, ":");
    }
    free(path_copy);
}

int main()
{
    print_path();
    return 0;
}