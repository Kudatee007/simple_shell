#include "main.h"

extern char **environ;

typedef struct node {
    char *dir;
    struct node *next;
} node_t;

node_t *build_path_list() {
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    node_t *head = NULL;
    node_t *tail = NULL;

    while (dir != NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->dir = strdup(dir);
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }

        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return head;
}

void free_path_list(node_t *head) {
    while (head != NULL) {
        node_t *next = head->next;
        free(head->dir);
        free(head);
        head = next;
    }
}

void print_path_list(node_t *head) {
    while (head != NULL) {
        printf("%s\n", head->dir);
        head = head->next;
    }
}

int main() {
    node_t *path_list = build_path_list();
    print_path_list(path_list);
    free_path_list(path_list);
    return 0;
}