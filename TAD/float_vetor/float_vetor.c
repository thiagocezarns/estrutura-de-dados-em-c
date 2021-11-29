#include <stdio.h>
#include <stdlib.h>
#include "float_vetor.h"

struct float_vetor {
    unsigned int capacidade_max;
    unsigned int qtd;
    float *vetor;
};

FloatVetor* criar_float_vetor(unsigned int capacidade_max) {
    FloatVetor *float_vetor = (FloatVetor *) calloc(1, sizeof(FloatVetor));
    float_vetor->vetor = (float *) calloc(capacidade_max, sizeof(float));
    float_vetor->capacidade_max = capacidade_max;
    return float_vetor;
}

void deletar_float_vetor(FloatVetor **float_vetor) {
    FloatVetor *fv = *float_vetor;
    free(fv->vetor);
    free(fv);
    *float_vetor = NULL;
}

int inserir_no_final(FloatVetor *float_vetor, float valor) {
    if(float_vetor->qtd == float_vetor->capacidade_max) return 0;
    float_vetor->vetor[float_vetor->qtd] = valor;
    float_vetor->qtd++;
    return 1;
}

int inserir_na_posicao(FloatVetor *float_vetor, float valor, int posicao) {
    if(float_vetor->qtd == float_vetor->capacidade_max) return 0;
    int proximo_index = float_vetor->qtd;
    int index_atual = float_vetor->qtd-1;
    while(proximo_index != posicao-1) {
        float_vetor->vetor[proximo_index] = float_vetor->vetor[index_atual];
        proximo_index--;
        index_atual--;
    }
    float_vetor->vetor[proximo_index] = valor;
    float_vetor->qtd++;
    return 1;
}

int imprimir(FloatVetor *float_vetor) {
    if(float_vetor == NULL) return 0;

    printf("Capaxidade maxima: %d\n", float_vetor->capacidade_max);
    printf("Tamanho: %d\n", float_vetor->qtd);
    for(int i=0; i<float_vetor->qtd; i++) {
        printf("valor: %f\n", float_vetor->vetor[i]);
    }
    return 1;
}
