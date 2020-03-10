/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_ls
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <time.h>
#define my_major(dev) ((int)(((unsigned int) (dev) >> 8) & 0xff))
#define my_minor(dev) ((int)((dev) & 0xff))

typedef struct params_s
{
    struct dirent *rd;
    char *filepath;
} params_t;


#include "my_printf.h"

#endif /* !MY_LS_H_ */