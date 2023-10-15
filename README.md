
# Simple Shell Collaboration Project

 README

## Overview

Welcome to our shell collaboration project! This README will guide you through the project and help you get started with contributing. This project aims to create a custom implementation of the Shell Terminal in C, which is a fundamental function for Command line interface.

### Table of Contents

- Getting Started
- Project Structure
- Contribution Guidelines
- Coding Standards
- Testing
- Documentation

## Authors

- [@Okoye Emmanuel Obiajulu](https://github.com/Obiajulu-gif/)
- [@Timilehin Kudaisi](https://github.com/Kudatee007/)

## Tech Stack

- **language:** C language
- **Command line:** bash


## ABOUT
### Simple Shell
This project is a simple implementation of a UNIX command interpreter in C. It can execute commands read from the standard input or from a file.
Getting StartedTo use this shell, you need to clone this repository and compile the source files. You can do this by running the following commands in your terminal:

git clone ** <https://github.com/Kudatee007/simple_shell.git>**
cd simple_shell
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

This will create an executable file called hsh in the current directory. You can then run the shell by typing ./hsh and pressing enter. You should see a prompt like this:

$

You can now type any command that you want to execute, followed by any arguments, and press enter. The shell will try to find and run the command, and print the output to the standard output. For example:

$ ls -l
total 64
-rw-rw-r-- 1 vagrant vagrant   157 Oct 15 11:10 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  1465 Oct 15 11:10 README.md
-rwxrwxr-x 1 vagrant vagrant 13992 Oct 15 11:10 hsh
-rw-rw-r-- 1 vagrant vagrant   929 Oct 15 11:10 main.c
-rw-rw-r-- 1 vagrant vagrant   614 Oct 15 11:10 shell.h
-rw-rw-r-- 1 vagrant vagrant   980 Oct 15 11:10 shell_builtins.c
-rw-rw-r-- 1 vagrant vagrant   861 Oct 15 11:10 shell_execute.c
-rw-rw-r-- 1 vagrant vagrant   784 Oct 15 11:10 shell_parse.c
-rw-rw-r-- 1 vagrant vagrant   538 Oct 15 11:10 shell_path.c
-rw-rw-r-- 1 vagrant vagrant   402 Oct 15 11:10 shell_prompt.c

To exit the shell, you can type exit and press enter, or press Ctrl-D at the prompt.
Project StructureThe project consists of several source files written in C. The main file is main.c, which contains the main function that initializes and runs the shell loop. The other files are:

- shell.h: This is the header file that contains all the function prototypes, macros, and data structures used by the shell.
- shell_builtins.c: This file contains the functions that implement the builtin commands of the shell, such as cd, env, exit, etc.
- shell_execute.c: This file contains the function that executes a given command by either calling a builtin function or launching a new process.
- shell_parse.c: This file contains the function that parses a line of input into an array of tokens (command and arguments).
- shell_path.c: This file contains the function that searches for a command in the PATH environment variable and returns the full path if found.
- shell_prompt.c: This file contains the function that prints the prompt to the standard output.
Contribution GuidelinesIf you want to contribute to this project, please follow these guidelines:
- Fork this repository and create a new branch for your feature or bug fix.
- Write clear and descriptive commit messages and comments for your code.
- Follow the coding standards described below.
- Test your code thoroughly before pushing it to your branch.
- Create a pull request with a detailed description of your changes and why they are needed.
- Wait for feedback from the project maintainers and make any necessary changes.
Coding StandardsThe coding standards for this project are based on the Betty style and documentation guidelines. You can use the Betty linter to check your code for compliance. Some of the main rules are:
- Use four spaces for indentation, not tabs.
- Use one space around operators and after commas and semicolons.
- Do not leave trailing spaces at the end of lines or files.
- Use braces for all control structures, even if they have only one statement.
- Write short and simple functions (no more than 40 lines).
- Write short and simple lines (no more than 80 characters).
- Use descriptive variable names and avoid abbreviations.
- Use comments to explain your code, but do not overcomment.
- Use proper spelling and grammar in your comments and documentation.
TestingTo test the functionality and memory leaks of the shell, you can use the following tools:
- Shellcheck: This is a static analysis tool that can detect syntax errors, bugs, and bad practices in shell scripts. You can use it to check the scripts that you use to test the shell.
- Valgrind: This is a dynamic analysis tool that can detect memory leaks, memory errors, and other issues in C programs. You can use it to check the memory usage of the shell.
- Holberton's tests: This is a repository that contains a collection of tests for the simple shell project. You can use it to check the output and behavior of the shell.
DocumentationThe documentation for this project is generated using Doxygen. You can find the HTML version of the documentation in the docs directory. To generate the documentation, you need to install Doxygen and run the following command in the root directory of the project:



## Contributing

Contributions are always welcome!

See `contributing.md` for ways to get started.

Please adhere to this project's `code of conduct`.

