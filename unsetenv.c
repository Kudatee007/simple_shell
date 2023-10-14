#include "main.h"

extern char **environ;

int _unsetenv(const char *name) {
    char **env = environ;
    size_t namelen = strlen(name);

    while (*env != NULL) {
        if (strncmp(*env, name, namelen) == 0 && (*env)[namelen] == '=') {
            char **next = env + 1;
            while (*next != NULL) {
                *(next - 1) = *next;
                next++;
            }
            *(next - 1) = NULL;
            return 0;
        }
        env++;
    }

    return -1;
}

int main() {
    char *new_path = "/usr/local/bin:/usr/bin:/bin";
    if (setenv("PATH", new_path, 1) != 0) {
        printf("Error setting PATH\n");
        return 1;
    }
    printf("PATH set to %s\n", getenv("PATH"));

    if (_unsetenv("PATH") != 0) {
        printf("Error unsetting PATH\n");
        return 1;
    }
    printf("PATH unset\n");

    printf("PATH is now %s\n", getenv("PATH"));

    return 0;
}