#include "main.h"

int main() {
    pid_t pid;
    int status, i;

    for (i = 0; i < 5; i++) {
        pid = fork();
        if (pid == -1) {
            perror("Error:");
            return 1;
        } else if (pid == 0) {
            /* Child process */
            char *args[] = {"ls", "-l", "/tmp", NULL};
            execve("/bin/ls", args, NULL);
            perror("execve");
            exit(1);
        } else {
            /* Parent process */
            wait(&status);
        }
    }

    return 0;
}