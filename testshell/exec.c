#include "main.h"

void _exec(data *d)
{
    const char prompt[] = PROMPT;

    signal(SIGINT, handler_sigint);

    while (1)
    {
        if (isatty(STDIN_FILENO))
            _printf(prompt);

        read_cmd(d);
        if (_strlen(d->cmd) != 0)
        {
            split(d, " ");
            if (!exec_builtin(d))
            {
                _which(d);
                if (access(d->av[0], F_OK) == -1)
                {
                    perror(d->shell_name);
                }
                else
                {
                    start_process(d);
                }
            }
            free_array(d->av);
        }
        free(d->cmd);
    }
}

