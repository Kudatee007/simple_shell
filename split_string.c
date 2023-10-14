#include "main.h"
/**
 * split_string - splits a string into an array of strings
 * @str: string to split
 * @delim: delimiter to split string by
 * @num_tokens: pointer to store number of tokens in string
 * Return: pointer to array of strings 
 */

char **split_string(char *str, const char *delim, int *num_tokens) {
    char **tokens = NULL;
    char *token;
    int i = 0, j = 0, len = strlen(str);

    while (i < len) {
        /* Skip leading delimiters */
        while (i < len && strchr(delim, str[i]) != NULL) {
            i++;
        }

        /* Find end of next token */
        j = i;
        while (j < len && strchr(delim, str[j]) == NULL) {
            j++;
        }

        /* Add token to array */
        if (j > i) {
            tokens = realloc(tokens, (i + 1) * sizeof(char *));
            tokens[*num_tokens] = malloc((j - i + 1) * sizeof(char));
            strncpy(tokens[*num_tokens], &str[i], j - i);
            tokens[*num_tokens][j - i] = '\0';
            (*num_tokens)++;
        }

        i = j + 1;
    }

    return tokens;
}

int main() {
    char str[] = "This is a test string";
    char **tokens;
    int num_tokens = 0, i;

    tokens = split_string(str, " ", &num_tokens);

    for (i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }

    free(tokens);
    return 0;
}