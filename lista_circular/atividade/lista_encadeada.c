#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

struct no{
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
        No* no;
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

int inserir_lista_inicio(Lista *li, Aluno al){
    if (li == NULL)
        return 0;
    No* novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dados = al;
    novo_no->prox = (*li);
    *li = novo_no;
    return 1;
}

int inserir_lista_final(Lista *li, Aluno al){
    if (li == NULL)
        return 0;
    No *novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dados = al;
    novo_no->prox = NULL;
    if((*li) == NULL){
        *li = novo_no;
    } else {
        No *aux;
        aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo_no;
    }
    return 1;
}

int inserir_lista_ordenada(Lista* li, Aluno al){
    if (li == NULL)
        return 0;
    No* novo_no;
    novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;
    novo_no->dados = al;
    if((*li) == NULL){
        novo_no->prox = NULL;
        *li = novo_no;
        return 1;
    } else{
        No *ant, *atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            novo_no->prox = (*li);
            *li = novo_no;
        } else {
            novo_no->prox = atual;
            ant->prox = novo_no;
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
    free(no);
    return 1;
}

int remover_lista_final(Lista* li){
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;

    No *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remover_lista(Lista* li, int mat){
    if (li == NULL)
        return 0;
    if ((*li) == NULL)
        return 0;

    No *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if (no == NULL)
        return 0;

    if (no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int busca_lista_mat(Lista* li, int mat, Aluno *al){
    if (li == NULL)
        return 0;
    No *no = *li;
    while(no != NULL && no->dados.matricula != mat)
        no = no->prox;
    if (no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

void imprimir_lista(Lista* li){
    if (li == NULL)
        printf("Lista vazia\n");
    No* ler_no = (*li);
    printf("-------------\n");
    while(ler_no != NULL){
        printf("Matricula: %d\n", ler_no->dados.matricula);
        printf("Nome: %s\n", ler_no->dados.nome);
        printf("Notas: %2.1f %2.1f %2.1f\n", ler_no->dados.n1, ler_no->dados.n2, ler_no->dados.n3);
        printf("-------------\n");
        ler_no = ler_no->prox;
    }
}

int converte_lista_encadeada_para_circular(Lista *li) {
    if(li == NULL || (*li) == NULL)
        return 0;
    No *no = (*li);
    while(no->prox != NULL) {
        no = no->prox;
    }
    no->prox = (*li);
    return 1;
}

Lista* concatenar_listas_e_transformar_em_circular(Lista *li1, Lista *li2) {
    if(li1 == NULL || (*li1) == NULL)
        return 0;
    if(li2 == NULL || (*li2) == NULL)
        return 0;
    Lista *nova_lista = criar_lista();
    No *no_aux; 

    no_aux = (*li1);
    while(no_aux != NULL) {
        inserir_lista_final(nova_lista, no_aux->dados);
        no_aux = no_aux->prox;
    }
    no_aux = (*li2);
    while(no_aux != NULL) {
        inserir_lista_final(nova_lista, no_aux->dados);
        no_aux = no_aux->prox;
    }

    No *no_final = (*nova_lista);
    while(no_final->prox != NULL) {
        no_final = no_final->prox;
    }
    no_final->prox = (*nova_lista);
    return nova_lista;
}

int troca_posicao_no(Lista *li, int p1, int p2) {
    if(li == NULL || (*li) == NULL)
        return 0;
    if(p1 == p2)
        return 0;
    if(p1 == 1 && p2 == 1)
        return 0;

    if(p1 == 1 || p2 == 1) {
        //Pega o primeiro elemento da lista.
        No *no = (*li);
        while(no->prox != (*li)) {
            no = no->prox;
        }
        No *no_anterior_inicio = no;
        No *no_inicio = no_anterior_inicio->prox;
        //
        
        //Pega o elemento na posicao da lista que for diferente da primeira posicao. Esse eh o elemento que recebeu valor diferente de 1 na chamada da funcao.
        int p;
        if(p1 != 1)
            p = p1;
        else
            p = p2;
        
        No *no_p2, *no_anterior_p2 = (*li);
        for(int i=1; i<(p-1); i++) {
            no_anterior_p2 = no_anterior_p2->prox;
        }
        no_p2 = no_anterior_p2->prox; 
        No no_aux_p2 = (*no_p2);
        //

        //Faz a troca de posicao dos no's
        (*li) = no_anterior_p2->prox;
        (*li)->prox = no_inicio->prox;
        no_anterior_p2->prox = no_anterior_inicio->prox;
        no_inicio->prox = no_aux_p2.prox;
        no_anterior_inicio->prox = (*li);
        //

    } else {

        //Pega o no que esta na posicao p1 da lista
        No *no_p1, *no_anterior_p1 = (*li);
        for(int i=1; i<(p1-1); i++) {
            no_anterior_p1 = no_anterior_p1->prox;
        }
        no_p1 = no_anterior_p1->prox; 
        No aux_no_anterior_p1 = (*no_anterior_p1);
        //

        //Pega o no que esta na posicao p2 da lista
        No *no_p2, *no_anterior_p2 = (*li);
        for(int i=1; i<(p2-1); i++) {
            no_anterior_p2 = no_anterior_p2->prox;
        }
        no_p2 = no_anterior_p2->prox; 
        No no_aux_p2 = (*no_p2);
        //

        //Faz a troca de posicao dos no's
        no_anterior_p1->prox = no_anterior_p2->prox;
        no_p2->prox = no_p1->prox;
        no_anterior_p2->prox = aux_no_anterior_p1.prox;
        no_p1->prox = no_aux_p2.prox;
        //
    }
    return 1;
}

int imprimir_lista_circular(Lista* li) {
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
    }while(ler_no != (*li));
    return 1;
}
