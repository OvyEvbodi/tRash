## tRash

***
***
#### Description
The TRagically Awesome SHell--**tRash** is a command line interpreter wholly written by Ovy Evbodi and Chee-zaram Okeke based off the **sh** shell. It reads and executes commands from the standard input or the terminal by default, or from a file specified as a command line argument to the shell.
**tRash** is capable of running any valid executable with options within a machine. If the absolute path to a particular file with execute permission(s) is not specified, tRash searches all directories in the **$PATH** available to it to find a valid absolute path to the command, except in the case where the command is a <a href="#built-ins">built-in</a>, then it is handled immediately and **execve** is not called.<br>

#### Use environment
It is to be used within the **GNU/Linux** terminal.

##### Getting started with tRash
* Clone this repository `git clone https://github.com/OvyEvbodi/tRash`.
* Using the `cd` command, navigate to your local **tRash** repository.
* On bash, you can run this [shell_creation](https://github.com/OvyEvbodi/simple_shell/blob/master/make_tRash.sh) script from within the directory. Optionally, use the `make tRash` command to run the [makefile](https://github.com/OvyEvbodi/simple_shell/blob/master/makefile).
> Note: The [make_tRash.sh](https://github.com/OvyEvbodi/simple_shell/blob/master/make_tRash.sh) and [makefile](https://github.com/OvyEvbodi/simple_shell/blob/master/makefile) scripts are intended to work for Ubuntu and Debian-based distro users. Other users may setup **tRash** manually, in conformity to the syntax and nuances of their operating system.<br>
> It is a one-time setup, and need not be run at multiple instances.

#### Usage and Invocation
**tRash** can be invoked interactively or non-interactively.
In interactive mode, it is invoked by calling its name in the current directory - ***./tRash***, or **tRash** if the executable has been added to a directory present in **$PATH**. A prompt is displayed and the user enters in commands from the terminal, ending with a new line or an **EOF**.
In non-interactive mode, another shell could read and execute commands, and the output is piped into the input stream of the TRagically Awesome SHell. The shell exits after all the commands piped into it have been executed. Commands could also be contained in a file with read permission, provided as a command line argument to the program. If more than one argument is provided, the first one is assumed to be the file with the commands to be executed, separated by a new line or semi-colon, and ending with an **EOF**.

***
***
###### Multiple Commands
The semi-colon(;) is used to seperate commands within **tRash**. Each command is ended with a semi-colon, and the succeeding command(s) follows.
###### Comments
Comments are started with a hash symbol(#). Any data that follows the '#' is ignored only if the hash symbol follows a non-printable character, otherwise the symbol loses its special meaning. All data that succeed a valid '#' are treated as command line comments and therefore are not processed.
<a id="built-in"></a>
###### Built-ins
These provide some extra flexibilty.

Built-in  |  Details
:--: | :--
'cd [directory]'  | Changes the users current working directory and updates **$PWD** and **$OLDPWD**.
'exit [status]'  | Exits the current instance of the shell process.
'env'  | Prints a list of the currently set environment variables available to the shell.
'setenv NAME value'  | Sets a new environment variable for the current shell process and sub processes, with NAME and value in the format ***NAME=value***.
'unsetenv NAME'  | Removes an environment variable whose name matches NAME from the list of environment variables available to the shell.

###### Exit Status
Code | Meaning
:--: | :--
'0'  | For success.
'1'  | Usage, syntax, or processing errors.

#### AUTHORS

[**Chee-zaram Okeke**](https://github.com/chee-zaram)

[**Ovy Evbodi**](https://github.com/OvyEvbodi)
<br><br>

