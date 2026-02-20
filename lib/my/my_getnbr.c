/*
** EPITECH PROJECT, 2025
** G-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#include "../../include/my.h"

int my_getnbr(char *str)
{
    int count = 0;
    int exp = 1;
    int nb = 0;

    nb = my_strlen(str);
    for (int i = (nb - 1); i != -1; i--) {
        count += (str[i] - '0') * exp;
        exp *= 10;
    }
    return count;
}
