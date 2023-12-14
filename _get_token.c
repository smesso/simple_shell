#include "shell.h"

char **get_tokens(char *lineptr)
{
	char **user_command = NULL;
	char *token = NULL;
	size_t i = 0;
	size_t size = 0;

	if (lineptr == NULL)
		return NULL;

	for (i = 0; lineptr[i]; i++)
	{
		if (lineptr[i] == ' ')
			size++;
	}

	if ((size + 1) == _strlen(lineptr))
		return NULL;

	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return NULL;

	token = _strtok(lineptr, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		user_command[i] = token;
		token = _strtok(NULL, " \n\t\r");
	}

	user_command[i] = NULL;
	return user_command;
}

