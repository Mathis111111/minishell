/*
** EPITECH PROJECT, 2026
** project template
** File description:
** template
*/

#include "../../include/my.h"

char *replace_tab_and_guillemet_by_space(char *buf)
{
    for (int len = 0; buf[len] != '\0'; len++) {
        if (buf[len] == '\t')
            buf[len] = ' ';
        if (buf[len] == '"')
            buf[len] = ' ';
    }
    return buf;
}

char *clean_str(char *buf, char c)
{
    char *new_buf = malloc(sizeof(char) * (my_strlen(buf) + 1));
    int i = 0;
    int len = 0;

    buf = replace_tab_and_guillemet_by_space(buf);
    while (buf[i] == c)
        i++;
    while (buf[i] != '\0') {
        if (buf[i] != c && buf[i] != '\n') {
            new_buf[len] = buf[i];
            len++;
        }
        if (buf[i] == c && (buf[i + 1] != c && buf[i + 1] != '\n')) {
            new_buf[len] = buf[i];
            len++;
        }
        i++;
    }
    new_buf[len] = '\0';
    return new_buf;
}

char **my_str_to_word_array_2(char **array, char *buf, int count, char c)
{
    int i = 0;
    int len = 0;
    int index = 0;

    while (buf[i] != '\0') {
        while (buf[i] != '\0' && buf[i] != c) {
            array[index][len] = buf[i];
            len++;
            i++;
        }
        if (len != 0) {
            array[index][len] = '\0';
            len = 0;
            index++;
        }
        if (buf[i] == c)
            i++;
    }
    free(buf);
    return array;
}

char **my_str_to_word_array(char *buf, char c)
{
    int count = 0;
    char **array;
    char *new_buf = clean_str(buf, c);

    if (new_buf[0] != '\0')
        count++;
    for (int i = 0; new_buf[i] != '\0'; i++) {
        if (new_buf[i] == c)
            count++;
    }
    array = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; i != count; i++)
        array[i] = malloc(sizeof(char) * (my_strlen(new_buf) + 1));
    array[count] = NULL;
    array = my_str_to_word_array_2(array, new_buf, count, c);
    return array;
}
