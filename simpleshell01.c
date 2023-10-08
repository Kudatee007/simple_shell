#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - A UNIX command line interpreter.
 * File: simple_shell.c
 * Authored by: Timilehin Kudaisi, Emmanuel Okoye.
 * Created on: October 8, 2023.
 * Description: Basic UNIX command line interpreter.
 */

int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_byte;
	pid_t pidd;

	while (1)
	{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	read_byte = read(STDIN_FILENO, buffer, BUFFER_SIZE);

	if (read_byte == 0)
	{
	write(STDOUT_FILENO, "\n", 1);
	break;
	}

	buffer[read_byte - 1] = '\0';

	pidd = fork();

	if (pidd == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}

	if (pidd == 0)
	{
	execlp(buffer, buffer, (char *)NULL);
	perror(buffer);
	exit(EXIT_FAILURE);
	}
	else
	{
	wait(NULL);
	}
	}

	return (EXIT_SUCCESS);
}
