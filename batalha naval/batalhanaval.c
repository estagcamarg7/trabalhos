#include <stdio.h>

#define TAM_TAB 10
#define TAM_HAB 5

// Função para inicializar o tabuleiro com água (0) e alguns navios (3)
void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Exemplos de navios (posição fixa)
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[6][5] = 3;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ "); // Água
            else if (tabuleiro[i][j] == 3)
                printf("N "); // Navio
            else if (tabuleiro[i][j] == 5)
                printf("* "); // Área de habilidade
        }
        printf("\n");
    }
}

// Cria a matriz Cone
void criarCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Cria a matriz Cruz
void criarCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Cria a matriz Octaedro (losango)
void criarOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

// Sobrepõe matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB], int habilidade[TAM_HAB][TAM_HAB], int origemX, int origemY) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int x = origemX + i - TAM_HAB / 2;
            int y = origemY + j - TAM_HAB / 2;

            // Verifica se está dentro dos limites do tabuleiro
            if (x >= 0 && x < TAM_TAB && y >= 0 && y < TAM_TAB) {
                if (habilidade[i][j] == 1 && tabuleiro[x][y] != 3) {
                    tabuleiro[x][y] = 5; // Marca área de habilidade, sem sobrescrever navios
                }
            }
        }
    }
}

// Função principal
int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    int habilidade[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    // Demonstração da Habilidade em Cone
    criarCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 3, 3); // Ponto de origem no tabuleiro
    printf("Habilidade: Cone\n");
    exibirTabuleiro(tabuleiro);

    // Resetar tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Demonstração da Habilidade em Cruz
    criarCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 5, 5);
    printf("\nHabilidade: Cruz\n");
    exibirTabuleiro(tabuleiro);

    // Resetar tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Demonstração da Habilidade em Octaedro
    criarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4);
    printf("\nHabilidade: Octaedro\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
