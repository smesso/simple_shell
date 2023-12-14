#include "shell.h"

/**
 * getline_command - Prints the shell prompt and reads a line of input from the user.
 * Return: A dynamically allocated string containing the user's input.
 *         Returns NULL on failure or if the user enters EOF (Ctrl-D).
 */
char *getline_command(void)
{
    char *lineptr = NULL;
    size_t buffer_size = 0;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
    ssize_t chars_read = getline(&lineptr, &buffer_size, stdin);

    if (chars_read == -1)
    {
        free(lineptr);
        return NULL;
    }

    if (chars_read > 0 && lineptr[chars_read - 1] == '\n')
        lineptr[chars_read - 1] = '\0';

    return lineptr;
}

