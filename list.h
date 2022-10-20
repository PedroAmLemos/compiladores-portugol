//
// Created by pedroamlemos on 20/10/22.
//

#ifndef LEXICO_C_LIST_H
#define LEXICO_C_LIST_H

#include <stdlib.h>

struct ListNode{
    char value;
    struct ListNode *next;

};

typedef struct List{
    struct ListNode *first;
    struct ListNode *last;
    int size;
}List;

List *create_list();

void insert_list(List *list, char value);

int is_list_empty(List *list);

char get_list_char(List *list, int i);

void remove_list_word(List *list, int i);

void remove_list(List *list);

int get_list_size(List *list);

char *get_word_list(List *list, int i);


#endif //LEXICO_C_LIST_H
