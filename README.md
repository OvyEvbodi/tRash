# TRagically Awesome SHell

[![License][license-badge]][license]
[![Contributors][contributors-badge]][contributors]

---

---

## Description

The TRagically Awesome SHell-- _tRash_ --is a command-line interpreter based off the `sh` shell.
It reads and executes commands from the standard input or the terminal by default,
or from a file specified as a command line argument to the shell.
`tRash` is capable of running any valid executable with options within a machine.
If the absolute path to a particular file with execute permission(s) is not specified,
`tRash` searches all directories in the `$PATH` available to it to find a valid
absolute path to the command, except in the case where the command is a <a href="#built-ins">built-in</a>,
then it is handled immediately and `execve` is not called.<br>

## Build and Installation

It can be built and run on any computer with C compiler, and accessed via a [terminal](https://ubuntu.com/tutorials/command-line-for-beginners).

### Installation

Dependencies include `make`, `gcc`, `gzip`, `mandb`. Ensure you have them installed.

- Clone this repository and navigate into the local `tRash/build/` directory

```shell
git clone https://github.com/OvyEvbodi/tRash/ tRash ;
cd tRash/build/ ;
```

- To build `tRash` and run it in the current directory, use the following command:

```shell
make
```

- For the complete installation, and to add `tRash` to a standard location and install
  the [manpage](https://en.wikipedia.org/wiki/Man_page), run:

```shell
make install
```

- To uninstall the `tRash` binary, run:

```shell
make uninstall
```

- For a complete clean of the `tRash` binary as well as all object files, run:

```shell
make clean
```

- For help, checkout the manpage:

```shell
man tRash
```

### Usage and Invocation

`tRash` can be invoked interactively or non-interactively.
In interactive mode, it is invoked by calling its name in the current directory:

```shell
./tRash
```

If the executable has been added to a directory present in `$PATH`, you could run:

```shell
tRash
```

A prompt is displayed and the user enters in commands from the terminal, ending with a new line or an `EOF`.
In non-interactive mode, another shell could read and execute commands, and the output
is piped into the input stream of the TRagically Awesome SHell.
The shell exits after all the commands piped into it have been executed.
Commands could also be contained in a file with read permission, provided as a command line argument to the program.
If more than one argument is provided, the first one is assumed to be the file
with the commands to be executed, separated by a new line or semi-colon, and ending with an `EOF`.

---

###### Multiple Commands

The semi-colon `;` is used to seperate commands on the command-line.
Each command is ended with a semi-colon, and the succeeding command(s) follows.

###### Comments

Comments are started with a hash symbol `#`. Any data that follows the `#` is ignored
only if the hash symbol follows a non-printable character, otherwise the symbol loses its special meaning.
All data that succeed a valid `#` are treated as command-line comments and therefore are not processed.
<a id="built-in"></a>

###### Built-ins

These provide some extra flexibilty.

|      Built-in       | Details                                                                                                                              |
| :-----------------: | :----------------------------------------------------------------------------------------------------------------------------------- |
|  `cd [directory]`   | Changes the users current working directory and updates `$PWD` and `$OLDPWD`.                                                        |
|   `exit [status]`   | Exits the current instance of the shell process.                                                                                     |
|        `env`        | Prints a list of the currently set environment variables available to the shell.                                                     |
| `setenv NAME VALUE` | Sets a new environment variable for the current shell process and sub processes, with _NAME_ and _VALUE_ in the format `NAME=VALUE`. |
|   `unsetenv NAME`   | Removes an environment variable whose name matches NAME from the list of environment variables available to the shell.               |

###### Exit Status

| Code  | Meaning                              |
| :---: | :----------------------------------- |
| **0** | For success.                         |
| **1** | Usage, syntax, or processing errors. |

### AUTHORS

[**Chee-zaram Okeke**](https://github.com/chee-zaram)

[**Ovy Evbodi**](https://github.com/OvyEvbodi)
<br><br>

### BUGS

To report bugs and make contributions or feature requests, [click here](https://github.com/OvyEvbodi/simple_shell/issues)

### NOTE

The original version of `tRash` was made for educational purposes and resticted function use to the following.
Every other function was created from scratch.

- List of allowed functions and system calls
  > access (man 2 access)
  > chdir (man 2 chdir)
  > close (man 2 close)
  > closedir (man 3 closedir)
  > execve (man 2 execve)
  > exit (man 3 exit)
  > \_exit (man 2 \_exit)
  > fflush (man 3 fflush)
  > fork (man 2 fork)
  > free (man 3 free)
  > getcwd (man 3 getcwd)
  > getline (man 3 getline)
  > getpid (man 2 getpid)
  > isatty (man 3 isatty)
  > kill (man 2 kill)
  > malloc (man 3 malloc)
  > open (man 2 open)
  > opendir (man 3 opendir)
  > perror (man 3 perror)
  > read (man 2 read)
  > readdir (man 3 readdir)
  > signal (man 2 signal)
  > stat (\_\_xstat) (man 2 stat)
  > lstat (\_\_lxstat) (man 2 lstat)
  > fstat (\_\_fxstat) (man 2 fstat)
  > strtok (man 3 strtok)
  > wait (man 2 wait)
  > waitpid (man 2 waitpid)
  > wait3 (man 2 wait3)
  > wait4 (man 2 wait4)
  > write (man 2 write)

[license-badge]: https://img.shields.io/github/license/chee-zaram/monty
[license]: https://github.com/OvyEvbodi/tRash/blob/master/LICENSE
[contributors-badge]: https://img.shields.io/github/contributors/OvyEvbodi/tRash
[contributors]: https://github.com/OvyEvbodi/simple_shell/graphs/contributors
