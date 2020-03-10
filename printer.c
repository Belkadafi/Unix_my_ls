/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** printer
*/

#include "my_ls.h"

void not_dir(char *filepath, int *params)
{
    struct stat st;
    int test = 0;

    stat(filepath, &st);
    if (params[0]) {
        my_print_right(st, &test);
        my_print_stats(st, test);
    }
    my_printf("%s\n", filepath);
}

void swap_elem(char **tab, int index1, int index2)
{
    char *tempo;

    tempo = tab[index1];
    tab[index1] = tab[index2];
    tab[index2] = tempo;
}

void read_loop(params_t par, char **tab, int *count, int *params)
{
    if (par.rd->d_name[0] != '.') {
            if (params[0] == 1)
                my_l_flag(par.rd, par.filepath, tab, *count);
            else
                tab[*count] = par.rd->d_name;
            *count += 1;
    }
}

void sort(char **tab, char *filepath)
{
    struct stat s1;
    struct stat s2;
    int test = 1;
    char *name = NULL;

    while (test == 1) {
        test = 0;
        for (int i = 0; tab[i + 1]; i += 1) {
            lstat(get_name(name, tab[i], filepath), &s1);
            name = NULL;
            lstat(get_name(name, tab[i + 1], filepath), &s2);
            name = NULL;
            if (s1.st_mtime < s2.st_mtime) {
                swap_elem(tab, i, i + 1);
                test = 1;
            }
        }
    }

}