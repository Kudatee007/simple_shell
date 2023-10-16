#include "simple_shell.h"

/**
 * split_line - splits a line into tokens
 * @line: line to split
 * Return: array of tokens
 */
char **split_line(char *line)
{
    int bufsize = TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
<<<<<<< HEAD

=======
    char *token = NULL;
    int reallocated = 0;
    char **temp;
>>>>>>> fe20ff6 (Task 0 to 10 fix)
    if (!tokens)
    {
	    perror("hsh: allocation error");
	    exit(EXIT_FAILURE);
    }

    char *token = _strtok(line, TOK_DELIM);
    while (token != NULL)
    {
	    tokens[position] = strdup(token);

        if (!tokens[position])
        {
            perror("hsh: allocation error");
            exit(EXIT_FAILURE);
        }

        position++;

        if (position >= bufsize)
        {
            bufsize += TOK_BUFSIZE;
            temp = realloc(tokens, bufsize * sizeof(char *));
            if (!temp)
            {
<<<<<<< HEAD
                perror("hsh: allocation error");
=======
                fprintf(stderr, "hsh: reallocation error\n");
                free(tokens);
>>>>>>> fe20ff6 (Task 0 to 10 fix)
                exit(EXIT_FAILURE);
            }
            tokens = temp;
            reallocated = 1; 
        }
        token = _strtok(NULL, TOK_DELIM);
    }

    tokens[position] = NULL;
<<<<<<< HEAD
=======

    if (reallocated)
        free(tokens);

>>>>>>> fe20ff6 (Task 0 to 10 fix)
    return tokens;
}

/**
 * exec_command - executes a command
 * @args: array of arguments
 */
void exec_command(char **args)
{
    char *command_path = find_command(args[0]);

    if (command_path == NULL)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        exit(EXIT_FAILURE);
    }

    if (execve(command_path, args, NULL) == -1)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
}

/**
 * find_command - finds a command in the directories listed in PATH
 * @command: the command to find
 * Return: the full path to the command, or NULL if not found
 */
char *find_command(char *command)
{
    char *path = getenv("PATH");
    char *dir = _strtok(path, ":");
    while (dir != NULL)
    {
        char *full_path = malloc(strlen(dir) + strlen(command) + 2);
        snprintf(full_path, strlen(dir) + strlen(command) + 2, "%s/%s", dir, command);
        if (access(full_path, X_OK) == 0)
        {
            return full_path;
        }
        free(full_path);
        dir = _strtok(NULL, ":");
    }
    return NULL;
}

/**
 * execute_ls - executes the ls command
 * @args: array of arguments
 */
void execute_ls(char **args)
{
    if (args[1] == NULL)
    {
        char *current_directory = ".";
        args[1] = current_directory;
    }

    _ls(args + 1);
}

void print_mode(mode_t mode)
{
	switch (mode & S_IFMT)
	{
	case S_IFBLK:
		printf("b");
		break;
	case S_IFCHR:
		printf("c");
		break;
	case S_IFDIR:
		printf("d");
		break;
	case S_IFIFO:
		printf("p");
		break;
	case S_IFLNK:
		printf("l");
		break;
	case S_IFREG:
		printf("-");
		break;
	case S_IFSOCK:
		printf("s");
		break;
	default:
		printf("?");
		break;
	}
	printf((mode & S_IRUSR) ? "r" : "-");
	printf((mode & S_IWUSR) ? "w" : "-");
	printf((mode & S_IXUSR) ? "x" : "-");
	printf((mode & S_IRGRP) ? "r" : "-");
	printf((mode & S_IWGRP) ? "w" : "-");
	printf((mode & S_IXGRP) ? "x" : "-");
	printf((mode & S_IROTH) ? "r" : "-");
	printf((mode & S_IWOTH) ? "w" : "-");
	printf((mode & S_IXOTH) ? "x" : "-");
}


void _ls(char **path)
{
<<<<<<< HEAD
	char *name;
	char full_path[PATH_MAX];
	struct stat st;
	struct dirent *entry;
	DIR *dir = opendir(*path);
	if (dir == NULL)
	{
		perror("opendir");
		exit(1);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		name = entry->d_name;
		if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
		{
			continue;
		}
		sprintf(full_path, "%s/%s", *path, name);
		if (lstat(full_path, &st) == -1)
		{
			perror("lstat");
			exit(1);
		}
		print_mode(st.st_mode);
		printf(" %ld ", st.st_size);
		printf("%s\n", name);
	}
	closedir(dir);
=======
    char *name;
    char full_path[PATH_MAX];
    struct stat st;
    struct dirent *entry;
    DIR *dir = opendir(*path);
    if (dir == NULL)
    {
        perror("opendir");
        exit(1);
    }
    while ((entry = readdir(dir)) != NULL)
    {
        name = entry->d_name;
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
        {
            continue;
        }
        sprintf(full_path, "%s/%s", *path, name);
        if (lstat(full_path, &st) == -1)
        {
            perror("lstat");
            continue;
        }
        print_mode(st.st_mode);
        printf(" %ld ", st.st_size);
        printf("%s\n", name);
    }
    closedir(dir);
>>>>>>> fe20ff6 (Task 0 to 10 fix)
}

