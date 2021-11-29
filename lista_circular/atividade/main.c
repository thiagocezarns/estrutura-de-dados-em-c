#include <stdio.h>
#include <string.h>
#include "lista_encadeada.h"

int main() {

    Lista *minha_lista, *outra_lista, *lista_circular;
    Aluno al;

    minha_lista = criar_lista();
    outra_lista = criar_lista();

    al.matricula = 1;
    strcpy(al.nome,"Diego Ribas");
    al.n1 = 7.5;
    al.n2 = 8.2;
    al.n3 = 7.4;
    inserir_lista_inicio(minha_lista,al);

    al.matricula = 4;
    strcpy(al.nome,"Diego Alves");
    al.n1 = 7.5;
    al.n2 = 9.2;
    al.n3 = 9.4;
    inserir_lista_final(minha_lista,al);

    al.matricula = 2;
    strcpy(al.nome,"Rodrigo Caio");
    al.n1 = 6.5;
    al.n2 = 8.2;
    al.n3 = 5.4;
    inserir_lista_ordenada(outra_lista,al);

    al.matricula = 3;
    strcpy(al.nome,"Willian Arao");
    al.n1 = 7.5;
    al.n2 = 8.2;
    al.n3 = 7.4;
    inserir_lista_inicio(outra_lista,al);

    al.matricula = 7;
    strcpy(al.nome,"Filipe Luis");
    al.n1 = 7.5;
    al.n2 = 9.2;
    al.n3 = 9.4;
    inserir_lista_final(outra_lista,al);

    al.matricula = 5;
    strcpy(al.nome,"Isla");
    al.n1 = 6.5;
    al.n2 = 8.2;
    al.n3 = 5.4;
    inserir_lista_ordenada(outra_lista,al);

    lista_circular = concatenar_listas_e_transformar_em_circular(minha_lista, outra_lista);
    imprimir_lista_circular(lista_circular);
    troca_posicao_no(lista_circular, 1, 4);
    printf("\n\n\n\n");
    imprimir_lista_circular(lista_circular);
    //printf("minha_lista: %p\n", (*minha_lista));
    //converte_lista_encadeada_para_circular(minha_lista);
    return 0;
}
