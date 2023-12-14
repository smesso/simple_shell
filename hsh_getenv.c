#include "shell.h"

/**
 * _getenv - prints environment variables to standard output
 *
 * @env: environment variables
 *
 */

void _getenv(char **env)
{
	size_t i = 0;

	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

