#include <stdio.h>
#include "fila_estatica.h"


Fila *minha_fila;
struct aluno al;

int main() {
    minha_fila = criar_fila();
    
    printf("criou");
    return 0;
}
