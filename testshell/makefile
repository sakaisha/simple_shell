CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = main.o error.o exec.o setenv-unsetenv.o split-strings.o getenv.o getenv_variables.o error_handling.o

hsh: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o hsh

%.o: %.c main.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o hsh

