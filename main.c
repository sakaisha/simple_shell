#include "main.h"

int main(int argc, char *argv[]) {
char *command = NULL;
size_t len = 0;
ssize_t read_bytes;

setup_signal_handlers();

while (1) {
write(1, "> ", 2);

command = (char *)malloc(BUFF_SIZE);
if (command == NULL) {
handle_malloc_error();
}

read_bytes = getline(&command, &len, stdin);

if (read_bytes == 0) {
free(command);
break;
}

if (read_bytes == -1) {
if (feof(stdin)) {
free(command);
break;
} else if (ferror(stdin)) {
handle_getline_error();
free(command);
continue;
}
}

if (command[read_bytes - 1] == '\n') {
command[read_bytes - 1] = '\0';
}

if (strcmp(command, "exit") == 0) {
free(command);
break;
}

pid_t pid = fork();

if (pid == -1) {
handle_fork_error();
} else if (pid == 0) { 
executeCommand(command);
free(command);
_exit(EXIT_SUCCESS);
} else { 
wait(NULL);
}

if (!is_valid_command(command)) {
handle_command_not_found(command);
}

free(command);
}

return 0;
}
