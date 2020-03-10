/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** srt cat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int n = 0;
    while (dest[i] != '\0')
        i++;
    while (src[n] != '\0') {
        dest[i] = src[n];
        i++;
        n++;
    }
    dest[i] = '\0';
    return (dest);
}
