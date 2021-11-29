#include <stdio.h>
#include "float_vetor.h"

int main() {
    FloatVetor *v = criar_float_vetor(10);
    inserir_no_final(v, 2.0);
    inserir_no_final(v, 3.5);
    inserir_no_final(v, 4.8);
    inserir_no_final(v, 9.3);
    inserir_no_final(v, 1.8);
    inserir_na_posicao(v, 6.6, 4);
    imprimir(v);

    deletar_float_vetor(&v);
    imprimir(v);
    printf("lk;ajd;a");

    return 0;
}
