#include <stdio.h>

// Função recursiva para o movimento da Torre na vertical (para cima)
void moverTorreCima(int casas) {
    if (casas == 0) return;
    printf("Cima\n");
    moverTorreCima(casas - 1);
}

// Função recursiva para o movimento do Bispo na diagonal (noroeste)
void moverBispoDiagonal(int casas) {
    if (casas == 0) return;
    printf("Cima\n");
    printf("Esquerda\n");
    moverBispoDiagonal(casas - 1);
}

// Função recursiva para o movimento da Rainha na horizontal (para a direita)
void moverRainhaDireita(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverRainhaDireita(casas - 1);
}

// Movimento do Cavalo utilizando loops aninhados e controle com continue/break
void moverCavalo() {
    printf("\nMovimento do Cavalo (duas casas para cima e uma para a direita):\n");

    int maxLinha = 8;
    int maxColuna = 8;

    // A posição inicial é arbitrária (por exemplo, 4,4)
    int linhaAtual = 4;
    int colunaAtual = 4;

    for (int i = 1; i <= 2; i++) { // duas casas para cima
        linhaAtual--;

        for (int j = 1; j <= 1; j++) { // uma casa para a direita
            colunaAtual++;

            // Verifica se está dentro do tabuleiro
            if (linhaAtual < 0 || colunaAtual >= maxColuna) {
                printf("Movimento inválido: fora do tabuleiro.\n");
                break;
            }

            // Exibe o movimento
            printf("Cima\n");
            printf("Cima\n");
            printf("Direita\n");

            break; // O cavalo só se move uma vez por ciclo completo
        }
    }
}

// Bispo com recursividade + loops aninhados (diagonal para cima/esquerda)
void moverBispoComLoop(int casas) {
    printf("\nMovimento do Bispo com recursividade + loops aninhados:\n");

    for (int i = 0; i < casas; i++) { // loop externo: vertical
        for (int j = 0; j < 1; j++) { // loop interno: horizontal (uma vez por passo)
            printf("Cima\n");
            printf("Esquerda\n");
        }
    }

    // Reforçando a lógica com recursão separada
    printf("\nRecursividade complementar ao loop:\n");
    moverBispoDiagonal(casas);
}

int main() {
    int casasTorre = 3;
    int casasBispo = 2;
    int casasRainha = 4;

    printf("Movimento da Torre:\n");
    moverTorreCima(casasTorre);

    printf("\nMovimento da Rainha:\n");
    moverRainhaDireita(casasRainha);

    printf("\nMovimento do Bispo:\n");
    moverBispoComLoop(casasBispo);

    moverCavalo();

    return 0;
}
