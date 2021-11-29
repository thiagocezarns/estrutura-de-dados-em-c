#include <stdlib.h>
#include "lista_dinamica.h"

struct no {
    Aluno al;
    struct no *prox_no;
};

struct lista {
    int tamanho;
    No *prox_no;
};

Lista* criar_lista() {
    Lista *lista = (Lista *) calloc(1, sizeof(Lista));
    lista->prox_no = NULL;
    return lista;
}

No* criar_no(Aluno al) {
    No *no = (No *) calloc(1, sizeof(No));
    no->al = al;
    no->prox_no = NULL;
    return no;
}

void inserir_lista_final(Lista *li, Aluno al) {
    if(li->prox_no == NULL) {
        No *novo_no = criar_no(al);
        li->prox_no = novo_no;
    } else {
        No *no = li->prox_no;
        No *ultimo_no = li->prox_no;
        while(no != NULL) {
          if(no->prox_no == NULL)
          ultimo_no = no;
          no = no->prox_no;
        }
        No *novo_no = criar_no(al);
        ultimo_no->prox_no = novo_no;
    }
    li->tamanho++;
}

void inserir_lista_ordenada(Lista *li, Aluno al) {
    if(li->prox_no == NULL) {
        No *novo_no = criar_no(al);
        li->prox_no = novo_no;
    } else {
        No *no = li->prox_no;
        No *no_anterior = li->prox_no;
        while(al.matricula > no->al.matricula) {
            if(no->prox_no == NULL)
                break;
            no_anterior = no;
            no = no->prox_no;
        }
        No *novo_no = criar_no(al);
        no_anterior->prox_no = novo_no;
        novo_no->prox_no = no;
    } 
}



void imprimir_lista(Lista *li) {
    No *no = li->prox_no;
    while(no != NULL) {
        printf("Aluno: %s\n", no->al.nome);
        printf("Matricula: %d\n", no->al.matricula);
        printf("Nota 1: %.1f\n", no->al.nota1);
        printf("Nota 2: %.1f\n", no->al.nota2);
        printf("Nota 3: %.1f\n\n", no->al.nota3);
        no = no->prox_no;
    }
}

void tamanho_lista(Lista *li) {
    printf("\nTamanho da lista: %d\n", li->tamanho);
}
