#include <stdio.h>

int main() {
    FILE *file, *arq;
    file = fopen("alunos.txt", "r");
    long n_matricula[1000010];
    long i = 0;
    
    if(!feof(file))
        printf("entrou");

    while(!feof(file)) {
        char name[20];
        fscanf(file, "%s %ld", name, &n_matricula[i]);
        i++;
    }
    fclose(file);

    arq = fopen("numero_matricula.txt", "w");
    int j = 0;
    while(j < 1000010) {
        fprintf(arq, "%ld\n", n_matricula[j]);
        j++;
    }
    fclose(arq);

    return 0;
}
