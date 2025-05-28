#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[50];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

// Exibe os atributos da carta
void exibirCarta(Carta c) {
    printf("\nCarta: %s\n", c.nome);
    printf("1. Força: %d\n", c.forca);
    printf("2. Velocidade: %d\n", c.velocidade);
    printf("3. Inteligência: %d\n", c.inteligencia);
}

// Comparação por atributo único
void compararPorAtributoUnico(Carta jogador, Carta maquina, int atributo) {
    int valJogador, valMaquina;

    switch (atributo) {
        case 1:
            valJogador = jogador.forca;
            valMaquina = maquina.forca;
            break;
        case 2:
            valJogador = jogador.velocidade;
            valMaquina = maquina.velocidade;
            break;
        case 3:
            valJogador = jogador.inteligencia;
            valMaquina = maquina.inteligencia;
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    printf("\n--- Resultado da Comparação ---\n");
    printf("Sua carta: %d\n", valJogador);
    printf("Carta do oponente: %d\n", valMaquina);

    if (valJogador > valMaquina)
        printf("Você venceu!\n");
    else if (valJogador < valMaquina)
        printf("Você perdeu!\n");
    else
        printf("Empate!\n");
}

// Comparação com múltiplos atributos e lógica composta
void compararMultiplosAtributos(Carta jogador, Carta maquina) {
    printf("\n--- Comparação com múltiplos atributos ---\n");
    printf("Critérios: Você vence se tiver:\n");
    printf("- Força > máquina E Inteligência >= máquina\n");

    int venceu = 0;

    if (jogador.forca > maquina.forca && jogador.inteligencia >= maquina.inteligencia) {
        venceu = 1;
    } else if (jogador.velocidade > maquina.velocidade || jogador.inteligencia > maquina.inteligencia) {
        // Caso alternativo com lógica diferente
        venceu = 2;
    }

    printf("\nSua carta:\n");
    exibirCarta(jogador);
    printf("\nCarta do oponente:\n");
    exibirCarta(maquina);

    if (venceu == 1)
        printf("\nVocê venceu com superioridade!\n");
    else if (venceu == 2)
        printf("\nVocê tem alguma vantagem, mas não venceu com todos critérios.\n");
    else
        printf("\nVocê perdeu ou não cumpriu os critérios principais.\n");
}


// NOVO: comparação baseada em dois atributos com operador ternário
void compararDoisAtributos(Carta jogador, Carta maquina) {
    int attr1, attr2;
    int somaJogador = 0, somaMaquina = 0;

    printf("\nEscolha dois atributos para comparar:\n");
    printf("1. Força\n2. Velocidade\n3. Inteligência\n");

    printf("Primeiro atributo: ");
    scanf("%d", &attr1);
    printf("Segundo atributo: ");
    scanf("%d", &attr2);

    // Função interna para obter valor do atributo
    int valor(Carta c, int attr) {
        if (attr == 1) return c.forca;
        if (attr == 2) return c.velocidade;
        if (attr == 3) return c.inteligencia;
        return 0;
    }

    // Soma os dois atributos escolhidos
    somaJogador = valor(jogador, attr1) + valor(jogador, attr2);
    somaMaquina = valor(maquina, attr1) + valor(maquina, attr2);

    exibirCarta(jogador);
    exibirCarta(maquina);

    printf("\nSoma dos atributos escolhidos:\n");
    printf("Sua carta: %d\n", somaJogador);
    printf("Carta do oponente: %d\n", somaMaquina);

    // Operador ternário para decisão
    somaJogador > somaMaquina ? 
        printf("Você venceu com dois atributos!\n") :
        (somaJogador < somaMaquina ? 
            printf("Você perdeu com dois atributos.\n") :
            printf("Empate na soma dos atributos.\n"));
}

int main() {
    srand(time(NULL));

    // Cartas disponíveis
    Carta cartas[] = {
        {"Dragão", 90, 60, 70},
        {"Cavaleiro", 70, 80, 60},
        {"Mago", 50, 40, 90},
        {"Gigante", 95, 30, 40}
    };

    int total = sizeof(cartas) / sizeof(Carta);
    Carta jogador = cartas[rand() % total];
    Carta maquina = cartas[rand() % total];

    while (&jogador == &maquina) {
        maquina = cartas[rand() % total];
    }

    int opcao, atributo;

    printf("=== SUPER TRUNFO ===\n");
    exibirCarta(jogador);

    printf("\nMenu de comparação:\n");
    printf("1. Comparar por atributo único\n");
    printf("2. Comparar com múltiplos atributos (Força + Inteligência)\n");
    printf("3. Comparar com dois atributos à escolha (Usando operador ternário)\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("\nEscolha o atributo:\n1. Força\n2. Velocidade\n3. Inteligência\n");
            printf("Sua escolha: ");
            scanf("%d", &atributo);
            compararPorAtributoUnico(jogador, maquina, atributo);
            break;

        case 2:
            compararMultiplosAtributos(jogador, maquina);
            break;

        case 3:
            compararDoisAtributos(jogador, maquina);
            break;

        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
