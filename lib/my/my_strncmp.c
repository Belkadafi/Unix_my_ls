/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** compares n char
*/

#include<stdio.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    i = s1[n] - s2[n];
    return i;
}
