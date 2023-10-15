#ifndef MAIN_H
#define MAIN_H

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

/* Function Declarations */
/**
 * split_string - Split a string into tokens based on a delimiter.
 * @str: The input string to be split.
 * @delim: The delimiter used to split the string.
 * @num_tokens: A pointer to an integer to store the number of tokens.
 *
 * Return: An array of strings containing the tokens.
 */
char **split_string(char *str, const char *delim, int *num_tokens);
char *build_path(char *dir, char *cmd);
char *find_path(char *cmd, char **env);
void print_env(char **env);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/**
 * MAX_PATH_LENGTH - Maximum Path Length
 * MAX_FILENAME_LENGTH - Maximum Filename Length
 */
#define MAX_PATH_LENGTH 1024
#define MAX_FILENAME_LENGTH 256

#endif /* MAIN_H */
