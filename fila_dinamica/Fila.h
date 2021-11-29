#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct fila Fila;

Fila* criar_fila();
void liberar_fila(Fila* fi);
int consultar_fila(Fila* fi, struct aluno *al);
int inserir_fila(Fila* fi, struct aluno al);
int remover_fila(Fila* fi);
int tamanho_fila(Fila* fi);
int fila_vazia(Fila* fi);
int fila_cheia(Fila* fi);
Fila *copia_fila(Fila *fi);
