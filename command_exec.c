/*
** EPITECH PROJECT, 2026
** project mini_shell
** File description:
** mini_shell
*/

#include "include/my.h"

char **list_to_array(header_t *begin)
{
    node_t *node = begin->header;
    int i = 0;
    char **env;

    while (node != NULL) {
        i++;
        node = node->next;
    }
    env = malloc(sizeof(char *) * (i + 1));
    node = begin->header;
    i = 0;
    while (node != NULL) {
        env[i] = malloc(sizeof(char) * (my_strlen(node->env) + 1));
        env[i] = my_strdup(node->env);
        node = node->next;
        i++;
    }
    env[i] = NULL;
    return env;
}

void free_path_and_env(char **env, char *path)
{
    for (int i = 0; env[i] != NULL; i++)
        free(env[i]);
    free(env);
    free(path);
}

static void free_path_and_array(char **array, char *path)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    free(path);
}

char *create_path(char *path, char **argv)
{
    char **array;
    char *str = my_strndup(path, 5);

    if (access(argv[0], X_OK) == 0)
        return argv[0];
    array = my_str_to_word_array(str, ':');
    for (int i = 0; array[i] != NULL; i++) {
        free(path);
        path = my_strcat_malloc(array[i], "/");
        free(str);
        str = my_strcat_malloc(path, argv[0]);
        if (access(str, X_OK) == 0) {
            free_path_and_array(array, path);
            return str;
        }
    }
    free_path_and_array(array, path);
    free(str);
    return NULL;
}

char *env_path(header_t *begin, char **argv)
{
    node_t *node = begin->header;
    char *path = NULL;
    char *str = NULL;

    while (node != NULL) {
        if (my_strcmp_modif(node->env, "PATH=") == 0)
            path = my_strdup(node->env);
        node = node->next;
    }
    if (!path)
        return NULL;
    str = create_path(path, argv);
    return str;
}

int command_exec(char **argv, header_t *begin)
{
    char *path = NULL;
    int status = 0;
    pid_t pid = fork();
    char **env = list_to_array(begin);

    if (pid < 0)
        perror("fork failed\n");
    if (pid == 0) {
        path = env_path(begin, argv);
        execve(path, argv, env);
        stdout_msg3(argv[0], path, env);
        exit(0);
    }
    if (pid > 0)
        waitpid(pid, &status, 0);
    if (WIFSIGNALED(status))
        my_putstr(strsignal(WTERMSIG(status)));
    free_path_and_env(env, path);
    return 0;
}
