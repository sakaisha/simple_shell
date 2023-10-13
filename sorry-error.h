#ifndef SORRY_ERROR_H
#define SORRY_ERROR_H

void handle_malloc_error(void);
void handle_getline_error(void);
void handle_fork_error(void);
void handle_execve_error(const char *command);
void handle_access_error(const char *command);
void handle_waitpid_error(void);

#endif /* SORRY_ERROR_H */
