#include <unistd.h>

int main(int argc, char *argv[], char *env[])
{
    char address_env[] = "Address of env: ";
    write(1, address_env, sizeof(address_env) - 1);

    char buf[1024];
    int len = 0;

    len += _itoa((int)env, buf + len);
    buf[len++] = '\n';
    write(1, buf, len);

    char address_environ[] = "Address of environ: ";
    write(1, address_environ, sizeof(address_environ) - 1);

    len = 0;
    len += _itoa((int)environ, buf + len);
    buf[len++] = '\n';
    write(1, buf, len);

    return 0;
}
