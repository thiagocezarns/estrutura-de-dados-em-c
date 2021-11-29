#include <stdlib.h>
#include "lista_circular.h"

struct no {
    Aluno dados;
    struct no *prox;
};

Lista* criar_lista() {
    Lista *li = (Lista *) calloc(1, sizeof(Lista));
    if(li != NULL) {
        (*li) = NULL;
    }
    
    return li;
}

No* criar_no() {
    No *novo_no = (No *) calloc(1, sizeof(No));
    if(novo_no == NULL)
        return 0;
    return novo_no;
}

int inserir_lista_final(Lista *li, Aluno al) {
    if(li == NULL)
        return 0;
    No *novo_no = criar_no();
    if(!novo_no)
        return 0;
    novo_no->dados = al;
    novo_no->prox = (*li);
    if((*li) == NULL) {
        (*li) = novo_no;
        (*li)->prox = (*li);
        return 1;
    }
    No *no_aux = (*li);
    while(no_aux->prox != (*li)) {
        no_aux = no_aux->prox;
    }
    
    no_aux->prox = novo_no;

    return 1;
}

int tamanho_lista(Lista *li) {
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    int i=1;
    No *no = (*li);
    while(no->prox != (*li)) {
        i++;
        no = no->prox;
    }
    return i;
}

int imprimir_lista(Lista *li) {
    if(li == NULL || (*li) == NULL)
        return 0;
    No *no = (*li);
    int i, qtd_no;
    qtd_no = tamanho_lista(li);
    printf("\n-------------------------\n");
    for(i=0; i<qtd_no; i++) {
        printf("\nNome: %s\n", no->dados.nome);
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nota 1: %.1f\n", no->dados.nota1);
        printf("Nota 2: %.1f\n", no->dados.nota2);
        printf("Nota 3: %.1f\n", no->dados.nota3);
        no = no->prox;
    }
    printf("\n-------------------------\n");
    return 1;
}
