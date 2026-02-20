/*
** EPITECH PROJECT, 2026
** project template
** File description:
** template
*/

#include "../../include/my.h"

int error_msg1(void)
{
    my_putstr("setenv: Variable name must begin with a letter.\n");
    return 1;
}

int error_msg2(void)
{
    my_putstr("setenv: Variable name must contain alphanumeric characters.\n");
    return 1;
}

int is_alpha_num_for_setenv(char *str)
{
    int r = 0;
    int nb = str[0];

    if ((nb >= 65 && nb <= 90) || (nb >= 97 && nb <= 122) || nb == 95)
        nb = str[1];
    else
        r = error_msg1();
    for (int i = 1; str[i] != '\0'; i++) {
        nb = str[i];
        if ((nb >= 65 && nb <= 90) || (nb >= 97 && nb <= 122) || nb == 95 || (
                nb >= 48 && nb <= 57)) {
            continue;
        } else
            r = error_msg2();
    }
    return r;
}
