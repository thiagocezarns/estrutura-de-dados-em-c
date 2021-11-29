#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_circular.h"

#define UM_MILHAO 1000000
#define DEZ_MIL 10000
#define CEM_MIL 100000


Lista* minha_lista;

struct aluno al, al_2;

int main()
{
    FILE *file;
    file = fopen("alunos.txt", "r");

    minha_lista = criar_lista();
    printf("Lista criada! \n");


    int n_matricula[CEM_MIL];
    for(int i=0; i<CEM_MIL; i++) {
        char name[20];
        fscanf(file, "%s %d", name, &n_matricula[i]);

        al.matricula = n_matricula[i];
        strcpy(al.nome, name);
        al.n1 = 6.5;
        al.n2 = 8.2;
        al.n3 = 5.4;
        inserir_lista_ordenada(minha_lista,al);
    }
    fclose(file);

    for(int i=0; i<CEM_MIL; i++) {
        busca_lista_mat(minha_lista, n_matricula[i], &al_2);
    }

    //imprimir_lista(minha_lista);

    liberar_lista(minha_lista);

    printf("A lista foi liberada!");
}
