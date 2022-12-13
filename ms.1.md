% MS(1) ms 1.0.3
% Mason Counts /// Clint Hendrickson
% December 2022

# NAME
hsh - command interpreter (shell)

# DESCRIPTION
hsh is a copy of the standard command interpreter for the system. This project is made for learning purposes. Made by Holberton School.

# SYNOPSIS
**ms** {*OPTION*}
**ms** *PATTERN*

# OPTIONS
Overview
The shell is a command that reads lines from either a file or the terminal, interprets them, and generally executes other commands. Has an non-interactive mode, commands can be typed directly to the running shell or can be put into a file and the file can be executed directly by the shell.

# EXAMPLES
To activate interactive mode write "./hsh". The prompt will be displayed. There, you can write commands and will be executed by the simple shell.
EXAMPLES: "/bin/ls" or "pwd"
To activate non-interactive mode write "echo (command to be executed) | ./hsh". 
EXAMPLES: "echo "Hello!" | ./hsh" or "echo "ls -ltr | ./hsh"

# AUTHORS

Mason Counts  |  (https://github.com/spindouken)

Clint Hendrickson  |  (https://github.com/Maitreya-today)

December 2022
