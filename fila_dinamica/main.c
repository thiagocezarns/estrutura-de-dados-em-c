#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"

Fila* minha_fila, *fil;

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
    printf("Tamanho da fila: %d\n", n);

    //liberar_fila(minha_fila);
    fil = copia_fila(minha_fila);
    liberar_fila(minha_fila);

    printf("------------\n");
    for(int i=0; i < n; i++){
        printf("Consulta %d:\n",i+1);
        consultar_fila(fil, &al);
        printf("Matricula: %d\n", al.matricula);
        printf("Nome: %s\n", al.nome);
        printf("Notas: %.2f %.2f %.2f\n",al.n1,al.n2,al.n3);
        printf("------------\n");
        remover_fila(fil);
    }

}
