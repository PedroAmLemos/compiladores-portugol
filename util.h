//
// Created by pedroamlemos on 19/10/22.
//

#ifndef LEXICO_C_UTIL_H
#define LEXICO_C_UTIL_H

enum tolkens{
    tolkens_de_controle, // tolkens de controle
    ERRO,
    END_OF_FILE,
    WHITE_SPACE,
    QUEBRA_LINHA,

    comeco_terminais, // tolkens terminais
    IDENTIFICADOR,
    E,
    NUMERO_INTEIRO,
    COMENTARIO_DE_BLOCO_ABERTO,
    DIVISAO,
    PONTO_E_VIRGULA,
    VIRGULA,
    DOIS_PONTOS,
    PONTO,
    ABRE_COLCHETES,
    FECHA_COLCHETES,
    ABRE_PARENTESES,
    FECHA_PARENTESES,
    IGUAL,
    MENOR,
    MAIOR,
    MAIS,
    MENOS,
    VEZES,
    STRING,
    DE,
    OU,
    SE,
    NUMERO_REAL,
    COMENTARIO_DE_BLOCO,
    COMENTARIO_DE_LINHA,
    ATRIBUICAO,
    DIFERENTE,
    MENOR_IGUAL,
    MAIOR_IGUAL,
    ATE,
    DIV,
    FIM,
    NAO,
    FACA,
    LEIA,
    PARA,
    REAL,
    TIPO,
    ENTAO,
    FALSO,
    PASSO,
    SENAO,
    VETOR,
    FUNCAO,
    INICIO,
    LOGICO,
    MATRIZ,
    REPITA,
    INTEIRO,
    IMPRIMA,
    ENQUANTO,
    ALGORITMO,
    CARACTERE,
    VARIAVEIS,
    VERDADEIRO,
    PROCEDIMENTO,

    comeco_nao_terminais, // nao terminais
    START_NT,
    BLOCO_VARIAVEIS_NT,
    PROCEDIMENTO_FUNCAO_NT,
    BLOCO_COMANDOS_NT,
    DECLARA_PROCEDIMENTO_NT,
    DECLARA_FUNCAO_NT,
    DECLARA_PARAMETROS_NT,
    PARAMETROS_NT,
    TIPO_BASICO_NT,
    DECLARA_IDENTIFICADOR_NT,
    DECLARACOES_NT,
    DECLARA_VARIAVEIS_NT,
    DECLARA_TIPO_NT,
    DECLARACOES_AUXILIAR_NT,
    DIMENSAO_NT,
    VETOR_MATRIZ_NT,
    DECLARA_IDENTIFICADOR_AUXILIAR_NT,
    DIMENSAO_AUXILIAR_NT,
    LISTA_COMANDOS_NT,
    LISTA_COMANDOS_AUXILIAR_NT,
    COMANDOS_NT,
    COMANDOS_AUX_1_NT,
    COMANDOS_AUX_2_NT,
    COMANDOS_AUX_3_NT,
    EXPR_ITER_NT,
    EXPRESSAO_NT,
    VARIAVEL_NT,
    VARIAVEL_AUX_NT,
    EXPRESSAO_AUX_NT,
    EXPRESSAO_SIMPLES_NT,
    EXPRESSAO_SIMPLES_AUX_NT,
    TERMO_NT,
    TERMO_AUX_NT,
    FATOR_NT,
    FATOR_AUX_NT,
    EXPR_ITER_AUX_NT,
    fim_nao_terminais,
};

#endif //LEXICO_C_UTIL_H
