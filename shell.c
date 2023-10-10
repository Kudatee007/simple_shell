#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point of the program.
 * Description: A beautiful code that passes the Betty checks.
 *
 * Return: Always 0.
 */

int main(void)
{
	char *input;

	while (1)
	{
		printf("$ ");
		getline(&input, NULL, stdin);

		free(input);
	}
}
