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

int comandos_aux_3_nt(Stack *stack, int input_tolken);

int expressao_nt(Stack *stack, int input_tolken);

int expressao_aux_nt(Stack *stack, int input_tolken);

int expressao_simples_nt(Stack *stack, int input_tolken);

int expressao_simples_aux_nt(Stack *stack, int input_tolken);

int termo_nt(Stack *stack, int input_tolken);

int termo_aux_nt(Stack *stack, int input_tolken);

int fator_nt(Stack *stack, int input_tolken);

int fator_aux_nt(Stack *stack, int input_tolken);

int variavel_nt(Stack *stack, int input_tolken);

int variavel_aux_nt(Stack *stack, int input_tolken);

int expr_iter_nt(Stack *stack, int input_tolken);

int expr_iter_aux_nt(Stack *stack, int input_tolken);

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
        case COMANDOS_AUX_3_NT:
            return comandos_aux_3_nt(stack, input_tolken);
        case EXPRESSAO_NT:
            return expressao_nt(stack, input_tolken);
        case EXPRESSAO_AUX_NT:
            return expressao_aux_nt(stack, input_tolken);
        case EXPRESSAO_SIMPLES_NT:
            return expressao_simples_nt(stack, input_tolken);
        case EXPRESSAO_SIMPLES_AUX_NT:
            return expressao_simples_aux_nt(stack, input_tolken);
        case TERMO_NT:
            return termo_nt(stack, input_tolken);
        case TERMO_AUX_NT:
            return termo_aux_nt(stack, input_tolken);
        case FATOR_NT:
            return fator_nt(stack, input_tolken);
        case FATOR_AUX_NT:
            return fator_aux_nt(stack, input_tolken);
        case VARIAVEL_NT:
            return variavel_nt(stack, input_tolken);
        case VARIAVEL_AUX_NT:
            return variavel_aux_nt(stack, input_tolken);
        case EXPR_ITER_NT:
            return expr_iter_nt(stack, input_tolken);
        case EXPR_ITER_AUX_NT:
            return expr_iter_aux_nt(stack, input_tolken);

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
            break;
        case ENQUANTO:
            insert_stack(stack, ENQUANTO);
            insert_stack(stack, FIM);
            insert_stack(stack, LISTA_COMANDOS_NT);
            insert_stack(stack, FACA);
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, ENQUANTO);
            break;
        case PARA:
            insert_stack(stack, COMANDOS_AUX_3_NT);
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, ATE);
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, DE);
            insert_stack(stack, IDENTIFICADOR);
            insert_stack(stack, PARA);
            break;
        case REPITA:
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, ATE);
            insert_stack(stack, LISTA_COMANDOS_NT);
            insert_stack(stack, REPITA);
            break;
        case LEIA:
            insert_stack(stack, FECHA_PARENTESES);
            insert_stack(stack, VARIAVEL_NT);
            insert_stack(stack, ABRE_PARENTESES);
            insert_stack(stack, LEIA);
            break;
        case IMPRIMA:
            insert_stack(stack, FECHA_PARENTESES);
            insert_stack(stack, EXPR_ITER_NT);
            insert_stack(stack, ABRE_PARENTESES);
            insert_stack(stack, IMPRIMA);
            break;
        default:
            return 0;
    }
    return 1;
}

int comandos_aux_1_nt(Stack *stack, int input_tolken){
    switch (input_tolken) {
        case ABRE_PARENTESES:
            insert_stack(stack, FECHA_PARENTESES);
            insert_stack(stack, EXPR_ITER_NT);
            insert_stack(stack, ABRE_PARENTESES);
            break;
        case PONTO_E_VIRGULA:
            break;
        case ATRIBUICAO: //todo perguntar isso pro pedro
        case ABRE_COLCHETES:
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, ATRIBUICAO);
            insert_stack(stack, VARIAVEL_AUX_NT);
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

int comandos_aux_3_nt(Stack *stack, int input_tolken){
    switch(input_tolken) {
        case FACA:
            insert_stack(stack, PARA);
            insert_stack(stack, FIM);
            insert_stack(stack, LISTA_COMANDOS_NT);
            insert_stack(stack, FACA);
            break;

        case PASSO:
            insert_stack(stack, PARA);
            insert_stack(stack, FIM);
            insert_stack(stack, LISTA_COMANDOS_NT);
            insert_stack(stack, FACA);
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, PASSO);
            break;
        default:
            return 0;
    }
    return 1;
}

