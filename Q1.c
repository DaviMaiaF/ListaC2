#include <stdio.h>

int main() {
    int valores[10]; // Array para armazenar os valores de entrada
    int janela = 2;
    int tamanho = 10; // O tamanho da entrada
    int somas[10]; // Array para armazenar as somas

    // Solicitar ao usuário para inserir 10 valores
    printf("Digite 10 valores:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
    }

    // Calcular e exibir as somas das janelas deslizantes
    printf("Somas das janelas:\n");
    for (int i = 0; i < tamanho - janela + 1; i++) {
        somas[i] = 0; // Inicializa a soma para a janela atual
        for (int j = 0; j < janela; j++) {
            somas[i] += valores[i + j]; // Adiciona o valor à soma
        }
        printf("%d ", somas[i]);
    }
    printf("\n");

    // Continue reduzindo a janela até que não seja mais possível criar uma nova janela
    while (tamanho > janela) {
        for (int i = 0; i < tamanho - janela; i++) {
            somas[i] += somas[i + 1]; // Soma a próxima janela
        }

        tamanho--; // Reduz o tamanho
        printf("Somas atualizadas:\n");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", somas[i]);
        }
        printf("\n");
    }

    return 0;
}
