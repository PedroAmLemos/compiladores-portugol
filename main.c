#include <string.h>
#include "lexico.h"
#include "util.h"


int main() {
    int tolken = 1;
    FILE *entry = stdin;

    fseek(entry, 0, SEEK_END); // going to the last char
    long int input_size = ftell(entry);
    fseek(entry, 0, SEEK_SET);

    while(tolken != END_OF_FILE){
        tolken = check_automata(1, stdin, input_size);
        if(tolken != WHITE_SPACE){
            printf("tolken %d\n", tolken);
        }
    }


    return 0;
}
