# pipex_1337cursus
This project will let you discover in detail the UNIX processes, and how it mechanism works.
<br>
<br>
The main idea is to build a program that does the same behavior of a pipe (|) which is letting you execute more than one command at the same time, by creating a child process from the main process with the function `fork()` and execute all the processes at the same time.
<br>
<br>
**FILES USED**
<br>
**`ft_split()`** :  *if the user pass an argument (command) as the following exemple : `ls -l` we have to split the argument he passed by a space by the `ft_split()` functions which takes two arguments; the string we want to split, and the separator we want to split with. and it returns a splitted `**string`.*
<br>
