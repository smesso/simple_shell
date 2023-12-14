#include "shell.h"

/**
 * get_path - Retrieves the value of the PATH variable from the environment.
 * @env: Local environment.
 * Return: Value of PATH variable (NULL if not found or on failure).
 */
char *get_path(char **env)
{
    char *path_prefix = "PATH=";
    char *path = NULL;

    size_t index;
    for (index = 0; env[index] && _strncmp(env[index], path_prefix, _strlen(path_prefix)); index++)
        ;

    if (env[index] == NULL)
        return NULL;

    char *path_value = env[index] + _strlen(path_prefix);

    path = duplicate_string(path_value);

    return path;
}

/**
 * duplicate_string - Duplicates a string and returns the new copy.
 * @str: The string to duplicate.
 * Return: A pointer to the duplicated string (NULL on failure).
 */
char *duplicate_string(const char *str)
{
    if (str == NULL)
        return NULL;

    char *duplicate = malloc(_strlen(str) + 1);
    if (duplicate == NULL)
        return NULL;

    _strcpy(duplicate, str);

    return duplicate;
}

