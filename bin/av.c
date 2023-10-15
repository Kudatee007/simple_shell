#include "main.h"

/**
 * main - prints all arguments it receives
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 if success
 */
int main(int argc, char *argv[]) {
    int i;
    (void)argc;
    for (i = 0; argv[i] != NULL; i++)
    {
        /* code */
        printf("%s\n", argv[i]);
    }

    return (0);
}