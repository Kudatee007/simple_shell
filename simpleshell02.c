/**
 * File: simple_shell.c
 * Authored by: Timilehin Kudaisi, Emmanuel Okoye.
 * Created on: October 8, 2023.
 * Description: Simple shell that handles command lines with arguments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * main - Entry point of the program.
 * Description: Displays a command prompt.
 *              Reads user input and executes commands with arguments.
 *
 * Return: EXIT_SUCCESS on successful execution, EXIT_FAILURE on failure.
 */

int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_byte;
	pid_t pid;

	while (1)
	{
	char *args[64];
	char *token;
	int arg_count;

	write(STDOUT_FILENO, "#cisfun$ ", 9);
	read_byte = read(STDIN_FILENO, buffer, BUFFER_SIZE);

	if (read_byte == 0)
	{
	write(STDOUT_FILENO, "\n", 1);
	break;
	}

	buffer[read_byte - 1] = '\0';
	
	token = strtok(buffer, " ");
	arg_count = 0;

	while (token != NULL)
	{
	args[arg_count++] = token;
	token = strtok(NULL, " ");
	}

	args[arg_count] = NULL;

	pid = fork();

	if (pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
	execvp(args[0], args);
	perror(args[0]);
	exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	}
	}

	return (EXIT_SUCCESS);
}
