#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição da struct Territorio
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função que simula o ataque entre dois territórios
void atacar(Territorio* atacante, Territorio* defensor) {

    // Verifica se o atacante tem tropas suficientes
    if (atacante->tropas <= 1) {
        printf("\nAtaque invalido! Tropas insuficientes.\n");
        return;
    }

    // Simulação de dados (valores de 1 a 6)
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\n--- BATALHA ---\n");
    printf("Atacante (%s - %s) rolou: %d\n", atacante->nome, atacante->cor, dadoAtacante);
    printf("Defensor (%s - %s) rolou: %d\n", defensor->nome, defensor->cor, dadoDefensor);

    // Regra do combate
    if (dadoAtacante > dadoDefensor) {
        printf("Atacante venceu!\n");

        // Calcula metade das tropas do atacante
        int tropasTransferidas = atacante->tropas / 2;

        // Transfere domínio (cor)
        strcpy(defensor->cor, atacante->cor);

        // Atualiza tropas
        defensor->tropas = tropasTransferidas;
        atacante->tropas -= tropasTransferidas;

    } else {
        printf("Defensor venceu!\n");

        // Atacante perde uma tropa
        atacante->tropas--;
    }
}

// Função para mostrar o estado atual dos territórios
void mostrarTerritorios(Territorio* mapa, int n) {
    printf("\n--- ESTADO DOS TERRITORIOS ---\n");

    for (int i = 0; i < n; i++) {
        printf("[%d] %s | Cor: %s | Tropas: %d\n",
               i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Função para liberar memória alocada dinamicamente
void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

int main() {

    // Inicializa a semente do gerador aleatório
    srand(time(NULL));

    int n;

    printf("Quantidade de territorios: ");
    scanf("%d", &n);

    // Alocação dinâmica com calloc
    Territorio* mapa = (Territorio*) calloc(n, sizeof(Territorio));

    // Verificação de erro de memória
    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Cadastro dos territórios
    for (int i = 0; i < n; i++) {
        printf("\nTerritorio %d\n", i);

        printf("Nome: ");
        scanf("%s", mapa[i].nome);

        printf("Cor do exercito: ");
        scanf("%s", mapa[i].cor);

        printf("Numero de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }

    int atk, def;

    // Mostra territórios antes do ataque
    mostrarTerritorios(mapa, n);

    // Escolha do atacante e defensor
    printf("\nIndice do atacante: ");
    scanf("%d", &atk);

    printf("Indice do defensor: ");
    scanf("%d", &def);

    // 🔴 VALIDAÇÃO IMPORTANTE
    if (atk == def) {
        printf("Erro: nao pode atacar o mesmo territorio!\n");
    }
    else if (strcmp(mapa[atk].cor, mapa[def].cor) == 0) {
        printf("Erro: nao pode atacar territorio da mesma cor!\n");
    }
    else {
        // Chamada da função de ataque usando ponteiros
        atacar(&mapa[atk], &mapa[def]);
    }

    // Mostra resultado após ataque
    mostrarTerritorios(mapa, n);

    // Liberação da memória
    liberarMemoria(mapa);

    return 0;
}
