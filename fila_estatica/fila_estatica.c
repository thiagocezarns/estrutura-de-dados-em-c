#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

struct no {
    struct aluno dados;
};

struct fila {
    int inicio;
    int fim;
    int tamanho;
    struct no nos[MAX]; 
};

Fila *criar_fila() {
    Fila *fi = (Fila *) malloc(sizeof(Fila));
    if(fi == NULL)
        return 0;

    fi->inicio = 0;
    fi->fim = 0;
    fi->tamanho = 0;

    return fi;
}

void liberar_fila(Fila *fi) {
    free(fi);
}

int inserir_fila(Fila *fi, struct aluno al) {
    if(fi == NULL)
        return 0;
    if(fi->tamnho >= MAX)
        return 0;
    fi->nos[fi->tamanho].dados = al;
    fi->tamanho++;
    return 0;
}


int consultar_fila(Fila *fi, struct aluno *al) {
    if(fi == NULL)
        return 0;
    if(fi->tamanho == 0)
        return 0;

    *al = fi->nos[inicio];

    return 1;
}

int imprimir_fila(Fila *fi) {
    if(fi == NULL)
        return 0;
    for(int i=0; i<(fi->tamanho); i++) {
        printf("\n------------------------------");
        printf("\nNome: %s", fi->nos[i].dados.nome);
        printf("\nMatricula: %d", fi->nos[i].dados.matricula);
        printf("\nNota 1: %d", fi->nos[i].dados.n1);
        printf("\nNota 2: %d", fi->nos[i].dados.n2);
        printf("\nNota 3: %d", fi->nos[i].dados.n3);
        printf("\n------------------------------\n");
    }
    return 1;
}
