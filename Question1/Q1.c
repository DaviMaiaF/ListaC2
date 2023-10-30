#include <stdio.h>

int main() {
    int valores[10];
    int novoConjunto[10];
    int tamanhoConjunto = 10;

    for (int i = 0; i < tamanhoConjunto; i++) {
        scanf("%d", &valores[i]);
    }

    // Imprimir os valores de entrada
    for (int i = 0; i < tamanhoConjunto; i++) {
        printf("%d", valores[i]);
        if (i < tamanhoConjunto - 1) {
            printf(" ");
        }
    }
    printf("\n");

    // Realizar a conta até restar um número
    while (tamanhoConjunto > 1) {
        for (int i = 0; i < tamanhoConjunto - 1; i++) {
            novoConjunto[i] = valores[i] + valores[i + 1];
        }
        
        tamanhoConjunto--;

        // Próximo conjunto
        for (int i = 0; i < tamanhoConjunto; i++) {
            printf("%d", novoConjunto[i]);
            if (i < tamanhoConjunto - 1) {
                printf(" ");
            }
        }
        printf("\n");

        // Copiar o novo conjunto e retornar para o conjunto original
        for (int i = 0; i < tamanhoConjunto; i++) {
            valores[i] = novoConjunto[i];
        }
    }

    return 0;
}
