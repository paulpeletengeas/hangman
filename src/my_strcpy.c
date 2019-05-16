/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy str
*/

#include "header.h"
#include <string.h>
#include <stdlib.h>

char    *my_strcpy(char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * strlen(src));

    while (src[i] != '\n') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
