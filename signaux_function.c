/*
** EPITECH PROJECT, 2026
** project mini_shell
** File description:
** mini_shell
*/

#include "include/my.h"

void ctrl_c(int signal)
{
    (void)signal;
    write(1, "\n$> ", 4);
}

void segfault(int signal)
{
    (void)signal;
    write(1, "Segmentation fault !\n", 21);
    exit(0);
}

int signaux_function(void)
{
    signal(SIGSEGV, segfault);
    signal(SIGINT, ctrl_c);;
    return 0;
}
