#include <string.h>
#include "lexico.h"
#include "util.h"
#include "pilha.h"
#include "list.h"
#include "sintatico.h"

// todo ver outro dia: erro no ultimo elemento n vai colocar mais nada programa correto
int main() {
    FILE *entry = stdin;
    Stack *stack = create_stack();
    List *list = create_list();

    int input_tolken;
    int linha = 1;
    int coluna = 1;
    int flag = 1;
    char *word = NULL;

    input_tolken = advance(1, entry, list, &linha, &coluna, &word);
    insert_stack(stack, START_NT);

    while (input_tolken!= END_OF_FILE){
        int stack_tolken = pop(stack);
        if (stack_tolken < comeco_nao_terminais && stack_tolken > comeco_terminais){
            if(input_tolken == stack_tolken){
                input_tolken = advance(1, entry, list, &linha, &coluna, &word); // implementar advance
            }else{
                printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> \'%s\'", linha, coluna, word);
                flag = 0;
                break;
            }


        }else if (stack_tolken > comeco_nao_terminais && stack_tolken < fim_nao_terminais){
            if (!parser(input_tolken, stack_tolken, stack)){ // todo implementar parser()
                printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> \'%s\'", linha, coluna, word);
                flag = 0;
                break;
            }
        }
        if(input_tolken == ERRO){
            printf("ERRO LEXICO. Linha: %d Coluna: %d -> \'%s\'", linha, coluna, word);
            flag = 0;
            break;
        }
    }

    if(flag){
        printf("PROGRAMA CORRETO.");
    }

    stack_free(stack);

    return 0;

}
