#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
} Aluno;

typedef struct no* Lista;

Lista* criar_lista();
void liberar_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int inserir_lista_inicio(Lista *li, Aluno al);
int inserir_lista_final(Lista* li, Aluno al);
int inserir_lista_ordenada(Lista *li, Aluno al);
int remover_lista_inicio(Lista* li);
int remover_lista_final(Lista* li);
int busca_lista_mat(Lista* li, int mat, Aluno *al);
void imprimir_lista(Lista* li);
int converte_lista_encadeada_para_circular(Lista *li);
Lista* concatenar_listas_e_transformar_em_circular(Lista *li1, Lista *li2);
int troca_posicao_no(Lista *li, int p1, int p2);
int imprimir_lista_circular(Lista* li);

#endif
