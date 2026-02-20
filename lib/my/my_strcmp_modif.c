/*
** EPITECH PROJECT, 2025
** cpoolday06
** File description:
** task01
*/

#include "../../include/my.h"

int my_strcmp_modif(char *s, char *s2)
{
    int i = 0;

    if (s == NULL || s2 == NULL)
        return 84;
    if (s[i] != s2[i])
        return 84;
    while (s[i] == s2[i] && s2[i + 1] != '\0') {
        i++;
        if (s[i] != s2[i])
            return 84;
    }
    return 0;
}
