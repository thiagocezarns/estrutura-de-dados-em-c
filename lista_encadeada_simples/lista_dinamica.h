#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

typedef struct aluno {
    char nome[20];
    int matricula;
    float nota1;
    float nota2;
    float nota3;
} Aluno;

typedef struct no No;
typedef struct lista Lista;
Lista* criar_lista();
No* criar_no(Aluno al);
void inserir_lista_final(Lista *li, Aluno al);
void imprimir_lista(Lista *li);
void tamanho_lista(Lista *li);
void inserir_lista_ordenada(Lista *li, Aluno al);

#endif
