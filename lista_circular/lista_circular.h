#include <stdio.h>
#include <stdlib.h>

#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

#endif
typedef struct no* Lista;

Lista* criar_lista();
void liberar_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int inserir_lista_inicio(Lista *li, struct aluno al);
int inserir_lista_final(Lista* li, struct aluno al);
int inserir_lista_ordenada(Lista *li, struct aluno al);
int remover_lista_inicio(Lista* li);
int remover_lista_final(Lista* li);
int remover_lista(Lista* li, int mat);
int busca_lista_mat(Lista* li, int mat, struct aluno *al);
int imprimir_lista_circular(Lista* li);
int troca_posicao_no(Lista *li, int p1, int p2);
int converte_lista_encadeada_para_circular(Lista *li);
Lista* concatenar_listas_encadeadas_e_transformar_em_circular(Lista *li1, Lista *li2);
