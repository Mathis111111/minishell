/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** Header for setting_up
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <string.h>
    #include <pwd.h>
    #include <grp.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <signal.h>

typedef struct cd_tiret_s {
    char *cd;
    char *cd_before;
} cd_tiret_t;
typedef struct node_s {
    char *env;
    struct node_s *next;
} node_t;
typedef struct header_s {
    struct node_s *header;
} header_t;
char *my_strndup(char const *src, int nb);
int is_alpha_num_for_setenv(char *str);
int my_getnbr(char *str);
int my_putstr_error(char *str);
int my_putstr(char *str);
char *my_strdup(char const *src);
int my_strcmp(char *s, char *s2);
int my_strcmp_modif(char *s, char *s2);
int my_strlen(char *a);
char *my_strcat_malloc(char *a, char *b);
char *my_strcpy(char *dest, char const *src);
char **my_str_to_word_array(char *buf, char c);
int minishell(char **array, header_t *begin, cd_tiret_t *cd);
int cd_functions(char **array, header_t *begin, cd_tiret_t *cd);
int command_exec(char **argv, header_t *begin);
header_t *construct_env(char **env);
int free_function(char **array, char *buffer, cd_tiret_t *cd);
int error_handling(int argc, char **argv);
int env_functions(char **array, header_t *begin);
void stdout_msg(char *msg, char *str);
void stdout_msg2(char *str);
void stdout_msg3(char *str, char *path, char **env);
void stdout_msg4(char *str);
void stdout_msg5(char *str);
void free_path_and_env(char **env, char *path);
int initialize_cd(cd_tiret_t *cd);
int exit_and_ctrl_d(int x, char **array, char *buf);
int signaux_function(void);
int setenv_simple(header_t *begin, char **array);
#endif /* !MY_H_ */
