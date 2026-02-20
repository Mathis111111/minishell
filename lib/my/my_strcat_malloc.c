/*
** EPITECH PROJECT, 2026
** project template
** File description:
** template
*/

#include "../../include/my.h"

char *my_strcat_malloc(char *a, char *b)
{
    char *str;
    int i = my_strlen(a);
    int nb = 0;

    i += my_strlen(b);
    str = malloc(sizeof(char) * (i + 1));
    if (!str)
        return NULL;
    while (a[nb] != '\0') {
        str[nb] = a[nb];
        nb++;
    }
    for (int n = 0; b[n] != '\0'; n++) {
        str[nb] = b[n];
        nb++;
    }
    str[nb] = '\0';
    return str;
}
