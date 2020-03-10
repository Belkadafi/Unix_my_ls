/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>

int is_alpha_num(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int arg_num(char const *str)
{
    int arg = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((is_alpha_num(str[i]) && i == 0) ||
        (i > 0 && is_alpha_num(str[i]) && !is_alpha_num(str[i - 1])))
            arg += 1;
    }
    return (arg);
}

void my_creater(char **array, char const *str, int nb)
{
    int len = 0;
    int i = 0;

    while (!is_alpha_num(str[i]) && str[i] != '\0')
        i += 1;
    for (int j = 0; j < nb; j += 1) {
        len = 0;
        while (is_alpha_num(str[i]) && str[i] != '\0') {
            len += 1;
            i += 1;
        }
        array[j] = malloc(sizeof(char) * (len + 1));
        while (!is_alpha_num(str[i]) && str[i] != '\0')
            i += 1;
    }
}

char **my_filler(char **array, char const *str, int nb)
{
    int len = 0;
    int i = 0;

    while (!is_alpha_num(str[i]) && str[i] != '\0')
        i += 1;
    for (int j = 0; j < nb; j += 1) {
        len = 0;
        while (is_alpha_num(str[i]) && str[i] != '\0') {
            array[j][len] = str[i];
            len += 1;
            i += 1;
        }
        array[j][len] = 0;
        while (!is_alpha_num(str[i]) && str[i] != '\0')
            i += 1;
    }
    return (array);
}

char **my_str_to_word_array(char const *str)
{
    int nb = arg_num(str);
    char **array = malloc(sizeof(char *) * (nb + 1));

    array[nb] = NULL;
    my_creater(array, str, nb);
    return (my_filler(array, str, nb));
}