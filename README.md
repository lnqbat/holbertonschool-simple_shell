# <center>**Holbertonschool_Simple_SHELL**</center>
[![holberton School](https://github.com/lnqbat/holbertonschool-simple_shell/blob/dev/Image/Holberton.png)](https://www.holbertonschool.fr/)

## <ins>Overview
- [Project_Simple_SHELL](#project_simple_shell)
    - [Description](#-description)
    - [Features](#-features)
    - [Technology](#️-technology)
    - [Structure_project](#-structure_project)
- [How_to_Compile](#-how_to_compile)
    - [How_to_Use](#-how_to_use)
- [Requirements](#-requirements)
- [Cod_Snipet](#-cod_snipet)
- [Exemples](#-exemples)
- [Testing_Method](#-testing_method)
    - [Test_Valgrind](#-test_valgrind)
- [Man_SHELL](#-man_shell)
- [Flowchart](#--flowchart)
- [Authors](#-authors)
## <ins>Project_Simple_SHELL:
### 🧠 Description:
This project is an implementation of a minimalist shell for UNIX-like systems. It is a simple command-line interpreter, capable of reading user input, parsing it, and executing the requested commands. Like traditional shells such as bash or sh, this mini-shell provides a command-line interface, although its features are intentionally limited within the scope of this project.
### 🚀 Features:
- Display a prompt and wait for user input
- Parse and execute basic shell commands (`ls`, `pwd`, `echo`, etc.)
- Built-in commands: `exit`, `env`, `help`
- Execution of programs in /bin/ (`/bin/ls`)
- Handling command paths via `PATH`
- Fork and execute commands via `execve`
- Environment variable access
### 💻⚙️ Technology:
![](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&>logoColor=white) 
![](https://img.shields.io/badge/VIM-%2311AB00.svg?&style=for-the-badge&logo=vim&logoColor=white)
![](https://img.shields.io/badge/Slack-4A154B?style=for-the-badge&logo=slack&logoColor=white)
![](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)

### 📁 Structure_project:
|                                       Files Name                                                                 |                     Fonctionnality                      |
| :---------                                                                                                       |:-------------                                           |
|[`[shell.h]`](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/shell.h)                           |The header file containing function prototypes           |
|[`[_getenv.c]`](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/_getenv.c)                       |The function searches for the environment string         |
|[`[utils.c]`](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/utils.c)                           |The function that `free`,`exit`,`env_builtin` and `_atoi`|
|[`[tokenize.c]`](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/tokenize.c)                     |Split a command line into tokens                         |
|[`[main.c]`](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/main.c)                             |Entry point of the shell                                 |
|[`[prompt.c]`](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/prompt.c)                         |Print and read a prompt                                  |
|[`[exec.c]`](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/exec.c)                             |Execute command in prompt                                |
|[`[path.c]`](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/path.c)                             |Search the full path of (shell) commands                 |
|[`[man_1_simple_shell.1]`](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/man_1_simple_shell.1) |The man page SHELL                                       |
|[`[struct_builtin.c]`](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/struct_builtin.c)         |Use for command pass if it is a built-in                 |
|[`[help.c]`](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/help.c)                             |The help function command                                |

## 💾 <ins>How_to_Compile:
For the shell it will be compiled like this below and all the files above:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
### 💻 How_to_Use:
1. Compile the program (as shown above)
2. Run the shell (shown below.):
```
./hsh
```
3. You'll see a prompt. Type commands like:
```
$ ls
$ pwd
$ echo "Hello, world"
$ exit
```
## ✅ <ins>Requirements:
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
## 📝 <ins>Code_Snippet:
Below you will find code snippets:

![main](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/images/main_update.png)

![_which](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/images/screen_which.png)
## 🔄 <ins>Examples:
```
$CISFUN ls
AUTHORS  _getenv.c  images  man_shell.1  prompt.c   shell.h     utils.c
exec.c   hsh        main.c  path.c       README.md  tokenize.c
$ echo "pwd" | ./hsh
/root/holbertonschool-simple_shell
```
## 🧪 <ins>Testing_Method:
Mode intéractive:
```
$CISFUN /bin/pwd
/root/holbertonschool-simple_shell
$CISFUN which pwd
/usr/bin/pwd
$CISFUN exit
$ echo $?
0
$CISFUN env
SHELL=/bin/bash
COLORTERM=truecolor
TERM_PROGRAM_VERSION=1.99.1
HOSTNAME=10b5af25495b
...
```
Mode non-intéractive:
```
$ cat script.txt
    echo Testing shell
    ls
    exit 98

$ ./hsh < script.txt
    Testing shell
    simple_shell  main.c  README.md

$ echo $?
    98 
```
### 💨 Test_Valgrind:
Below is a memory leak test:

![VALGRIND](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/images/valgind_shell.png)
## 📚 <ins>Man_SHELL:
For read and exectue man page SHELL in Terminal use the command below:
```
man ./man_1_simple_shell.1
```
- For read man_1_simple_shell is: [Here](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/man_1_simple_shell.1)
- For Output is: [Here](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/images/man_page_update.png)
## 📈 <ins> Flowchart:
Below is the flowchart for the `Simple SHELL`:

![Flowchart](https://github.com/lnqbat/holbertonschool-simple_shell/blob/main/images/flowchart_shell.jpg)
## 🧑‍💻 <ins>Authors:
[Jeffrey BASSET](https://github.com/JeffToken31) / [linkedin](https://www.linkedin.com/in/jeffrey-basset/)

[Baptiste Lonqueu](https://github.com/lnqbat) / [linkedin](https://www.linkedin.com/in/baptiste-lonqueu-9a9b79202/)