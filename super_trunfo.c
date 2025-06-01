#include <stdio.h>
#include <string.h>

// Definição da estrutura que representa uma carta do jogo
struct Carta {
    char estado[30];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

int main() {
    // Cadastro das cartas manualmente (como exigido no desafio nível novato)
    struct Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 2300000.00, 20};
    struct Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1182.30, 1700000.00, 15};

    // Cálculo da densidade populacional = população / área
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta2.densidade_populacional = carta2.populacao / carta2.area;

    // Cálculo do PIB per capita = PIB / população
    carta1.pib_per_capita = carta1.pib / carta1.populacao;
    carta2.pib_per_capita = carta2.pib / carta2.populacao;

    // Impressão dos dados da Carta 1
    printf("----- Carta 1 -----\n");
    printf("Cidade: %s (%s)\n", carta1.nome_cidade, carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f\n", carta1.pib);
    printf("Pontos turísticos: %d\n", carta1.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    printf("PIB per capita: %.2f\n\n", carta1.pib_per_capita);

    // Impressão dos dados da Carta 2
    printf("----- Carta 2 -----\n");
    printf("Cidade: %s (%s)\n", carta2.nome_cidade, carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f\n", carta2.pib);
    printf("Pontos turísticos: %d\n", carta2.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    printf("PIB per capita: %.2f\n\n", carta2.pib_per_capita);

    // Comparação de um atributo fixo definido no código
    // Você pode mudar o atributo abaixo para comparar outro (ex: área, PIB, etc.)

    printf("===== Comparação de cartas (Atributo: População) =====\n");
    printf("%s: %d habitantes\n", carta1.nome_cidade, carta1.populacao);
    printf("%s: %d habitantes\n", carta2.nome_cidade, carta2.populacao);

    // Lógica da comparação: maior população vence
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta1.populacao < carta2.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}