int expressao_nt(Stack *stack, int input_tolken){
    switch(input_tolken) {
        case ABRE_PARENTESES:
        case NAO:
        case NUMERO_INTEIRO:
        case NUMERO_REAL:
        case VERDADEIRO:
        case FALSO:
        case STRING:
        case IDENTIFICADOR:
        case MAIS:
        case MENOS:
            insert_stack(stack, EXPRESSAO_AUX_NT);
            insert_stack(stack, EXPRESSAO_SIMPLES_NT);
            break;
        default:
            return 0;
    }
    return 1;
}

int expressao_aux_nt(Stack *stack, int input_tolken){
    switch(input_tolken) {
        case IGUAL:
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, IGUAL);
            break;
        case DIFERENTE:
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, DIFERENTE);
            break;
        case MENOR:
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, MENOR);
            break;
        case MENOR_IGUAL:
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, MENOR_IGUAL);
            break;
        case MAIOR_IGUAL:
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, MAIOR_IGUAL);
            break;
        case MAIOR:
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, MAIOR);
            break;
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case FECHA_PARENTESES:
        case VIRGULA:
        case PONTO_E_VIRGULA:
        case FECHA_COLCHETES:
            break;
        default:
            return 0;
    }
    return 1;

}
int expressao_simples_nt(Stack *stack, int input_tolken){

    switch(input_tolken) {
        case MAIS:
            insert_stack(stack, EXPRESSAO_SIMPLES_AUX_NT);
            insert_stack(stack, TERMO_NT);
            insert_stack(stack, MAIS);
            break;
        case MENOS:
            insert_stack(stack, EXPRESSAO_SIMPLES_AUX_NT);
            insert_stack(stack, TERMO_NT);
            insert_stack(stack, MENOS);
            break;
        case ABRE_PARENTESES:
        case NAO:
        case NUMERO_INTEIRO:
        case NUMERO_REAL:
        case VERDADEIRO:
        case FALSO:
        case STRING:
        case IDENTIFICADOR:
            insert_stack(stack, EXPRESSAO_SIMPLES_AUX_NT);
            insert_stack(stack, TERMO_NT);
            break;
        default:
            return 0;
    }
    return 1;

}

int expressao_simples_aux_nt(Stack *stack, int input_tolken){
    switch(input_tolken) {
        case MAIS:
            insert_stack(stack, EXPRESSAO_SIMPLES_NT);
            insert_stack(stack, MAIS);
            break;
        case MENOS:
            insert_stack(stack, EXPRESSAO_SIMPLES_NT);
            insert_stack(stack, MENOS);
            break;
        case OU:
            insert_stack(stack, EXPRESSAO_SIMPLES_NT);
            insert_stack(stack, OU);
            break;
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case FECHA_PARENTESES:
        case VIRGULA:
        case PONTO_E_VIRGULA:
        case FECHA_COLCHETES:
        case IGUAL:
        case DIFERENTE:
        case MENOR:
        case MENOR_IGUAL:
        case MAIOR:
        case MAIOR_IGUAL:
            break;
        default:
            return 0;
    }
    return 1;
}
int termo_nt(Stack *stack, int input_tolken){

    switch(input_tolken) {
        case ABRE_PARENTESES:
        case NAO:
        case NUMERO_INTEIRO:
        case NUMERO_REAL:
        case VERDADEIRO:
        case FALSO:
        case STRING:
        case IDENTIFICADOR:
            insert_stack(stack, TERMO_AUX_NT);
            insert_stack(stack, FATOR_NT);
            break;
        default:
            return 0;
    }
    return 1;
}



int termo_aux_nt(Stack *stack, int input_tolken){
    switch(input_tolken) {
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case FECHA_PARENTESES:
        case VIRGULA:
        case PONTO_E_VIRGULA:
        case FECHA_COLCHETES:
        case IGUAL:
        case DIFERENTE:
        case MENOR:
        case MENOR_IGUAL:
        case MAIOR_IGUAL:
        case MAIOR:
        case MAIS:
        case MENOS:
        case OU:
            break;
        case VEZES:
            insert_stack(stack, TERMO_NT);
            insert_stack(stack, VEZES);
            break;
        case DIVISAO:
            insert_stack(stack, TERMO_NT);
            insert_stack(stack, DIVISAO);
            break;
        case DIV:
            insert_stack(stack, TERMO_NT);
            insert_stack(stack, DIV);
            break;
        case E:
            insert_stack(stack, TERMO_NT);
            insert_stack(stack, E);
            break;
        default:
            return 0;

    }
    return 1;
}

