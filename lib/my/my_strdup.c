/*
** EPITECH PROJECT, 2025
** cpooldayrush2
** File description:
** task01
*/

#include "../../include/my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int n = 0;
    char *str;

    while (src[i] != '\0') {
        i++;
    }
    str = malloc(sizeof(char) * (i + 1));
    while (src[n] != '\0') {
        str[n] = src[n];
        n++;
    }
    str[n] = '\0';
    return str;
}
