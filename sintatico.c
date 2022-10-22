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

int declara_tipo_nt(Stack *stack, int input_tolken);

int declara_variaveis_nt(Stack *stack, int input_tolken);

int declara_identificador_nt(Stack *stack, int input_tolken);

int declara_identificador_aux_nt(Stack *stack, int input_tolken);

int vetor_matriz_nt(Stack *stack, int input_tolken);

int dimensao_nt(Stack *stack, int input_tolken);

int dimenso_auxiliar_nt(Stack *stack, int input_tolken);

int tipo_bastico_nt(Stack *stack, int input_tolken);

int bloco_comandos_nt(Stack *stack, int input_tolken);

int lista_comandos_nt(Stack *stack, int input_tolken);

int lista_comandos_aux_nt(Stack *stack, int input_tolken);

int comandos_nt(Stack *stack, int input_tolken);

int comandos_aux_1_nt(Stack *stack, int input_tolken);

int comandos_aux_2_nt(Stack *stack, int input_tolken);

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
        case DECLARA_TIPO_NT:
            return declara_tipo_nt(stack, input_tolken);
        case DECLARA_VARIAVEIS_NT:
            return declara_variaveis_nt(stack, input_tolken);
        case DECLARA_IDENTIFICADOR_NT:
            return declara_identificador_nt(stack, input_tolken);
        case DECLARA_IDENTIFICADOR_AUXILIAR_NT:
            return declara_identificador_aux_nt(stack, input_tolken);
        case VETOR_MATRIZ_NT:
            return vetor_matriz_nt(stack, input_tolken);
        case DIMENSAO_NT:
            return dimensao_nt(stack, input_tolken);
        case DIMENSAO_AUXILIAR_NT:
            return dimenso_auxiliar_nt(stack, input_tolken);
        case TIPO_BASICO_NT:
            return tipo_bastico_nt(stack, input_tolken);
        case BLOCO_COMANDOS_NT:
            return bloco_comandos_nt(stack, input_tolken);
        case LISTA_COMANDOS_NT:
            return lista_comandos_nt(stack, input_tolken);
        case LISTA_COMANDOS_AUXILIAR_NT:
            return lista_comandos_aux_nt(stack, input_tolken);
        case COMANDOS_NT:
            return comandos_nt(stack, input_tolken);
        case COMANDOS_AUX_1_NT:
            return comandos_aux_1_nt(stack, input_tolken);
        case COMANDOS_AUX_2_NT:
            return comandos_aux_2_nt(stack, input_tolken);




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
            insert_stack(stack, ALGORITMO);
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
            insert_stack(stack, PROCEDIMENTO);
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
            insert_stack(stack, FUNCAO);
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
            insert_stack(stack, ABRE_PARENTESES);
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
            insert_stack(stack, VARIAVEIS);
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

int declara_tipo_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case TIPO:
            insert_stack(stack, PONTO_E_VIRGULA);
            insert_stack(stack, TIPO_BASICO_NT);
            insert_stack(stack, FECHA_COLCHETES);
            insert_stack(stack, DIMENSAO_NT);
            insert_stack(stack, ABRE_COLCHETES);
            insert_stack(stack, VETOR_MATRIZ_NT);
            insert_stack(stack, IGUAL);
            insert_stack(stack, IDENTIFICADOR);
            insert_stack(stack, TIPO);
            break;
        default:
            return 0;
    }
    return 1;
}

int declara_variaveis_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case INTEIRO:
        case REAL:
        case CARACTERE:
        case LOGICO:
        case IDENTIFICADOR:
            insert_stack(stack, PONTO_E_VIRGULA);
            insert_stack(stack, DECLARA_IDENTIFICADOR_NT);
            insert_stack(stack, DOIS_PONTOS);
            insert_stack(stack, TIPO_BASICO_NT);
            break;
        default:
            return 0;
    }
    return 1;
}

