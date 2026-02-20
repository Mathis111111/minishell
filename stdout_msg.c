/*
** EPITECH PROJECT, 2026
** project template
** File description:
** template
*/

#include "include/my.h"

void stdout_msg(char *msg, char *str)
{
    my_putstr(msg);
    write(1, ": ", 2);
    if (str != NULL) {
        my_putstr(str);
        write(1, ": No such file or directory\n", 28);
    } else
        write(1, "No such file or directory.\n", 27);
}

void stdout_msg2(char *str)
{
    my_putstr(str);
    write(1, ": ", 2);
    write(1, "Too many arguments.\n", 20);
}

void stdout_msg3(char *str, char *path, char **env)
{
    my_putstr(str);
    write(1, ": ", 2);
    write(1, "Command not found.\n", 19);
    free_path_and_env(env, path);
    exit(1);
}

void stdout_msg4(char *str)
{
    my_putstr(str);
    write(1, ": ", 2);
    write(1, "Too few arguments.\n", 19);
}

void stdout_msg5(char *str)
{
    my_putstr(str);
    write(1, ": ", 2);
    write(1, "Not a directory.\n", 17);
}
