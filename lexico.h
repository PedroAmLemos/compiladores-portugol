//
// Created by pedroamlemos on 19/10/22.
//
#include <stdio.h>
#include <stdint.h>
#include "list.h"

#ifndef LEXICO_C_LEXICO_H
#define LEXICO_C_LEXICO_H


void continue_reading(int *current_state, int next_state, int *current_position, int *last_word_ending, int *last_final_state);

int restart_reading(List *input, char current_input, int last_word_ending, int word_start, int last_final_state, char *word, int *coluna);

int check_automata(int initial_state, FILE *entry, List *input, int *coluna, char *erro);

int advance(int initial_state, FILE *entry, List *input, int *linha, int *coluna, char *word);

#endif //LEXICO_C_LEXICO_H
