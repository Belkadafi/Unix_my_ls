/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** flags_management
*/

#include "my_ls.h"

char *get_name(char *name, char *rd, char *filepath)
{
    name = malloc(sizeof(char) *
    (my_strlen(rd) + my_strlen(filepath) + 2));
    for (int i = 0; i < my_strlen(rd) +
    my_strlen(filepath) + 2; i += 1)
            name[i] = 0;
    my_strcat(name, filepath);
    if (name[my_strlen(name) - 1] != '/')
        my_strcat(name, "/\0");
    my_strcat(name, rd);
    return (name);
}

void print_total(char *filepath)
{
    DIR *dir = opendir(filepath);
    struct dirent *rd = readdir(dir);
    struct stat st;
    int total = 0;
    char *name = NULL;

    while ((rd = readdir(dir))) {
        name = get_name(name, rd->d_name, filepath);
        lstat(name, &st);
        if (rd->d_name[0] != '.' || (my_strlen(rd->d_name) == 1
        && rd->d_name[0] == '.'))
            total += (int)st.st_blocks;
        free(name);
    }
    my_printf("total %d\n", total / 2);
    closedir(dir);
}

int *get_flag(char c, int *params)
{
    char flags[5] = "lRdrt";

    for (int i = 0; i < 5; i += 1) {
        if (c == flags[i]) {
            params[i] = 1;
        }
    }
    return (params);
}

int is_flag(char *str)
{
    for (int i = 0; str[i]; i += 1) {
        if (str[i] != '-' && str[i] != 'l' &&
        str[i] != 'R' && str[i] != 'd' && str[i] != 'r'
        && str[i] != 't' && str[i] != '\0')
            return 0;
    }
    return 1;
}

int *get_params(int len, char **params)
{
    int *flags = malloc(sizeof(int) * 5);

    if (!flags) {
        write(2, "An error occured\n", 18);
        exit(84);
    }
    for (int i = 0; i < 5; flags[i] = 0, i += 1);
    for (int i = 0; i < len - 1; i += 1) {
        if (params[i][0] == '-')
            for (int j = 0; params[i][j]; j += 1)
                flags = get_flag(params[i][j], flags);
    }
    return (flags);
}
