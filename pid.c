#include <unistd.h>

void _itoa(int num, char* str) {
    int i = 0;
    while (num != 0) {
        str[i++] = '0' + num % 10;
        num /= 10;
    }

    if (i == 0) {
        str[i++] = '0';
    }

    str[i] = '\0';

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main(void) {
    pid_t my_pid, parent_pid;

    my_pid = getpid();
    parent_pid = getppid();

    char buf[1024];
    int len = 0;

    _itoa(my_pid, buf);
    len = strlen(buf);
    buf[len++] = '\n';
    write(1, buf, len);

    _itoa(parent_pid, buf);
    len = strlen(buf);
    buf[len++] = '\n';
    write(1, buf, len);

    return 0;
}
