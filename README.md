# Simple Shell Project

## Overview

This is the Simple Shell project, a Unix command interpreter developed by Aisha Sakkary as a solo project for ALX School. The project is scheduled to start on October 4, 2023, and must be completed by October 19, 2023. The checker will be released on October 18, 2023, at 1:12 AM.

## Project Description

The goal of the project is to create a simple UNIX command interpreter. This project is expected to challenge Aisha in various aspects, including the basics of programming, C language, engineering thinking, and the ability to learn independently.

## Concepts to Explore

To successfully complete the project, Aisha is expected to understand and apply various concepts, including:

- Basics of programming
- Basics of C
- Basics of thinking like an engineer
- Learning how to learn

## Learning Objectives

Upon completion of the project, Aisha should be able to explain various concepts without relying on Google, including:

- Design and implementation of the original Unix operating system
- Author of the first version of the UNIX shell
- Inventor of the B programming language (predecessor to C)
- Understanding of how a shell works
- Knowledge of pid and ppid
- Environment manipulation in the current process
- Difference between a function and a system call
- Creation of processes
- Understanding the three prototypes of the main function
- Utilization of the PATH to find programs
- Execution of another program with the execve system call
- Suspension of process execution until a child terminates
- Understanding of EOF ("end-of-file")

## Project Requirements

### General

- Allowed editors: vi, vim, emacs
- Compilation on Ubuntu 20.04 LTS using gcc with specific options
- Code should adhere to the Betty style
- No memory leaks
- No more than 5 functions per file
- Header files should be include guarded
- Use system calls only when necessary

### README Guidelines

- A README.md file at the root of the project folder is mandatory
- The README should provide a description of the project

### GitHub

- One project repository

## Tasks

1. **Betty would be proud**
   - Write code that passes the Betty checks.

2. **Simple shell 0.1**
   - Write a UNIX command line interpreter.

3. **Simple shell 0.2**
   - Handle command lines with arguments.

4. **Simple shell 0.3**
   - Handle the PATH.
   - Do not call fork if the command doesn't exist.

5. **Simple shell 0.4**
   - Implement the exit built-in.

6. **Simple shell 1.0**
   - Implement the env built-in to print the current environment.

7. **Simple shell 0.1.1**
   - Write a custom getline function using a buffer to read characters.

8. **Simple shell 0.2.1**
   - Do not use strtok.

9. **Simple shell 0.4.1**
   - Handle arguments for the built-in exit.

10. **setenv, unsetenv**
    - Implement setenv and unsetenv built-in commands.

11. **cd**
    - Implement the cd built-in command.

12. **;**
    - Handle the commands separator (;).

13. **&& and ||**
    - Handle the && and || logical operators.

14. **alias**
    - Implement the alias built-in command.

15. **Variables**
    - Handle variables replacement, including $? and $$.

16. **Comments**
    - Handle comments (#).

17. **File as input**
    - Allow the shell to take a file as a command line argument.

## Compilation and Testing

- Compile the shell using the following command:
  ```
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
  ```
- Testing can be performed in both interactive and non-interactive modes.