int declara_identificador_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case IDENTIFICADOR:
            insert_stack(stack, DECLARA_IDENTIFICADOR_AUXILIAR_NT);
            insert_stack(stack, IDENTIFICADOR);
            break;
        default:
            return 0;
    }
    return 1;
}
int declara_identificador_aux_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case VIRGULA:
            insert_stack(stack, DECLARA_IDENTIFICADOR_NT);
            insert_stack(stack, VIRGULA);
            break;
        case FECHA_PARENTESES:
        case PONTO_E_VIRGULA:
            break;
        default:
            return 0;
    }
    return 1;
}


int vetor_matriz_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case VETOR:
            insert_stack(stack, VETOR);
            break;
        case MATRIZ:
            insert_stack(stack, MATRIZ);
            break;
        default:
            return 0;
    }
    return 1;
}

int dimensao_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case NUMERO_INTEIRO:
            insert_stack(stack, DIMENSAO_AUXILIAR_NT);
            insert_stack(stack, NUMERO_INTEIRO);
            insert_stack(stack, DOIS_PONTOS);
            insert_stack(stack, NUMERO_INTEIRO);
            break;
        default:
            return 0;
    }
    return 1;

}

int dimenso_auxiliar_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case VIRGULA:
            insert_stack(stack, DIMENSAO_NT);
            insert_stack(stack, VIRGULA);
            break;
        case FECHA_COLCHETES:
            break;
        default:
            return 0;
    }
    return 1;
}
int tipo_bastico_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case INTEIRO:
            insert_stack(stack, INTEIRO);
            break;
        case REAL:
            insert_stack(stack, REAL);
            break;
        case CARACTERE:
            insert_stack(stack, CARACTERE);
            break;
        case LOGICO:
            insert_stack(stack, LOGICO);
            break;
        case IDENTIFICADOR:
            insert_stack(stack, IDENTIFICADOR);
            break;
        default:
            return 0;
    }
    return 1;
}

int bloco_comandos_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case INICIO:
            insert_stack(stack, FIM);
            insert_stack(stack, LISTA_COMANDOS_NT);
            insert_stack(stack, INICIO);
            break;
        default:
            return 0;
    }
    return 1;
}


int lista_comandos_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case IDENTIFICADOR:
        case SE:
        case ENQUANTO:
        case PARA:
        case REPITA:
        case LEIA:
        case IMPRIMA:
            insert_stack(stack, LISTA_COMANDOS_AUXILIAR_NT);
            insert_stack(stack, PONTO_E_VIRGULA);
            insert_stack(stack, COMANDOS_NT);
            break;
        default:
            return 0;
    }
    return 1;
}

int lista_comandos_aux_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case IDENTIFICADOR:
        case SE:
        case ENQUANTO:
        case PARA:
        case REPITA:
        case LEIA:
        case IMPRIMA:
            insert_stack(stack, LISTA_COMANDOS_NT);
        case FIM:
        case SENAO:
        case ATE:
            break;
        default:
            return 0;
    }
    return 1;
}

int comandos_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case IDENTIFICADOR:
            insert_stack(stack, COMANDOS_AUX_1_NT);
            insert_stack(stack, IDENTIFICADOR);
            break;
        case SE:
            insert_stack(stack, COMANDOS_AUX_2_NT);
            insert_stack(stack, LISTA_COMANDOS_NT);
            insert_stack(stack, ENTAO);
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, SE);
        default:
            return 0;
    }
    return 1;
}

int comandos_aux_1_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case ABRE_PARENTESES:
            insert_stack(stack, FECHA_PARENTESES);
            insert_stack(stack, EXP_ITER_NT);
            insert_stack(stack, ABRE_PARENTESES);
            break;
        case PONTO_E_VIRGULA:
            break;
        case ATRIBUICAO:
        case ABRE_COLCHETES:
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, ATRIBUICAO);
            insert_stack(stack, VARIAVEIS_AUX_NT);
            break;
        default:
            return 0;
    }
    return 1;
}

int comandos_aux_2_nt(Stack *stack, int input_tolken){
    switch(input_tolken) {
        case FIM:
            insert_stack(stack, SE);
            insert_stack(stack, FIM);
            break;
        case SENAO:
            insert_stack(stack, SE);
            insert_stack(stack, FIM);
            insert_stack(stack, LISTA_COMANDOS_NT);
            insert_stack(stack, SENAO);
            break;
        default:
            return 0;
    }
}
