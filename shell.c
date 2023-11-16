#include "shell.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void display_prompt(void) {
    printf("#cisfun$ ");
}

char *read_input(void) {
    char *input = NULL;
    size_t bufsize = 0;

    if (getline(&input, &bufsize, stdin) == -1) {
        if (feof(stdin)) {
            printf("\n");
            exit(EXIT_SUCCESS);
        } else {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }

    return input;
}

void execute_command(char *command) {
    pid_t child_pid;
    int status;

    char *args[2];
    args[0] = command;
    args[1] = NULL;

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {  /* Child process */
        if (execve(command, args, NULL) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {  /* Parent process */
        waitpid(child_pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "./shell: No such file or directory\n");
        }
    }
}

int main(void) {
    char *command;

    while (1) {
        display_prompt();
        command = read_input();
        execute_command(command);
        free(command);
    }

    return 0;
}
