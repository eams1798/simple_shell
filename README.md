<p align="center">
<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcTLtL_ToHLEo_BWFxD-yf32Ux3zfsH_NPc8Qw&usqp=CAU" width="225" height="175">

# Simple Shell Project - Command Interpreter

## Background
This is a collaboration project of two [Holberton School](https://www.holbertonschool.com/) students from Cohort 15 PER-0621, Lima Perú

## Description

This project is about to create an own simple shell as a command interpreter for a Linux operating system and should works without any memory leaks 
and have used System Calls only when is needed.

## Files

* [README.md](https://github.com/estefanomisme/simple_shell/blob/main/README.md)
This file

* [man_1_simple_shell](https://github.com/estefanomisme/simple_shell/blob/main/man_1_simple_shell)
man file of this Project program

* [README.md](https://github.com/estefanomisme/simple_shell/blob/main/AUTHORS)
Authors of this Project program

* [new_shell.h](https://github.com/estefanomisme/simple_shell/blob/main/new_shell.h)
Where prototypes and global variables are stored.

* [main.c](https://github.com/estefanomisme/simple_shell/blob/main/main.c)
Main file where receive the input and call functions to process data

* [match_sys.c](https://github.com/estefanomisme/simple_shell/blob/main/match_sys.c)
Code of the following functions: match_sys, execcmd, take_command

* [mainfunctions.c](https://github.com/estefanomisme/simple_shell/blob/main/mainfunctions.c)
Code of the following functions: _strok_all, tokalloc, cure_buffer, first_space and only_one_space

* [mainfunctions2.c](https://github.com/estefanomisme/simple_shell/blob/main/mainfunctions2.c)
Code of the following functions: free_vars, file_exit, err_invarg

* [environmatch.c](https://github.com/estefanomisme/simple_shell/blob/main/environmatch.c)
Code of the following functions: getenv_PATH, add_backslash, get_PATHS, execcmd and match_sys


## Diagram
<img src="https://www.inmobiliares.com/external/project_simple_shell.jpg">


## Compiling Requirements
All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89 and should 
compile all c files on this repository


## Executing program

```
Just execute ./hsh on command line.
```

## Examples
### No interactive

input:

root@9eda536ae174:~/shell/simple_shell/simple_shell# echo "qwerty" | ./hsh

output:

error: command not found

input:

root@9eda536ae174:~/shell/simple_shell/simple_shell# echo "pwd" | ./hsh

output:

/root/shell/simple_shell/simple_shell

### Interactive

input:

root@9eda536ae174:~/shell/simple_shell/simple_shell# ./hsh <br>
$ qwerty

output:

error: command not found

input:

root@9eda536ae174:~/shell/simple_shell/simple_shell# ./hsh <br>
$ pwd

output:

/root/shell/simple_shell/simple_shell


<!-- LICENSE -->
## License
Distributed under the Holberton School License.

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch
3. Commit your Changes
4. Push to the Branch
5. Open a Pull Request

## Authors

* Estéfano Misme (https://github.com/estefanomisme)
* Sammy Sam (https://github.com/sammysamp)

