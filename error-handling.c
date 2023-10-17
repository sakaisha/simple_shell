#include "main.h"
#include <unistd.h>

void print_not_found_error(char *program, char *cmd, int count) {
char count_char = count + '0';

write(2, program, custom_strlen(program));
write(2, ": ", 2);
write(2, &count_char, 1);
write(2, ": ", 2);
write(2, cmd, custom_strlen(cmd));
write(2, ": not found\n", 12);
}

void print_permission_error(char *program, char *cmd, int count) {
char count_char = count + '0';

write(2, program, custom_strlen(program));
write(2, ": ", 2);
write(2, &count_char, 1);
write(2, ": ", 2);
write(2, cmd, custom_strlen(cmd));
write(2, ": permission denied\n", 20);
}


int _strlen(char *str) {
int len = 0;
while (str[len] != '\0') {
len++;
}
return len;
}

int _putchar(char c) {
return write(2, &c, 1);
}
