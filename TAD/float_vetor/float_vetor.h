#ifndef FLOAT_VETOR
#define FLOAT_VETOR

typedef struct float_vetor FloatVetor;

FloatVetor* criar_float_vetor(unsigned int capacidade_max);
void deletar_float_vetor(FloatVetor **float_vetor);
int inserir_no_final(FloatVetor *float_vetor, float valor);
int imprimir(FloatVetor *float_vetor);
int inserir_na_posicao(FloatVetor *float_vetor, float valor, int posicao);

#endif
