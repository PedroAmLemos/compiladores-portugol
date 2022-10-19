//
// Created by pedroamlemos on 19/10/22.
//
#include <stdio.h>
#include <stdint.h>

#ifndef LEXICO_C_LEXICO_H
#define LEXICO_C_LEXICO_H


void continue_reading(int *current_state, int next_state, int *current_position, int *last_word_ending, int *last_final_state);

int restart_reading(char current_input, int last_word_ending, int *current_state, int *word_start, int *current_position, int last_final_state, FILE *entry, int initial_state);

int check_automata(int initial_state, FILE *entry, int input_size);

#endif //LEXICO_C_LEXICO_H
