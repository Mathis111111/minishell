/*
** EPITECH PROJECT, 2025
** cpooldayrush2
** File description:
** task01
*/

#include "../../include/my.h"

char *my_strndup(char const *src, int nb)
{
    int i = 0;
    int n = 0;
    char *str;

    while (src[nb] != '\0') {
        nb++;
    }
    str = malloc(sizeof(char) * (nb + 1));
    nb = 0;
    while (src[nb] != '\0') {
        str[n] = src[nb];
        n++;
        nb++;
    }
    str[n] = '\0';
    return str;
}
