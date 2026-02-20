/*
** EPITECH PROJECT, 2026
** project template
** File description:
** template
*/

#include "include/my.h"

char **formating_setenv(char **array)
{
    char *tmp = my_strdup(array[1]);

    free(array[1]);
    array[1] = my_strcat_malloc(tmp, "=");
    free(tmp);
    if (array[2] != NULL) {
        tmp = my_strdup(array[1]);
        free(array[1]);
        array[1] = my_strcat_malloc(tmp, array[2]);
    }
    return array;
}

int setenv_func(header_t *begin, char **array, node_t *node)
{
    node_t *tmp = malloc(sizeof(node_t));

    tmp->env = my_strdup(array[1]);
    tmp->next = NULL;
    if (begin->header == NULL) {
        begin->header = tmp;
        return 0;
    }
    while (node->next != NULL)
        node = node->next;
    node->next = tmp;
    return 0;
}

int setenv_compare(header_t *begin, node_t *node, char **array)
{
    char *tmp = my_strcat_malloc(array[1], "=");

    formating_setenv(array);
    while (node != NULL) {
        if (my_strcmp_modif(node->env, tmp) == 0) {
            free(node->env);
            node->env = my_strdup(array[1]);
            return 1;
        }
        node = node->next;
    }
    free(tmp);
    return 0;
}

int setenv_simple(header_t *begin, char **array)
{
    node_t *node = begin->header;
    int r = 0;

    if (is_alpha_num_for_setenv(array[1]) == 0) {
        r = setenv_compare(begin, node, array);
        if (r == 0)
            setenv_func(begin, array, node);
    }
    return 0;
}
