/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** management
*/

#include "my_ls.h"

int check_error(DIR *dir, int *params, char *filepath)
{
    static int is_first = 0;

    if (!dir && ENOTDIR != errno) {
        perror("Wrong file");
        exit(84);
    }
    if (!dir) {
        not_dir(filepath, params);
        return (1);
    }
    if (params[1]) {
        my_printf((is_first == 0) ? "%s:\n" : "\n%s:\n", filepath);
        is_first = 1;
    }
    return (0);
}

int manage_params(char *filepath, int *params)
{
    DIR *dir = opendir(filepath);
    int count = 0;
    struct dirent *rd;

    if (!dir)
        return (1);
    while (rd = readdir(dir))
        count += 1;
    closedir(dir);
    if (params[2])
        my_ls_d(filepath, params);
    if (params[0])
        print_total(filepath);
    return (count);
}

void nice_call(char **av, int *flags)
{
    int count = 0;
    int test = 0;

    for (int i = 0; av[i]; i += 1)
        if (!is_flag(av[i]))
            count += 1;
    for (int i = 0; av[i]; i += 1) {
        if (!is_flag(av[i])) {
            if (count != 1)
                my_printf("%s:\n", av[i]);
            my_ls(av[i], flags);
            test = 1;
        }
    }
    if (test == 0)
        my_ls(".", flags);
}

void my_ls_d(char *filepath, int *params)
{
    struct stat st;
    int test = 0;

    lstat(filepath, &st);
    if (params[0]) {
        my_print_right(st, &test);
        my_print_stats(st, test);
    }
    my_printf("%s\n", filepath);
    exit(0);
}
