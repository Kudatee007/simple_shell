#include "main.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;

    while (1)
    {
        read_line(&line, &len);
        execute_command(line);
    }

    free(line);
    return 0;
}