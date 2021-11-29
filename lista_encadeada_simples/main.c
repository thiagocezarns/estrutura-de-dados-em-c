#include <stdio.h>
#include <string.h>
#include "lista_dinamica.h"

int main() {
    Lista *lista;
    Aluno al, al2, al3;

    lista = criar_lista();
    
    strcpy(al.nome, "Thiago Cezar");
    al.matricula = 1;
    al.nota1 = 7.5;
    al.nota2 = 8.5;
    al.nota3 = 9;
    inserir_lista_ordenada(lista, al);
    
    strcpy(al2.nome, "Chiva");
    al2.matricula = 3;
    al2.nota1 = 6.8;
    al2.nota2 = 8.5;
    al2.nota3 = 7.5;
    inserir_lista_ordenada(lista, al2);
    
    strcpy(al3.nome, "Thigas");
    al3.matricula = 2;
    al3.nota1 = 8;
    al3.nota2 = 8.5;
    al3.nota3 = 7.5;
    inserir_lista_ordenada(lista, al3);

    imprimir_lista(lista);
    tamanho_lista(lista);
    return 0;
}
