//
// Created by pedroamlemos on 20/10/22.
//

#include "sintatico.h"
#include "util.h"

int start_nt(Stack *stack, int input_tolken);

int procedimento_funcao_nt(Stack *stack, int input_tolken);

int declara_procedimento_nt(Stack *stack, int input_tolken);

int declara_funcao_nt(Stack *stack, int input_tolken);

int parametros_nt(Stack *stack, int input_tolken);

int declara_parametros_nt(Stack *stack, int input_tolken);

int bloco_variaveis_nt(Stack *stack, int input_tolken);

int declaracoes_nt(Stack *stack, int input_tolken);

int declaracoes_aux_nt(Stack *stack, int input_tolken);
int parser(int input_tolken, int stack_tolken, Stack *stack){
    switch (stack_tolken) {
        case START_NT:
            return start_nt(stack, input_tolken);
        case PROCEDIMENTO_FUNCAO_NT:
            return procedimento_funcao_nt(stack, input_tolken);
        case DECLARA_PROCEDIMENTO_NT:
            return declara_procedimento_nt(stack, input_tolken);
        case DECLARA_FUNCAO_NT:
            return declara_funcao_nt(stack, input_tolken);
        case PARAMETROS_NT:
            return parametros_nt(stack, input_tolken);
        case DECLARA_PARAMETROS_NT:
            return declara_parametros_nt(stack, input_tolken);
        case BLOCO_VARIAVEIS_NT:
            return bloco_variaveis_nt(stack, input_tolken);
        case DECLARACOES_NT:
            return declaracoes_nt(stack, input_tolken);
        case DECLARACOES_AUXILIAR_NT:
            return declaracoes_aux_nt(stack, input_tolken);
        default:
            return 0;
    }
}

int start_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case ALGORITMO:
            insert_stack(stack, PONTO);
            insert_stack(stack, BLOCO_COMANDOS_NT);
            insert_stack(stack, PROCEDIMENTO_FUNCAO_NT);
            insert_stack(stack, BLOCO_VARIAVEIS_NT);
            insert_stack(stack, PONTO_E_VIRGULA);
            insert_stack(stack, IDENTIFICADOR);
            break;
        default:
            return 0;
    }
    return 1;
}

int procedimento_funcao_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case PROCEDIMENTO:
            insert_stack(stack, PROCEDIMENTO_FUNCAO_NT);
            insert_stack(stack, DECLARA_PROCEDIMENTO_NT);
            break;

        case FUNCAO:
            insert_stack(stack, PROCEDIMENTO_FUNCAO_NT);
            insert_stack(stack, DECLARA_FUNCAO_NT);
            break;

        case INICIO:
            break;

        default:
            return 0;
    }
    return 1;
}

int declara_procedimento_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case PROCEDIMENTO:
            insert_stack(stack, PONTO_E_VIRGULA);
            insert_stack(stack, BLOCO_COMANDOS_NT);
            insert_stack(stack, BLOCO_VARIAVEIS_NT);
            insert_stack(stack, DECLARA_PARAMETROS_NT);
            insert_stack(stack, PONTO_E_VIRGULA);
            insert_stack(stack, PARAMETROS_NT);
            insert_stack(stack, IDENTIFICADOR);
            break;

        default:
            return 0;
    }
    return 1;
}
int declara_funcao_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case FUNCAO:
            insert_stack(stack, PONTO_E_VIRGULA);
            insert_stack(stack, BLOCO_COMANDOS_NT);
            insert_stack(stack, BLOCO_VARIAVEIS_NT);
            insert_stack(stack, DECLARA_PARAMETROS_NT);
            insert_stack(stack, PONTO_E_VIRGULA);
            insert_stack(stack, TIPO_BASICO_NT);
            insert_stack(stack, DOIS_PONTOS);
            insert_stack(stack, PARAMETROS_NT);
            insert_stack(stack, IDENTIFICADOR);
            break;
        default:
            return 0;
    }
    return 1;
}

int parametros_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case ABRE_PARENTESES:
            insert_stack(stack, FECHA_PARENTESES);
            insert_stack(stack, DECLARA_IDENTIFICADOR_NT);
            break;
        case PONTO_E_VIRGULA:
        case DOIS_PONTOS:
            break;
        default:
            return 0;
    }
    return 1;
}

int declara_parametros_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
        case TIPO:
        case IDENTIFICADOR:
            insert_stack(stack, DECLARACOES_NT);
            break;
        case VARIAVEIS:
        case PROCEDIMENTO:
        case FUNCAO:
        case INICIO:
            break;
        default:
            return 0;
    }
    return 1;
}

int bloco_variaveis_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case VARIAVEIS:
            insert_stack(stack, DECLARACOES_NT);
            break;
        case INICIO:
        case PROCEDIMENTO:
        case FUNCAO:
            break;
        default:
            return 0;
    }
    return 1;
}


int declaracoes_aux_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
        case IDENTIFICADOR:
        case TIPO:
            insert_stack(stack, DECLARACOES_NT);
            break;
        case VARIAVEIS:
        case INICIO:
        case PROCEDIMENTO:
        case FUNCAO:
            break;
        default:
            return 0;
    }
    return 1;
}

int declaracoes_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
        case IDENTIFICADOR:
            insert_stack(stack, DECLARACOES_AUXILIAR_NT);
            insert_stack(stack, DECLARA_VARIAVEIS_NT);
            break;
        case TIPO:
            insert_stack(stack, DECLARACOES_AUXILIAR_NT);
            insert_stack(stack, DECLARA_TIPO_NT);
            break;
        default:
            return 0;
    }
    return 1;
}
