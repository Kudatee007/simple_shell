#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    char command[100];
    pid_t pid;
    int status;

    while (1)
    {
        printf("#cisfun$ ");
        scanf("%s", command);

        pid = fork();
        if (pid == -1)
        {
            perror("Error:");
            return 1;
        }
        else if (pid == 0)
        {
            execl(command, command, NULL);
            perror("exec");
            exit(1);
        }
        else
        {
            wait(&status);
        }
    }
    return (0);
}