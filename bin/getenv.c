#include "main.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 * Return: value of the environment variable
 */
extern char **environ;
char *_getenv(const char *name)
{
    char **env = environ;
    size_t namelen = strlen(name);
    while (*env != NULL)
    {
        if (strncmp(*env, name, namelen) == 0 && (*env)[namelen] == '=')
        {
            return &((*env)[namelen + 1]);
        }
        env++;
    }
        return NULL;
    
}

int main()
{
    char *path = _getenv("PATH");
    if (path != NULL)
    {
        printf("PATH=%s\n", path);
    }else
    {
        printf("PATH not found\n");
    }
    
    
    return 0;
}
