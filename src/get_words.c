/*
** EPITECH PROJECT, 2019
** duostumper 5
** File description:
** get_words
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "header.h"

int count_lines(char *file)
{
    int fd;
    int lines = 0;
    char buffer[1];

    if ((fd = open(file, O_RDONLY)) == -1)
        return (-1);
    read(fd, buffer, 1);
    if (buffer[0] == '\0')
	return (-1);
    while (read(fd, buffer, 1) != 0) {
        if (buffer[0] == '\n' || buffer[0])
            lines++;
    }
    close(fd);
    return (lines);
}

int check_word(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == ' ' || str[i] == '\t')
            return (1);
        i++;
    }
    return (0);
}

char **get_words(char *av)
{
    int i = 0;
    int nb_lines = count_lines(av);;
    char *line = NULL;
    size_t len;
    FILE *fd;
    char **dest = NULL;

    if (nb_lines == -1 || (fd = fopen(av, "r")) == NULL	||
        !(dest = malloc((nb_lines + 1) * sizeof(char *))))
        return (NULL);
    while (getline(&line, &len, fd) != -1) {
        dest[i] = my_strcpy(line);
        if (check_word(line) != 0 || dest[i]  == NULL)
            return (NULL);
        i++;
    }
    dest[i] = NULL;
    free(line);
    fclose(fd);
    return (dest);
}
