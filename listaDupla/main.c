#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_duplamente_encadeada.h"

Lista* minha_lista;

struct aluno al;

int main()
{
    FILE *file;
   file = fopen("alunos.txt", "r");

    minha_lista = criar_lista();
    printf("Lista criada! \n");

    for(int i=0; i<10000; i++) {
        char name[20];
        int id_matricula;
        fscanf(file, "%s %d", name, &id_matricula);

        al.matricula = id_matricula;
        strcpy(al.nome, name);
        al.n1 = 6.5;
        al.n2 = 8.2;
        al.n3 = 5.4;
        inserir_lista_ordenada(minha_lista,al);
    }
    fclose(file);

    imprimir_lista(minha_lista);

    liberar_lista(minha_lista);

    printf("A lista foi liberada!");
}
