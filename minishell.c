/*
** EPITECH PROJECT, 2026
** project template
** File description:
** template
*/

#include "include/my.h"

int minishell(char **array, header_t *begin, cd_tiret_t *cd)
{
    if (my_strcmp(array[0], "cd") == 0) {
        cd_functions(array, begin, cd);
        return 0;
    }
    if (my_strcmp(array[0], "env") == 0 || my_strcmp(array[0], "setenv"
        ) == 0 || my_strcmp(array[0], "unsetenv") == 0) {
        env_functions(array, begin);
        return 0;
    }
    command_exec(array, begin);
    return 0;
}
