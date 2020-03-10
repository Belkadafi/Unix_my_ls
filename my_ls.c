/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_ls
*/

#include "my_ls.h"

void manage_r(DIR *dir, char *filepath, int *params)
{
    struct dirent *rd;
    struct stat st;
    char *name;

    closedir(dir);
    dir = opendir(filepath);
    if (!dir)
        return (my_ls(filepath, params));
    while ((rd = readdir(dir))) {
        if (rd->d_name[0] != '.') {
            name = get_name(name, rd->d_name, filepath);
            lstat(name, &st);
            if (st.st_mode & __S_IFDIR &&
            rd->d_name[my_strlen(rd->d_name) - 1] != 'o'
            && rd->d_name[my_strlen(rd->d_name) - 2] != '.')
                my_ls(name, params);
        }
    }
    closedir(dir);
}

void my_printer(char **tab, int *params, char *filepath)
{
    int len = 0;

    if (params[4])
        sort(tab, filepath);
    if (!params[3]) {
        for (int i = 0; tab[i]; i += 1) {
            if (params[0])
                my_print_l(tab[i], filepath);
            my_printf("%s\n", tab[i]);
        }
    }
    else {
        for (; tab[len]; len += 1);
        for (int i = len - 1; i >= 0; i -= 1) {
            if (params[0])
                my_print_l(tab[i], filepath);
            my_printf("%s\n", tab[i]);
        }
    }
}

void my_ls(char *filepath, int *params)
{
    DIR *dir = opendir(filepath);
    struct dirent *rd;
    int count = 0;
    char **tab;
    params_t par;

    if (check_error(dir, params, filepath))
        return;
    count = manage_params(filepath, params);
    tab = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; i <= count; i += 1)
        tab[i] = NULL;
    count = 0;
    while ((rd = readdir(dir))) {
        par = (params_t){rd, filepath};
        read_loop(par, tab, &count, params);
    }
    my_printer(tab, params, filepath);
    if (params[1])
        manage_r(dir, filepath, params);
}

void ls_vanilla(char *filepath)
{
    DIR *dir = opendir(filepath);
    struct dirent *rd;
    struct stat st;

    if (!dir) {
        if (!dir && ENOTDIR != errno) {
            perror("Wrong file");
            exit(84);
        }
        else {
            my_printf("%s\n", filepath);
            exit(0);
        }
    }
    while ((rd = readdir(dir))) {
        if (rd->d_name[0] != '.')
            my_printf("%s\n", rd->d_name);
    }
    closedir(dir);
}

int main(int ac, char **av)
{
    int *flags = malloc(sizeof(int) * 5);

    if (ac == 2) {
        if (!is_flag(av[1]))
            ls_vanilla(av[1]);
        else {
            flags = get_params(ac, &av[1]);
            my_ls(".", flags);
        }
    }
    if (ac == 1)
        ls_vanilla(".");
    if (ac > 2) {
        flags = get_params(ac, &av[1]);
        nice_call(&av[1], flags);
    }
}