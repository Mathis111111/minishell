/*
** EPITECH PROJECT, 2026
** project template
** File description:
** template
*/

#include "../../include/my.h"

int my_strlen(char *a)
{
    int i = 0;

    while (a[i] != '\0')
        i++;
    return i;
}
