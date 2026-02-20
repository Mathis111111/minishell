/*
** EPITECH PROJECT, 2026
** project mini_shell
** File description:
** mini_shell
*/

#include "include/my.h"

int main(int argc, char **argv, char **env)
{
    header_t *begin;
    char *buffer = NULL;
    char **array = NULL;
    size_t bufsize = 32;
    ssize_t x = 0;
    cd_tiret_t *cd = malloc(sizeof(cd_tiret_t));

    signaux_function();
    initialize_cd(cd);
    error_handling(argc, argv);
    begin = construct_env(env);
    while (1) {
        my_putstr("$> ");
        x = getline(&buffer, &bufsize, stdin);
        array = my_str_to_word_array(buffer, ' ');
        exit_and_ctrl_d(x, array, buffer);
        minishell(array, begin, cd);
    }
    free_function(array, buffer, cd);
    return 0;
}
