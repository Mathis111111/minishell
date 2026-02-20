/*
** EPITECH PROJECT, 2026
** project mini_shell
** File description:
** mini_shell
*/

#include "include/my.h"

int free_function(char **array, char *buffer, cd_tiret_t *cd)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    free(buffer);
    free(cd);
    return 0;
}
