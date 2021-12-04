
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "fila_estatica.h"

Fila* minha_fila;

struct aluno al;

int main(){

    minha_fila = criar_fila();
    al.matricula = 1;
    strcpy(al.nome,"Teste Joao");
    al.n1 = 7.5;
    al.n2 = 8.2;
    al.n3 = 7.4;
    inserir_fila(minha_fila,al);

    al.matricula = 4;
    strcpy(al.nome,"Teste Maria");
    al.n1 = 7.5;
    al.n2 = 9.2;
    al.n3 = 9.4;
    inserir_fila(minha_fila,al);

    al.matricula = 2;
    strcpy(al.nome,"Novo Joao");
    al.n1 = 6.5;
    al.n2 = 8.2;
    al.n3 = 5.4;
    inserir_fila(minha_fila,al);

    al.matricula = 3;
    strcpy(al.nome,"Novo Maria");
    al.n1 = 6.5;
    al.n2 = 8.2;
    al.n3 = 5.4;
    inserir_fila(minha_fila,al);

    printf("Insercao completa!\n");
    int n = tamanho_fila(minha_fila);
    printf("Tamanho da fila: %d\n", tamanho_fila(minha_fila));

    imprimir_fila(minha_fila);
    return 0;
}
