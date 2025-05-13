#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[30];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para cadastrar os dados de uma carta
void cadastrarCarta(struct Carta *carta) {
    printf("\nCadastro de nova carta:\n");

    printf("Estado: ");
    fgets(carta->estado, sizeof(carta->estado), stdin);
    strtok(carta->estado, "\n"); // Remover quebra de linha

    printf("Código da carta: ");
    fgets(carta->codigo, sizeof(carta->codigo), stdin);
    strtok(carta->codigo, "\n");

    printf("Nome da cidade: ");
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    strtok(carta->nomeCidade, "\n");

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em milhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculo da densidade populacional e PIB per capita
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;

    while (getchar() != '\n'); // Limpar o buffer
}

// Função para exibir os dados de uma carta
void exibirCarta(struct Carta carta) {
    printf("\n----------------------------\n");
    printf("Cidade: %s (%s)\n", carta.nomeCidade, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.6f\n", carta.pibPerCapita);
    printf("----------------------------\n");
}

// Função que compara as cartas com base no PIB per capita
void compararCartas(struct Carta c1, struct Carta c2) {
    printf("\nComparação de cartas (Atributo: PIB per capita):\n\n");
    printf("Carta 1 - %s: %.6f\n", c1.nomeCidade, c1.pibPerCapita);
    printf("Carta 2 - %s: %.6f\n", c2.nomeCidade, c2.pibPerCapita);

    if (c1.pibPerCapita > c2.pibPerCapita) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
    } else if (c2.pibPerCapita > c1.pibPerCapita) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }
}

int main() {
    struct Carta carta1, carta2;

    printf("Bem-vindo ao Super Trunfo de Cidades!\n");

    // Cadastro da primeira carta
    cadastrarCarta(&carta1);

    // Cadastro da segunda carta
    cadastrarCarta(&carta2);

    // Exibição das cartas
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Comparação entre as cartas
    compararCartas(carta1, carta2);

    return 0;
}
