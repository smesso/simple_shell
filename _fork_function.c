#include "shell.h"

/**
 * execute_command - Executes a command using fork and execve.
 * @arg: Array of command and arguments.
 * @av: Array containing the program name.
 * @env: Array of environment variables.
 * @lineptr: Pointer to the command line string.
 * @np: Process ID.
 * @c: Checker flag for additional tests.
 * Return: Exit status of the child process.
 */
int execute_command(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
	pid_t child;
	int status;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}

	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		waitpid(child, &status, 0);

		if (WIFEXITED(status))
			return WEXITSTATUS(status);
	}

	return EXIT_SUCCESS;
}

