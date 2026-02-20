/*
** EPITECH PROJECT, 2026
** project mini_shell
** File description:
** mini_shell
*/

#include "include/my.h"

int error_handling(int argc, char **argv)
{
    if (argc != 1 || argv[1] != NULL)
        exit(0);
    return 0;
}
