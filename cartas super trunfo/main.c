#include <stdio.h>
#include <stdlib.h>

#define MAX_CARTAS 100

typedef struct {
    char estado[3];
    int codigo;
    char nomeCidade[50];
    long populacao;
    double pib;
    double area;
    int pontosTuristicos;
    double densidadePopulacional;
    double pibPerCapita;
} CartaCidade;

// Função para calcular densidade populacional e PIB per capita
void calcularPropriedades(CartaCidade *carta) {
    if (carta->area > 0) {
        carta->densidadePopulacional = carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0;
    }

    if (carta->populacao > 0) {
        carta->pibPerCapita = carta->pib / carta->populacao;
    } else {
        carta->pibPerCapita = 0;
    }
}

// Função para exibir uma carta
void exibirCarta(CartaCidade carta) {
    printf("\n--- CARTA DA CIDADE ---\n");
    printf("Código: %d\n", carta.codigo);
    printf("Nome: %s\n", carta.nomeCidade);
    printf("Estado: %s\n", carta.estado);
    printf("População: %ld\n", carta.populacao);
    printf("PIB: R$ %.2f\n", carta.pib);
    printf("Área: %.2f km²\n", carta.area);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
}

int main() {
    CartaCidade cartas[MAX_CARTAS];
    int qtd, i;

    printf("Quantas cartas deseja cadastrar? ");
    scanf("%d", &qtd);

    if (qtd > MAX_CARTAS || qtd <= 0) {
        printf("Número inválido.\n");
        return 1;
    }

    for (i = 0; i < qtd; i++) {
        printf("\n--- Cadastro da carta %d ---\n", i + 1);

        printf("Código: ");
        scanf("%d", &cartas[i].codigo);

        printf("Nome da cidade: ");
        getchar(); // limpar buffer
        fgets(cartas[i].nomeCidade, sizeof(cartas[i].nomeCidade), stdin);
        cartas[i].nomeCidade[strcspn(cartas[i].nomeCidade, "\n")] = '\0'; // remover newline

        printf("Estado (ex: SP): ");
        scanf("%s", cartas[i].estado);

        printf("População: ");
        scanf("%ld", &cartas[i].populacao);

        printf("PIB (em reais): ");
        scanf("%lf", &cartas[i].pib);

        printf("Área (em km²): ");
        scanf("%lf", &cartas[i].area);

        printf("Número de pontos turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        // Cálculos derivados
        calcularPropriedades(&cartas[i]);
    }

    printf("\n=== CARTAS REGISTRADAS ===\n");
    for (i = 0; i < qtd; i++) {
        exibirCarta(cartas[i]);
    }

    return 0;
}
