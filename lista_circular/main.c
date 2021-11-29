#include <stdio.h>
#include <string.h>
#include "lista_circular.h"

int main() {

    Lista *minha_lista;
    Aluno al;

    minha_lista = criar_lista();
    
    strcpy(al.nome, "Thiago Cezar");
    al.matricula = 1;
    al.nota1 = 7.8;
    al.nota2 = 7.5;
    al.nota3 = 8.2;
    inserir_lista_final(minha_lista, al);

    strcpy(al.nome, "Chiva");
    al.matricula = 2;
    al.nota1 = 8;
    al.nota2 = 7.5;
    al.nota3 = 9.2;
    inserir_lista_final(minha_lista, al);

    imprimir_lista(minha_lista);
    return 0;
}
