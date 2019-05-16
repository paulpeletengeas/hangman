/*
** EPITECH PROJECT, 2019
** word
** File description:
** keeps all proto from the word.c
*/

#ifndef WORD_H_
#define WORD_H_
char *create_word_blank(int size);
int check_letter_str(char *str, char letter);
void update_word(char *cp, char *str, char letter);
int word_found(char *str);
#endif
