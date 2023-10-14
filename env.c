#include "main.h"

extern char **environ;

int main(int argc, char *argv[], char **env)
{
    (void)argc;
    (void)argv;
    printf("this is the address of env %p\n", (void *)env);
    printf("this is the address of environ %p\n", (void *)environ);

    return 0;
}