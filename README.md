# :shell: Simple Shell :shell:

## Description :teacher:

* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?

## Flowchart :rowboat: :bar_chart:
![Flowchart of simple shell](https://user-images.githubusercontent.com/103126719/183076997-63175c7e-a122-4e98-bfc1-3ac16b5288e2.png)
### :computer_mouse: CLICK ME  |  (https://miro.com/app/board/uXjVP-i0iRk=/)


### Functions and system calls used  :desktop_computer: :floppy_disk: :calling:
- `execve`
- `exit`  
- `fork`  
- `free`  
- `getline`   
- `isatty`    
- `open`  
- `perror`
- `stat` 
- `strcat` 
- `strchr` 
- `strcmp` 
- `strdup` 
- `strtok` 
- `va_arg` 
- `va_end`  
- `va_start` 
- `wait`  

### Compilation and usage example :wrench: :card_file_box:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
 ./hsh - example fix

## Files :file_folder: :open_file_folder:
- **`AUTHORS`** : List of contributors  
- **`man_1_simple_shell`** : Manual page of the simple shell  
- **`main.c`** : Function that contains the main code; coordinates the execution of programs and alternate between interactive and non-interactive shell modes
- **`main.h`** : Header file
- **`builtin_checker.c`** : Builtin checker file
- **`commandPATH.c`** : File that handles the PATH
- **`fordandReplace.c~** : File that forks
- **`getend.c`** : getenv file
- **`helperfunc1.c`** : helper functions file
- **`read.c~** : read file
- **`tokenizer.c`** : Tokenizer file



## Resources  :technologist:

Wiki  |  (https://en.wikipedia.org/wiki/Unix_shell)

Wiki  |  (https://en.wikipedia.org/wiki/Thompson_shell)

Wiki  |  (https://en.wikipedia.org/wiki/Ken_Thompson)

Medium  |  (https://towardsdev.com/unix-shell-command-line-interpreter-in-a-nutshell-6bc91466a83f)


### Authors :memo::pencil:
 
Clint Hendrickson | (https://github.com/Maitreya-today)

Mason Counts  |  (https://github.com/spindouken)