int fator_nt(Stack *stack, int input_tolken){
    switch(input_tolken) {
        case ABRE_PARENTESES:
            insert_stack(stack, FECHA_PARENTESES);
            insert_stack(stack, EXPRESSAO_NT);
            insert_stack(stack, ABRE_PARENTESES);
            break;
        case NAO:
            insert_stack(stack, FATOR_NT);
            insert_stack(stack, NAO);
            break;
        case NUMERO_INTEIRO:
            insert_stack(stack, NUMERO_INTEIRO);
            break;
        case NUMERO_REAL:
            insert_stack(stack, NUMERO_REAL);
            break;
        case VERDADEIRO:
            insert_stack(stack, VERDADEIRO);
            break;
        case FALSO:
            insert_stack(stack, FALSO);
            break;
        case STRING:
            insert_stack(stack, STRING);
            break;
        case IDENTIFICADOR:
            insert_stack(stack, FATOR_AUX_NT);
            insert_stack(stack, IDENTIFICADOR);
            break;
        default:
            return 0;
    }
    return 1;
}

int fator_aux_nt(Stack *stack, int input_tolken){
    switch(input_tolken) {
        case ABRE_PARENTESES:
            insert_stack(stack, FECHA_PARENTESES);
            insert_stack(stack, EXPR_ITER_NT);
            insert_stack(stack, ABRE_PARENTESES);
            break;
        case ATRIBUICAO:
        case FECHA_PARENTESES:
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case VIRGULA:
        case PONTO_E_VIRGULA:
        case FECHA_COLCHETES:
        case IGUAL:
        case DIFERENTE:
        case MENOR:
        case MENOR_IGUAL:
        case MAIOR_IGUAL:
        case MAIOR:
        case MAIS:
        case MENOS:
        case OU:
        case VEZES:
        case DIVISAO:
        case DIV:
        case E:
        case ABRE_COLCHETES:
            insert_stack(stack, VARIAVEL_AUX_NT);
            break;
        default:
            return 0;
    }
    return 1;
}

int variavel_nt(Stack *stack, int input_tolken){
    switch(input_tolken) {
        case IDENTIFICADOR:
            insert_stack(stack, VARIAVEL_AUX_NT);
            insert_stack(stack, IDENTIFICADOR);
            break;
        default:
            return 0;
    }

    return 1;
}

int variavel_aux_nt(Stack *stack, int input_tolken){
    switch(input_tolken) {
        case ABRE_COLCHETES:
            insert_stack(stack, FECHA_COLCHETES);
            insert_stack(stack, EXPR_ITER_NT);
            insert_stack(stack, ABRE_COLCHETES);
            break;
        case ATRIBUICAO:
        case FECHA_PARENTESES:
        case ENTAO:
        case FACA:
        case ATE:
        case PASSO:
        case VIRGULA:
        case PONTO_E_VIRGULA:
        case FECHA_COLCHETES:
        case IGUAL:
        case DIFERENTE:
        case MENOR:
        case MENOR_IGUAL:
        case MAIOR_IGUAL:
        case MAIOR:
        case MAIS:
        case MENOS:
        case OU:
        case VEZES:
        case DIVISAO:
        case DIV:
        case E:
            break;
        default:
            return 0;
    }
    return 1;
}

int expr_iter_nt(Stack *stack, int input_tolken){
    switch(input_tolken) {
        case MAIS:
        case MENOS:
        case ABRE_PARENTESES:
        case NAO:
        case NUMERO_INTEIRO:
        case NUMERO_REAL:
        case VERDADEIRO:
        case FALSO:
        case STRING:
        case IDENTIFICADOR: //variavel
            insert_stack(stack, EXPR_ITER_AUX_NT);
            insert_stack(stack, EXPRESSAO_NT);
            break;

        default:
            return 0;
    }

    return 1;

}

int expr_iter_aux_nt(Stack *stack, int input_tolken) {

    switch (input_tolken) {
        case VIRGULA:
            insert_stack(stack, EXPR_ITER_NT);
            insert_stack(stack, VIRGULA);
            break;
        case FECHA_PARENTESES:
        case FECHA_COLCHETES:
            break;
        default:
            return 0;
    }


    return 1;
}