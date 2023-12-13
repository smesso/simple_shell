#include "shell.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024

/**
 * main - Entry point for the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: Always 0.
 */
int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    char command[MAX_COMMAND_LENGTH];

    if (isatty(STDIN_FILENO))
    {
        while (1)
        {
            display_prompt();

            if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
            {
                write(STDOUT_FILENO, "\n", 1);
                break;
            }

            command[strcspn(command, "\n")] = '\0';

            if (strlen(command) == 0)
                continue;

            execute_command(command);
        }
    }
    else
    {
        while (fgets(command, MAX_COMMAND_LENGTH, stdin) != NULL)
        {
            command[strcspn(command, "\n")] = '\0';
            execute_command(command);
        }
    }

    return 0;
}

