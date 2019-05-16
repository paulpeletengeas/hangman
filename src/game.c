/*
** EPITECH PROJECT, 2019
** game
** File description:
** is the gameplay part
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "word.h"

static void is_won(int found, char *cp, char *buff)
{
    if (buff != NULL && found == 0) {
        printf("You lost!\n");
    } else if (buff != NULL) {
        printf("Congratulations!\n");
    }
    if (cp != NULL)
        free(cp);
    if (buff != NULL)
        free(buff);
}

int game(int try, char *word)
{
    char *cp = create_word_blank(strlen(word));
    char *buff = NULL;
    size_t len = 0;
    int found = 0;

    printf("%s\nTries: %d\n\n", cp, try);
    while (try > 0 && cp != NULL && found == 0) {
        printf("Your letter: ");
        getline(&buff, &len, stdin);
        if (check_letter_str(word, buff[0]) == 0) {
            --try;
            printf("%c: is not in this word\n", buff[0]);
        } else {
            update_word(cp, word, buff[0]);
            found = word_found(cp);
        }
        printf("%s\nTries: %d\n\n", cp, try);
    }
    is_won(found, cp, buff);
    return (0);
}
