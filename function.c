#include "main.h"

/* Function to read a line */
ssize_t read_line(char **line, size_t *len)
{
    ssize_t read;

    printf("#cisfun$ ");
    read = getline(line, len, stdin);
    if (read == -1)
    {
        printf("\n");
    }
    return read;
}

void execute_command(char *line)
{
    pid_t pid;
    int status;
    char *argv[2]; /* Create an array for arguments */

    argv[0] = line; /* The command itself as the first argument */
    argv[1] = NULL; /* The array should be NULL-terminated */

    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        return;
    }
    if (pid == 0)
    {
        /* Child process */
        if (execve(argv[0], argv, NULL) == -1) /* Pass argv instead of NULL */
        {
            perror("Error:");
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        /* Parent process */
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}