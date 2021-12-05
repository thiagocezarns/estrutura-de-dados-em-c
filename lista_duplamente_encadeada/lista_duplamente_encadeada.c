#include <stdio.h>
#include <stdlib.h>
#include "lista_duplamente_encadeada.h"

struct no{
    struct no *ant;
    struct aluno dados;
    struct no *prox;
};

typedef struct no No;

Lista* criar_lista(){
    Lista * li = (Lista*) malloc (sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void liberar_lista(Lista* li){
    if (li != NULL){
        No *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li){
    if (li == NULL)
        return 0;
    int cont = 0;
    No* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(Lista* li){
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}

int inserir_lista_inicio(Lista *li, struct aluno al){
    if (li == NULL)
        return 0;
    No* novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
   novo_no->dados = al;
   novo_no->prox = (*li);
   novo_no->ant = NULL;
   if (*li != NULL)
       (*li)->ant = novo_no;
   *li = novo_no;
   return 1;
}

int inserir_lista_final(Lista *li, struct aluno al){
    if (li == NULL)
        return 0;
    No *novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dados = al;
    novo_no->prox = NULL;
    if((*li) == NULL){
        novo_no->ant = NULL;
        *li = novo_no;
    } else {
        No *aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo_no;
        novo_no->ant = aux;
    }
    return 1;
}

int inserir_lista_ordenada(Lista* li, struct aluno al){
    if (li == NULL)
        return 0;
    No* novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dados = al;
    if((*li) == NULL){ //lista vazia
        novo_no->prox = NULL;
        novo_no->ant = NULL;
        *li = novo_no;
        return 1;
    }else{
        No *anterior, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            anterior = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            novo_no->ant = NULL;
            (*li)->ant = novo_no;
            novo_no->prox = (*li);
            *li = novo_no;
        }else{
            novo_no->prox = anterior->prox;
            novo_no->ant = anterior;
            anterior->prox = novo_no;
            if (atual != NULL)
                atual->ant = novo_no;
        }
        return 1;
    }
}

int remover_lista_inicio(Lista* li){
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;
    No *no = *li;
    *li = no->prox;
    if (no->prox != NULL)
        no->prox->ant = NULL;
    free(no);
    return 1;
}

int remover_lista_final(Lista* li){
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;

    No *no = *li;
    while(no->prox != NULL)
        no = no->prox;

    if(no->ant == NULL)
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return 1;
}

int remover_lista(Lista* li, int mat){
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;

    No *no = *li;
    while(no != NULL && no->dados.matricula != mat)
        no = no->prox;
    if (no == NULL)
        return 0;

    if(no->ant == NULL)
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if(no->prox != NULL)
        no->prox->ant = no->ant;

    free(no);
    return 1;
}

int busca_lista_mat(Lista* li, int mat, struct aluno *al){
    if (li == NULL)
        return 0;
    No *no = *li;
    while (no != NULL && no->dados.matricula != mat)
        no = no->prox;
    if (no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int imprimir_lista(Lista* li){
    if (li == NULL){
       printf("Lista vazia\n");
       return 0;
    }
    No* ler_no = (*li);
    printf("-------------\n");
    do{
        printf("Matricula: %d\n", ler_no->dados.matricula);
        printf("Nome: %s\n", ler_no->dados.nome);
        printf("Notas: %2.1f %2.1f %2.1f\n", ler_no->dados.n1, ler_no->dados.n2, ler_no->dados.n3);
        printf("-------------\n");
        ler_no = ler_no->prox;
    }while(ler_no != NULL);
    return 1;
 }
