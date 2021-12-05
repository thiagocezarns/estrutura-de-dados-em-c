#include <stdio.h>
#include <stdlib.h>
#include "lista_descritor.h"

struct no{
    struct aluno dados;
    struct no *prox;
};

typedef struct no No;

struct descritor{
    struct no *inicio;
    struct no *fim;
    int tamanho;

};

Lista* criar_lista(){
    Lista * li = (Lista*) malloc (sizeof(Lista));
    if (li != NULL){
        li->inicio = NULL;
        li->fim = NULL;
        li->tamanho = 0;
    }
    return li;
}

void liberar_lista(Lista *li){
    if(li != NULL){
        No *no;
        while((li->inicio) != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    return li->tamanho;
}

int inserir_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    No* no = (No*) malloc(sizeof(No));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = li->inicio;
    if(li->inicio == NULL)
        li->fim = no;
    li->inicio = no;
    li->tamanho++;
    return 1;
}

int inserir_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    No *no = (No*) malloc(sizeof(No));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(li->inicio == NULL)
        li->inicio = no;
    else
        li->fim->prox = no;
    li->fim = no;
    li->tamanho++;
    return 1;
}


int remover_lista_inicio(Lista *li){
    if (li == NULL)
        return 0;
    if(li->inicio == NULL)
        return 0;
    No *no = li->inicio;
    li->inicio = no->prox;
    free(no);
    if(li->inicio == NULL)
        li->fim = NULL;
    li->tamanho--;
    return 1;
}

int lista_vazia(Lista *li) {
    if(li == NULL)
        return 0;

    if(li->tamanho == 0)
        return 1;

    return 0;
}

int inserir_lista_ordenada(Lista *li, struct aluno al) {
    if(li == NULL)
        return 0;

    No *no = (No*) malloc(sizeof(No));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;

    if(li->inicio == NULL) {
        li->inicio = no;
        li->fim = no;
        li->tamanho++;
        return 1;
    }

    if(al.matricula < (li->inicio)->dados.matricula) {
        no->prox = li->inicio;
        li->inicio = no;
        li->tamanho++;
        return 1;
    }


    if(al.matricula > (li->fim)->dados.matricula) {
        (li->fim)->prox = no;
        li->fim = no;
        li->tamanho++;
        return 1;
    }

    
    No *no_antecessor = li->inicio;
    No *no_aux = (li->inicio)->prox;

    while(al.matricula > no_aux->dados.matricula) {
        no_antecessor = no_aux;
        no_aux = no_aux->prox;
        if(no_aux == NULL)
            break;
    }


    no_antecessor->prox = no;
    no->prox = no_aux;

    li->tamanho++;
    return 1;
}

int remover_lista_final(Lista *li) {
    if(li == NULL)
        return 0;
    if(li->fim == NULL)
        return 0;

    if(li->fim == li->inicio){
        free(li->fim);
        li->fim = NULL;
        li->inicio = NULL;
        li->tamanho--;
        return 1;
    }

    No *no = li->inicio;

    while(no->prox != li->fim)
        no = no->prox;

    free(no->prox);
    no->prox = NULL;
    li->fim = no;
    li->tamanho--;

    return 1;
}

int remover_lista(Lista *li, int mat) {
    if(li == NULL)
        return 0;
    if(li->inicio == NULL)
        return 0;

    No *no;

    if((li->inicio)->dados.matricula == mat) {
        no = li->inicio;
        if(li->inicio == li->fim)
            li->fim = NULL;
        li->inicio = (li->inicio)->prox;
        free(no);
        li->tamanho--;
        return 1;
    }

    No *no_antecessor = li->inicio;
    no = (li->inicio)->prox;

    while(no->dados.matricula != mat) {
        no_antecessor = no;
        no = no->prox;
        if(no == NULL)
            return 0;
    }

    if(no == li->fim) {
        li->fim = no_antecessor;
    }
    no_antecessor->prox = no->prox;
    free(no);
    li->tamanho--;

    return 1;
}

int busca_lista_mat(Lista *li, int mat, struct aluno *al) {
    if(li == NULL)
        return 0;

    No *no = li->inicio;

    while(no->dados.matricula != mat) {
        no = no->prox;
        if(no == NULL)
            return 0;
    }

    *al = no->dados;
    return 1;
}

int imprimir_lista(Lista *li) {
    if(li == NULL)
        return 1;

    No *no = li->inicio;
    while(no != NULL) {
        printf("\n-----------------------");
        printf("\nNome: %s", no->dados.nome);
        printf("\nMatricula: %d", no->dados.matricula);
        printf("\nNota 1: %.2f", no->dados.n1);
        printf("\nNota 2: %.2f", no->dados.n2);
        printf("\nNota 3: %.2f", no->dados.n3);
        printf("\n-----------------------\n");

        no = no->prox;
    }

    return 1;
}
