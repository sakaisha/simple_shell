#include <unistd.h>

int main(void)
{
    pid_t my_pid, parent_pid;

    my_pid = getpid();
    parent_pid = getppid();

    char buf[1024];
    int len = 0;

    len += _itoa(my_pid, buf + len);
    buf[len++] = '\n';
    write(1, buf, len);

    len = 0;
    len += _itoa(parent_pid, buf + len);
    buf[len++] = '\n';
    write(1, buf, len);

    return 0;
}
