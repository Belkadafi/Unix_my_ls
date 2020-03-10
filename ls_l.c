/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** ls_l
*/

#include "my_ls.h"

void my_print_stats(struct stat st, int test)
{
    struct passwd *pwd = getpwuid(st.st_uid);
    struct group *grg = getgrgid(st.st_gid);
    char *time = ctime(&st.st_atime);
    int i = 0;

    time[my_strlen(time) - 1] = 0;
    my_printf("%d ", (int)st.st_nlink);
    my_printf("%s %s ", pwd->pw_name, grg->gr_name);
    if (test == 0)
        my_printf("%d", (int)st.st_size);
    else
        my_printf("%d, %d ", my_major(st.st_rdev), my_minor(st.st_rdev));
    for (; time[i] != ' '; i += 1);
    for (int count = 2; count > 0 && time[i]; i += 1) {
        if (time[i] == ':')
            count -= 1;
        if (count != 0)
            my_printf("%c", time[i]);
    }
    my_printf(" ");
}

int my_print_type(struct stat st)
{
    if ((st.st_mode & __S_IFMT) == __S_IFDIR) {
        my_printf("d");
        return (0);
    }
    if ((st.st_mode & __S_IFMT) == __S_IFCHR) {
        my_printf("c");
        return (1);
    }
    if ((st.st_mode & __S_IFMT) == __S_IFBLK) {
        my_printf("b");
        return (1);
    }
    my_printf("-");
    return (0);
}

void my_print_right(struct stat st, int *test)
{
    *test = my_print_type(st);
    my_printf("%c", ((st.st_mode & S_IRUSR) ? 'r' : '-'));
    my_printf("%c", ((st.st_mode & S_IWUSR) ? 'w' : '-'));
    my_printf("%c", ((st.st_mode & S_IXUSR) ? 'x' : '-'));
    my_printf("%c", ((st.st_mode & S_IRGRP) ? 'r' : '-'));
    my_printf("%c", ((st.st_mode & S_IWGRP) ? 'w' : '-'));
    my_printf("%c", ((st.st_mode & S_IXGRP) ? 'x' : '-'));
    my_printf("%c", ((st.st_mode & S_IROTH) ? 'r' : '-'));
    my_printf("%c", ((st.st_mode & S_IWOTH) ? 'w' : '-'));
    if (st.st_mode & __S_ISVTX)
        my_printf("%c ", ((st.st_mode & S_IXOTH) ? 't' : 'T'));
    else
        my_printf("%c ", ((st.st_mode & S_IXOTH) ? 'x' : '-'));
}

void my_print_l(char *rd, char *filepath)
{
    char *name = NULL;
    struct stat st;
    int test = 0;

    name = get_name(name, rd, filepath);
    lstat(name, &st);
    my_print_right(st, &test);
    my_print_stats(st, test);
}

void my_l_flag(struct dirent *rd, char *filepath, char **tab, int count)
{
    char *name = malloc(sizeof(char) *
    (my_strlen(rd->d_name) + my_strlen(filepath) + 2));

    for (int i = 0; i < my_strlen(rd->d_name) + my_strlen(filepath) + 2; i += 1)
        name[i] = 0;
    my_strcat(name, filepath);
    my_strcat(name, "/\0");
    my_strcat(name, rd->d_name);
    tab[count] = rd->d_name;
}