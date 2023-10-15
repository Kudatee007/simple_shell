#include "simple_shell.h"

/**
 * main - simple shell
 * @argc: get the number of the command line
 * @argv: get the array of the command line
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
    extern char **environ;
    char *command;
    char *dir;
    char *line;
    char **args;
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    (void)argc;
    (void)argv;

    /* declare and initialize command to NULL **before** the loop */
    while (1)
    {
        /* get the current working directory */
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) == NULL)
        {
            perror("Error");
            break;
        }
        /* remove the initial part of the current working directory */
        dir = strstr(cwd, "/mnt/c/Program Files/Git/root/alx-low_level_programming/simple_shell");
        if (dir != NULL)
        {
            dir += strlen("/mnt/c/Program Files/Git/root/alx-low_level_programming/simple_shell");
        }
        else
        {
            dir = cwd;
        }
        /* print the prompt */
        printf("#cisfun%s$ ", dir);

        /* read a line from stdin */
        read = _getline(&line, &len, stdin);
        /* check for EOF or error */
        if (read == -1)
        {
            printf("\n");
            break;
        }
        if (read > 1)
        {
            /* remove the newline character */
            line[read - 1] = '\0';
            /* split the line into arguments */
            args = split_line(line);

/*********************i AM HAVING ISSUE HERE ***********************/
            if (strcmp(args[0], "ls") == 0)
            {
                /* if the command is "ls", use the full path to the command */
                char *full_path = "/bin/ls";
                if (execv(full_path, args) == -1)
                {
                    perror("Error");
                    free(args);
                    exit(EXIT_FAILURE);
                }
            }

            if (strcmp(args[0], "exit") == 0)
            {
                int status = 0;

                if (args[1] != NULL)
                {
                    status = atoi(args[1]);
                }
                exit(status);
            }

            if (strcmp(args[0], "env") == 0)
            {
                char **env = environ;
                while (*env != NULL)
                {
                    printf("%s\n", *env);
                    env++;
                }
                continue;
            }

            if (strcmp(args[0], "cd") == 0)
            {
                _cd(args[1]);

                /* free the arguments */
                free(args);
                continue;
            }
            if (strcmp(args[0], "setenv") == 0)
            {
                _setenv(args);
                free(args);
                continue;
            }
            if (strcmp(args[0], "unsetenv") == 0)
            {
                _unsetenv(args);
                free(args);
                continue;
            }
            command = find_command(args[0]);
            /* find the full path of the command **before** creating a child process */
            if (command == NULL) /* check if the command is not found */
            {
                fprintf(stderr, "%s: command not found\n", args[0]); /* print error message */
                free(args);
                continue; /* skip to next iteration */
            }

            /* create a child process to execute the command */
            pid = fork();
            if (pid == -1)
            {
                perror("Error");
                free(args);
                continue;
            }
            else if (pid == 0)
            {
                if (execvp(args[0], args) == -1)
                {
                    perror("Error");
                    free(args);
                    exit(EXIT_FAILURE);
                }
                free(command);
            }
            else
            {
                /* wait for the child process to complete */
                wait(NULL);
            }
            /* free the arguments */
            free(args);
        }

        free(line);
    }

    return 0;
}
