/*
** EPITECH PROJECT, 2026
** project template
** File description:
** template
*/

#include "include/my.h"

int unsetenv_not_first(node_t *node, node_t *tmp, char **array, int i)
{
    while (node->next != NULL) {
        if (my_strcmp_modif(node->next->env, array[i]) == 0) {
            tmp = node->next;
            node->next = tmp->next;
        } else
            node = node->next;
    }
    return 0;
}

int unsetenv_simple(header_t *begin, char **array)
{
    node_t *node;
    node_t *tmp;

    for (int i = 1; array[i] != NULL; i++) {
        node = begin->header;
        if (my_strcmp_modif(node->env, array[i]) == 0)
            begin->header = node->next;
        node = node->next;
        unsetenv_not_first(node, tmp, array, i);
    }
    return 0;
}

int env_simple(header_t *begin)
{
    node_t *node = begin->header;

    while (node != NULL) {
        my_putstr(node->env);
        my_putstr("\n");
        node = node->next;
    }
    return 0;
}

int env_functions(char **array, header_t *begin)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    if (my_strcmp(array[0], "env") == 0 && i == 1)
        env_simple(begin);
    if (my_strcmp(array[0], "env") == 0 && i != 1)
        stdout_msg(array[0], array[1]);
    if (my_strcmp(array[0], "setenv") == 0 && i > 1 && i < 4)
        setenv_simple(begin, array);
    if (my_strcmp(array[0], "setenv") == 0 && i == 1)
        env_simple(begin);
    if (my_strcmp(array[0], "setenv") == 0 && i > 3)
        stdout_msg2(array[0]);
    if (my_strcmp(array[0], "unsetenv") == 0 && i > 1)
        unsetenv_simple(begin, array);
    if (my_strcmp(array[0], "unsetenv") == 0 && i == 1)
        stdout_msg4(array[0]);
    return 0;
}
