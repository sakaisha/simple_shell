#include "main.h"

int main(void) {
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    char before[] = "Before execve\n";
    write(1, before, sizeof(before) - 1);

    pid_t pid = fork();

    if (pid == -1) {
        handle_fork_error();
    } else if (pid == 0) { // Child process
        if (execve(argv[0], argv, NULL) == -1) {
            handle_execve_error(argv[0]);
        }
    } else { // Parent process
        waitpid(pid, NULL, 0);
    }

    char after[] = "After execve\n";
    write(1, after, sizeof(after) - 1);

    return 0;
}
