#include "main.h"

/**
 * getppid_builtin - prints the PID of the parent process
 * @args: arguments
 * Return: 1 if success, 0 if failure
 */
int main()
{
    pid_t ppid = getppid();
    char ppid_str[20];

    sprintf(ppid_str, "%d", ppid);
    printf("Parent PID: %s\n", ppid_str);

    return 0;
}