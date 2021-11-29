#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

struct no{
    struct aluno dados;
    struct no* prox;
};

typedef struct no No;

struct fila{
    struct no *inicio;
    struct no *fim;
    int qtd;
};

Fila* criar_fila(){
    Fila* fi = (Fila*) malloc(sizeof(struct fila));
    if (fi != NULL){
        fi->inicio = NULL;
        fi->fim = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void liberar_fila(Fila *fi){
    if (fi != NULL){
        No *no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_fila(Fila* fi){
    if (fi == NULL)
        return 0;
    return fi->qtd;
}

int fila_cheia(Fila* fi){
    return 0;
}

int fila_vazia(Fila* fi){
    if (fi == NULL)
        return -1;
    if (fi->inicio == NULL)
        return 1;
    return 0;
}

int inserir_fila(Fila* fi, struct aluno al){
    if (fi == NULL)
        return 0;
    No *no = (No*) malloc(sizeof(No));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if (fi->fim == NULL)
        fi->inicio = no;
    else
        fi->fim->prox = no;
    fi->fim = no;
    fi->qtd++;
    return 1;
}

int remover_fila(Fila* fi){
    if (fi == NULL)
        return 0;
    if (fi->inicio == NULL)
        return 0;
    No* no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    free(no);
    if(fi->inicio == NULL)
        fi->fim = NULL;
    fi->qtd--;
    return 1;
}

int consultar_fila(Fila* fi, struct aluno *al){
    if (fi == NULL)
        return 0;
    if (fi->inicio == NULL)
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

Fila *copia_fila(Fila *fi) {
    if(fi == NULL)
        return 0;
    if(fi->qtd == 0)
        return 0;

    Fila *fi_copia = (Fila *) malloc(sizeof(Fila));
    if(fi_copia == NULL)
        return 0;

    No *inicio = (No*) malloc(sizeof(No));
        if(inicio == NULL)
            return 0;
    inicio->dados = (fi->inicio)->dados;
    fi_copia->inicio = inicio;
    fi_copia->qtd = fi->qtd;


    No *no_aux = (fi->inicio)->prox;;
    No *no_antecessor = fi_copia->inicio;
    
    while(no_aux != NULL) {
        No *no = (No*) malloc(sizeof(No));
        if (no == NULL)
            return 0;

        no->dados = no_aux->dados;
        no->prox = NULL;

        no_antecessor->prox = no;
        no_antecessor = no;

        if(no_aux->prox == NULL)
            fi_copia->fim = no;

        no_aux = no_aux->prox;
    }
    return fi_copia;
}
