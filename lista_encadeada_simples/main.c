#include <stdio.h>
#include <string.h>
#include "lista_dinamica.h"

int main() {
    Lista *lista;
    struct aluno al;

    lista = criar_lista();
    
    strcpy(al.nome, "Thiago Cezar");
    al.matricula = 2;
    al.n1 = 7.5;
    al.n2 = 8.5;
    al.n3 = 9;
    inserir_lista_ordenada(lista, al);
    
    strcpy(al.nome, "Chiva");
    al.matricula = 3;
    al.n1 = 6.8;
    al.n2 = 8.5;
    al.n3 = 7.5;
    inserir_lista_ordenada(lista, al);
    
    strcpy(al.nome, "Thigas");
    al.matricula = 1;
    al.n1 = 8;
    al.n2 = 8.5;
    al.n3 = 7.5;
    inserir_lista_ordenada(lista, al);

    imprimir_lista(lista);
    tamanho_lista(lista);
    return 0;
}
