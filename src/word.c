/*
** EPITECH PROJECT, 2019
** word
** File description:
** modifie the word or check steps
*/

#include <string.h>
#include <stdlib.h>

char *create_word_blank(int size)
{
    char *new = malloc(sizeof(char) * (size + 1));
    int index = 0;

    while (new != NULL && index < size) {
        new[index] = '*';
        ++index;
    }
    if (new != NULL) {
        new[index] = '\0';
    }
    return (new);
}

int check_letter_str(char *str, char letter)
{
    int index = 0;

    while (str[index] != '\0' && str[index] != letter) {
        ++index;
    }
    if (str[index] == letter) {
        return (1);
    }
    return (0);
}

void update_word(char *cp, char *word, char letter)
{
    int index = 0;

    while (word[index] != '\0') {
        if (word[index] == letter) {
            cp[index] = letter;
        }
        ++index;
    }
}

int word_found(char *cp)
{
    unsigned int index = 0;

    while (cp[index] != '\0' && cp[index] != '*') {
        ++index;
    }
    if (index == strlen(cp)) {
        return (1);
    }
    return (0);
}
