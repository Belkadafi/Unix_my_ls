/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** is this a standar header ?
*/
#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *dest;
    dest = malloc(my_strlen(src));
    my_strcpy(dest, src);
    dest[my_strlen(src)] = '\0';
    return (dest);
}
