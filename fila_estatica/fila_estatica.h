#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct fila Fila;

Fila* criar_fila();
void liberar_fila(Fila* fi);
int inserir_fila(Fila* fi, struct aluno al);
int remover_fila(Fila* fi);
int consultar_fila(Fila* fi, struct aluno *al);
int tamanho_fila(Fila* fi);
int fila_vazia(Fila* fi);
int fila_cheia(Fila* fi);
int imprimir_fila(Fila *fi);
