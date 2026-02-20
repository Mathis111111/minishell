/*
** EPITECH PROJECT, 2026
** project template
** File description:
** template
*/

#include "include/my.h"

void error_handling_cd(char *str)
{
    if (open(str, O_RDONLY) == -1)
        stdout_msg(str, NULL);
    else
        stdout_msg5(str);
}

char *create_home(char *home, char *tmp)
{
    int len = 0;

    home = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    for (int i = 5; tmp[i] != '\0'; i++) {
        home[len] = tmp[i];
        len++;
    }
    home[len] = '\0';
    return home;
}

int cd_home(header_t *begin, cd_tiret_t *cd)
{
    node_t *node = begin->header;
    char *tmp = NULL;
    char *home = NULL;

    cd->cd_before = getcwd(NULL, 0);
    if (cd != NULL)
        free(cd->cd);
    cd->cd = NULL;
    while (node->next != NULL) {
        if (my_strcmp_modif(node->env, "HOME=") == 0)
            tmp = my_strdup(node->env);
        node = node->next;
    }
    if (tmp != NULL)
        home = create_home(home, tmp);
    cd->cd = my_strdup(getcwd(NULL, 0));
    chdir(home);
    free(home);
    return 0;
}

int cd_directory(char **array, header_t *begin, cd_tiret_t *cd)
{
    int r = 0;

    cd->cd_before = getcwd(NULL, 0);
    if (cd->cd != NULL)
        free(cd->cd);
    cd->cd = NULL;
    r = chdir(array[1]);
    if (r == -1)
        error_handling_cd(array[1]);
    else
        cd->cd = my_strdup(getcwd(NULL, 0));
    return 0;
}

static int condtion_cd_directory(char **array, header_t *begin, cd_tiret_t *cd)
{
    if (array[1] != NULL && array[2] == NULL) {
        if (array[1][0] != '-' && array[1][0] != '~')
            cd_directory(array, begin, cd);
    }
    return 0;
}

int cd_functions(char **array, header_t *begin, cd_tiret_t *cd)
{
    if (array[1] == NULL || array[1][0] == '~')
        cd_home(begin, cd);
    if (array[2] != NULL)
        stdout_msg2(array[0]);
    condtion_cd_directory(array, begin, cd);
    if (cd->cd_before == NULL)
        cd->cd_before = my_strdup(getcwd(NULL, 0));
    if (array[1] != NULL && array[1][0] == '-' && array[2] == NULL)
        chdir(cd->cd_before);
    return 0;
}