/**
 * _getline - reads an entire line from a file stream
 * @lineptr: pointer to a buffer
 * @n: pointer to the size of the buffer
 * @stream: file stream to read from
 * Return: number of bytes read, or -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
<<<<<<< HEAD
	static char buffer[BUFFER_SIZE];
	size_t len = 0;
	char *new_line;
	size_t linelen;
	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return -1;
	}
=======
    char *buffer = NULL;
    size_t len = 0;
    ssize_t linelen;
/*     ssize_t read;
 */
    if (lineptr == NULL || n == NULL)
    {
        errno = EINVAL;
        return -1;
    }
>>>>>>> fe20ff6 (Task 0 to 10 fix)

	if (*lineptr == NULL)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return -1;
		}
	}

<<<<<<< HEAD
	while (1)
	{
		char *newline = fgets(buffer, BUFFER_SIZE, stream);
		if (newline == NULL)
		{
			break;
		}

		linelen = strlen(newline);
		if (len + linelen >= *n)
		{
			*n *= 2;
			new_line = realloc(*lineptr, *n);
			if (new_line == NULL)
			{
				return -1;
			}
			*lineptr = new_line;
		}

		memcpy(*lineptr + len, newline, linelen);
		len += linelen;

		if (newline[linelen - 1] == '\n')
		{
			break;
		}
	}

	(*lineptr)[len] = '\0';

	return len;
=======
    buffer = NULL; 
    linelen = getdelim(&buffer, &len, '\n', stream);
    if (linelen == -1)
    {
        free(buffer);
        return -1;
    }

    if (linelen > 0 && buffer[linelen - 1] == '\n')
    {
        buffer[linelen - 1] = '\0';
        linelen--;
    }

    if (linelen >= (ssize_t)*n)
    {
        *n = linelen + 1;
        *lineptr = realloc(*lineptr, *n);
        if (*lineptr == NULL)
        {
            free(buffer);
            return -1;
        }
    }

    memcpy(*lineptr, buffer, linelen + 1);
    free(buffer);

    return linelen;
>>>>>>> fe20ff6 (Task 0 to 10 fix)
}
/**
 * _strtok - splits a string into tokens
 * @str: string to split
 * @delim: delimiter to split string by
 * Return: pointer to the next token
 */
char *_strtok(char *str, const char *delim)
{
	static char *last = NULL;
	char *tok = NULL;

	if (str != NULL)
	{
		last = str;
	}
	else if (last == NULL)
	{
		return NULL;
	}

	tok = last;
	while (*last != '\0')
	{
		if (strchr(delim, *last) != NULL)
		{
			*last++ = '\0';
			break;
		}
		last++;
	}

	if (*tok == '\0')
	{
		return NULL;
	}
	else
	{
		return tok;
	}
}

/**
 * _setenv - sets an environment variable
 * @args: array of arguments
 * Return: void
 */
void _setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}

	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("Error");
	}
}

/**
 * _unsetenv - unsets an environment variable
 * @args: array of arguments
 * Return: void
 */
void _unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return;
	}

	if (unsetenv(args[1]) != 0)
	{
		perror("Error");
	}
}

/**
 * _cd - changes the current working directory
 * @path: path to change to
 * Return: 0 on success, -1 on failure
 */
int _cd(char *path)
{
    char old_path[MAX_PATH];
    char new_path[MAX_PATH];
    if (getcwd(old_path, MAX_PATH) == NULL)
    {
        perror("getcwd");
        return -1;
    }

    if (path == NULL)
    {
        path = getenv("HOME");
        if (path == NULL)
        {
            perror("getenv");
            return -1;
        }
    }

    if (strcmp(path, "-") == 0)
    {
        path = getenv("OLDPWD");
        if (path == NULL)
        {
            perror("getenv");
            return -1;
        }
    }

    if (chdir(path) == -1)
    {
        perror("chdir");
        return -1;
    }

    if (getcwd(new_path, MAX_PATH) == NULL)
    {
        perror("getcwd");
        return -1;
    }

    if (setenv("PWD", new_path, 1) == -1)
    {
        perror("setenv");
        return -1;
    }

    if (setenv("OLDPWD", old_path, 1) == -1)
    {
        perror("setenv");
        return -1;
    }

    return 0;
}

int main(void)
{
    char *line;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        printf("$ ");
        read = _getline(&line, &len, stdin);

        if (read == -1)
        {
            perror("Error reading line");
            exit(EXIT_FAILURE);
        }

        if (read == 0)
        {
            break; // EOF
        }

        char **args = split_line(line);
        if (args[0] != NULL)
        {
            if (strcmp(args[0], "exit") == 0)
            {
                free(line);
                free(args);
                exit(EXIT_SUCCESS);
            }

            if (strcmp(args[0], "cd") == 0)
            {
                _cd(args[1]);
            }
            else if (strcmp(args[0], "setenv") == 0)
            {
                _setenv(args);
            }
            else if (strcmp(args[0], "unsetenv") == 0)
            {
                _unsetenv(args);
            }
            else if (strcmp(args[0], "ls") == 0)
            {
                execute_ls(args);
            }
            else
            {
                exec_command(args);
            }
        }

        free(line);
        free(args);
    }

    return 0;
}
