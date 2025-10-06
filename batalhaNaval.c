#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0};

    // Tamanho fixo dos navios
    int tamanho_navio = 3;

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 1, colunaHorizontal = 0; 
    int linhaVertical = 0, colunaVertical = 4;     

    // Posiciona navio horizontal (valor 3)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // Posiciona navio vertical (valor 3)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

    return 0;
}
