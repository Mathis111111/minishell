/*
** EPITECH PROJECT, 2026
** project mini_shell
** File description:
** mini_shell
*/

#include "include/my.h"

int exit_and_ctrl_d(int x, char **array, char *buffer)
{
    int r = 0;

    if (x == -1) {
        free(buffer);
        exit(0);
    }
    if (my_strcmp(array[0], "exit") == 0) {
        if (array[1] != NULL && array[2] == NULL) {
            r = my_getnbr(array[1]);
            exit(r);
        }
        exit(0);
    }
    return 0;
}
