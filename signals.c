#include "main.h"

void handle_sigint(int signum) {
    write(1, "\nReceived SIGINT (Ctrl+C)\n> ", 29);
    fflush(stdout);
}

void setup_signal_handlers() {
    if (signal(SIGINT, handle_sigint) == SIG_ERR) {
        perror("Error setting up SIGINT handler");
        exit(EXIT_FAILURE);
    }
}
