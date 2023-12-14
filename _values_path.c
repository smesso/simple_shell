#include "shell.h"

/**
 * _values_path - Separate the path into new strings.
 * @arg: Command input of the user.
 * @env: Environment.
 * Return: A pointer to the modified argument or NULL on failure.
 */
size_t _values_path(char **arg, char **env)
{
    char *token = NULL, *path_rela = NULL, *path_absol = NULL;
    size_t value_path, command;
    struct stat stat_lineptr;

    if (stat(*arg, &stat_lineptr) == 0)
        return 0; // File exists, no modification needed

    path_rela = _get_path(env);
    if (!path_rela)
        return 0; // Path retrieval failure

    token = _strtok(path_rela, ":");
    command = _strlen(*arg);

    while (token)
    {
        value_path = _strlen(token);
        path_absol = malloc(sizeof(char) * (value_path + command + 2));

        if (!path_absol)
        {
            free(path_rela);
            return 0; // Memory allocation failure
        }

        // Construct the absolute path
        _strcpy(path_absol, token);
        _strcat(path_absol, "/");
        _strcat(path_absol, *arg);

        if (stat(path_absol, &stat_lineptr) == 0)
        {
            // File found in the current path, update the argument
            *arg = path_absol;
            free(path_rela);
            return 1; // Success
        }

        free(path_absol);
        token = _strtok(NULL, ":");
    }

    free(path_rela);
    return 0; // File not found in any path
}

