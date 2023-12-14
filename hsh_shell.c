#include "shell.h"

int main(int ac, char **av, char **env)
{
    int pathValue = 0, status = 0, is_path = 0;
    char *line = NULL, **commands = NULL;
    (void)ac;

    while (1)
    {
        errno = 0;
        line = _getline_command();

        if (line == NULL && errno == 0)
            return (0);

        if (line)
        {
            pathValue++;
            commands = tokenize(line);

            if (!commands)
            {
                free(line);
                continue;
            }

            if (_strcmp(commands[0], "env") == 0)
            {
                _getenv(env);
            }
            else
            {
                is_path = _values_path(&commands[0], env);
                status = _fork_fun(commands, av, env, line, pathValue, is_path);

                if (status == 200)
                {
                    free(line);
                    free(commands);
                    return (0);
                }

                if (is_path == 0)
                    free(commands[0]);
            }

            free(commands);
        }
        else
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);

            exit(status);
        }

        free(line);
    }

    return (status);
}

