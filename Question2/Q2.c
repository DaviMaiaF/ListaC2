#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Struct de dados jogador
struct Jogador {
    char nome[30];
    char posicao;
    double forca;
};

// Struct de dados time
struct Time {
    char nome[30];
    struct Jogador jogadores[11];
};

// calcular a força do time
double calcularForcaTotal(struct Time time) {
    double forcaTotal = 0;
    for (int i = 0; i < 11; i++) {
        char posicao = time.jogadores[i].posicao;
        double forca = time.jogadores[i].forca;  

        if (posicao == 'G') {
            forcaTotal += 8.00 * forca;
        } else if (posicao == 'L') {
            forcaTotal += 10.00 * forca;
        } else if (posicao == 'Z') {
            forcaTotal += 5.00 * forca;
        } else if (posicao == 'V') {
            forcaTotal += 8.00 * forca;
        } else if (posicao == 'M') {
            forcaTotal += 11.00 * forca;
        } else if (posicao == 'A') {
            forcaTotal += 12.00 * forca;
        }
    }

    forcaTotal /= 100.00;

    return forcaTotal;
}

int main() {
    struct Time time1, time2;

    // Dados Time 1
    scanf(" %29[^\n]", time1.nome);
    for (int i = 0; i < 11; i++) {
        char jogador_info[100];
        scanf(" %99[^\n]", jogador_info);

        sscanf(jogador_info, "%[^;];%c;%lf", time1.jogadores[i].nome, &time1.jogadores[i].posicao, &time1.jogadores[i].forca);
    }

    // Dados Time 2
    scanf(" %29[^\n]", time2.nome); 
    for (int i = 0; i < 11; i++) {
        char jogador_info[100];
        scanf(" %99[^\n]", jogador_info);

        sscanf(jogador_info, "%[^;];%c;%lf", time2.jogadores[i].nome, &time2.jogadores[i].posicao, &time2.jogadores[i].forca);
    }

// Retorno da fomula
    double forcaTime1 = calcularForcaTotal(time1);
    double forcaTime2 = calcularForcaTotal(time2);

  printf("%s: %.2lf de forca\n", time1.nome, forcaTime1);
  printf("%s: %.2lf de forca\n", time2.nome, forcaTime2);

    if (forcaTime1 > forcaTime2) {
        printf("%s eh mais forte\n", time1.nome);
    } else if (forcaTime1 < forcaTime2) {
        printf("%s eh mais forte\n", time2.nome);
    } else {
        printf("Os times têm a forca igual a %.2f\n", forcaTime1);
    }

    return 0;
}
