#include <stdio.h>
#include <string.h>
#include "lista_circular.h"

int main() {

    Lista *minha_lista;
    struct aluno al;

    minha_lista = criar_lista();

    al.matricula = 1;
    strcpy(al.nome,"João");
    al.n1 = 7.5;
    al.n2 = 8.2;
    al.n3 = 7.4;
    inserir_lista_inicio(minha_lista,al);

    al.matricula = 4;
    strcpy(al.nome,"Pedro");
    al.n1 = 7.5;
    al.n2 = 9.2;
    al.n3 = 9.4;
    inserir_lista_final(minha_lista,al);

    al.matricula = 2;
    strcpy(al.nome,"Maria");
    al.n1 = 6.5;
    al.n2 = 8.2;
    al.n3 = 5.4;
    inserir_lista_ordenada(minha_lista,al);

    al.matricula = 3;
    strcpy(al.nome, "Teste João");
    al.n1 = 7.5;
    al.n2 = 8.2;
    al.n3 = 7.4;
    inserir_lista_inicio(minha_lista,al);

    al.matricula = 7;
    strcpy(al.nome,"Teste Pedro");
    al.n1 = 7.5;
    al.n2 = 9.2;
    al.n3 = 9.4;
    inserir_lista_final(minha_lista,al);

    al.matricula = 5;
    strcpy(al.nome,"Teste Maria");
    al.n1 = 6.5;
    al.n2 = 8.2;
    al.n3 = 5.4;
    inserir_lista_ordenada(minha_lista,al);

    imprimir_lista_circular(minha_lista);
    troca_posicao_no(minha_lista, 1, 4);
    printf("\n\n\n\n");
    imprimir_lista_circular(minha_lista);
    //printf("minha_lista: %p\n", (*minha_lista));
    //converte_lista_encadeada_para_circular(minha_lista);
    return 0;
}
