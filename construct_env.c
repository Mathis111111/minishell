/*
** EPITECH PROJECT, 2026
** project mini_shell
** File description:
** mini_shell
*/

#include "include/my.h"

header_t *construct_env(char **env)
{
    node_t *new;
    header_t *begin = malloc(sizeof(header_t));
    int i = 0;

    while (env[i + 1] != NULL)
        i++;
    begin->header = NULL;
    while (i >= 0) {
        new = malloc(sizeof(node_t));
        new->env = my_strdup(env[i]);
        new->next = begin->header;
        begin->header = new;
        i--;
    }
    return begin;
}
