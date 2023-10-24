#include <stdio.h>
#include <string.h>

void somaMatrizes(int matriz1[4][4], int matriz2[4][4], int resultado[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void subMatrizes(int matriz1[4][4], int matriz2[4][4], int resultado[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

void multMatrizes(int matriz1[4][4], int matriz2[4][4], int resultado[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void saidaMatriz(int matriz[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz1[4][4];
    int matriz2[4][4];
    int resultado[4][4];
    char conta[10];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    scanf("%s", conta);

    if (strcmp(conta, "soma") == 0) {
        somaMatrizes(matriz1, matriz2, resultado);
    } else if (strcmp(conta, "sub") == 0) {
        subMatrizes(matriz1, matriz2, resultado);
    } else if (strcmp(conta, "mult") == 0) {
        multMatrizes(matriz1, matriz2, resultado);
    } else {
        printf("Operação inválida.\n");
        return 1;
    }

    saidaMatriz(resultado);

    return 0;
}
