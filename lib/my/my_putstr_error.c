/*
** EPITECH PROJECT, 2026
** project template
** File description:
** template
*/

#include "../../include/my.h"

int my_putstr_error(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
    return 0;
}
