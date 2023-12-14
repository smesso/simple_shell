#include "shell.h"

/**
 * _get_path - get variable PATH.
 * @env: environment variable array
 * Return: value of PATH.
 */
char *_get_path(char **env)
{
    size_t index = 0;
    char *path = NULL;

    while (env[index] != NULL)
    {
        if (strncmp(env[index], "PATH=", 5) == 0)
        {
            path = strdup(env[index] + 5);
            break;
        }
        index++;
    }

    return path;
}

