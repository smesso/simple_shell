#include "shell.h"

/**
 * exit_shell - Exits the shell with the specified exit status.
 * @arg: Pointer to the arguments.
 * @lineptr: Pointer to the input string.
 * @_exit: Exit status.
 */
void exit_shell(char **arg, char *lineptr, int _exit)
{
	int exit_status = 0;

	if (!arg[1])
	{
		free(lineptr);
		free(arg);
		exit(_exit);
	}

	exit_status = atoi(arg[1]);

	free(lineptr);
	free(arg);
	exit(exit_status);
}

/**
 * print_environment - Prints all environment variables.
 * @env: Array of environment variables.
 */
void print_environment(char **env)
{
	size_t run = 0;

	while (env[run])
	{
		write(STDOUT_FILENO, env[run], _strlen(env[run]));
		write(STDOUT_FILENO, "\n", 1);
		run++;
	}
}

