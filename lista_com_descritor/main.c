#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_descritor.h"

Lista *minha_lista;

struct aluno al, al2;

int main(){

    minha_lista = criar_lista();

    al.matricula = 2;
    strcpy(al.nome,"Teste Maria");
    al.n1 = 7.5;
    al.n2 = 8.2;
    al.n3 = 7.4;

    inserir_lista_ordenada(minha_lista,al);

    al.matricula = 1;
    strcpy(al.nome,"Teste Joao");
    inserir_lista_ordenada(minha_lista,al);

    al.matricula = 3;
    strcpy(al.nome,"Teste Marcela");
    inserir_lista_ordenada(minha_lista,al);

    //remover_lista(minha_lista, 2);
    //imprimir_lista(minha_lista);

    printf("\nTamanho lista: %d\n", tamanho_lista(minha_lista));

    liberar_lista(minha_lista);
    return 0;
}
