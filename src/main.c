/*
** EPITECH PROJECT, 2019
** duostumper 5
** File description:
** main
*/

#include "header.h"
#include "game.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void destroy_tab(char **tab)
{
    int i = 0;

    while (tab[i]) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

int get_tries(int ac, char **av)
{
    int tries = 10;

    if (ac == 3)
        tries = atoi(av[2]);
    if (tries < 1)
        return (0);
    return (tries);
}

int tab_size(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i);
}

int main(int ac, char **av)
{
    char **tab = NULL;
    int index;
    int tries = 10;

    srand(time(NULL));
    if (ac < 2 || ac > 3)
        return (84);
    tab = get_words(av[1]);
    tries = get_tries(ac, av);
    if (tries < 1 || tab == NULL)
        return (84);
    else {
        index = rand() % tab_size(tab);
        game(tries, tab[index]);
    }
    destroy_tab(tab);
    return (0);
}
