#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt(void) {
    write(STDOUT_FILENO, "($)\n", 4);
}

void shell_exit(void) {
    exit(0);
}

void shell_env(void) {
    extern char **environ;
    int i;
    for (i = 0; environ[i] != NULL; i++) {
        size_t len = strlen(environ[i]);
        write(STDOUT_FILENO, environ[i], len);
        write(STDOUT_FILENO, "\n", 1);
    }
}

void execute_command(const char *command) {
    if (strcmp(command, "exit") == 0) {
        shell_exit();
    } else if (strcmp(command, "env") == 0) {
        shell_env();
    } else {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Error");
            exit(errno);
        } else if (pid == 0) {
            /* Child process */
            char *cmd_args[] = {(char *)command, NULL};
            execve(command, cmd_args, NULL);
            perror(command);
            exit(errno);
        } else {
            /* Parent process */
            waitpid(pid, NULL, 0);
        }
    }
}

