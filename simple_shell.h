#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* Standard Libraries */

/**
 * 1. stdio.h - Standard Input/Output
 * 2. stdlib.h - Standard Library
 * 3. unistd.h - Symbolic Constants and Types
 * 4. string.h - String Operations
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
/**
 * MAX_LEN - Maximum Length
 */
#define MAX_LEN 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024
#define MAX_PATH 1024

/* Function Prototypes */
char **split_line(char *line);
void exec_command(char **args);
char *find_command(char *command);
void execute_command(char **args);
void read_command(char *line, char **args);
void execute_ls(char **args);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);
void _setenv(char **args);
void _unsetenv(char **args);
int _cd(char *path);

#endif /* SIMPLE_SHELL_H */