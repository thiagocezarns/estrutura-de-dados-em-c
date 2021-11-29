#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

typedef struct aluno {
    char nome[40];
    int matricula;
    float nota1;
    float nota2;
    float nota3;
} Aluno;
typedef struct no *Lista;
typedef struct no No;

Lista* criar_lista();
int inserir_lista_final(Lista *li, Aluno al);
int imprimir_lista(Lista *li);
int tamanho_lista(Lista *li);

#endif
