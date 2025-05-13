#include <stdio.h>

// Estrutura para representar uma carta de cidade
struct Carta {
    char estado[50];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Função para cadastrar uma carta
void cadastrarCarta(struct Carta *carta) {
    printf("Digite o código da carta: ");
    scanf("%s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome); // para aceitar espaços

    printf("Digite o estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir os dados de uma carta
void exibirCarta(struct Carta carta) {
    printf("\n--- Dados da Cidade ---\n");
    printf("Código: %s\n", carta.codigo);
    printf("Nome: %s\n", carta.nome);
    printf("Estado: %s\n", carta.estado);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

// Função para comparar cartas com base na densidade populacional
void compararCartas(struct Carta a, struct Carta b) {
    float densidadeA = a.populacao / a.area;
    float densidadeB = b.populacao / b.area;

    printf("\nComparando as cartas com base na DENSIDADE POPULACIONAL (menor valor vence):\n");
    printf("Densidade da cidade 1 (%s): %.2f habitantes/km²\n", a.nome, densidadeA);
    printf("Densidade da cidade 2 (%s): %.2f habitantes/km²\n", b.nome, densidadeB);

    if (densidadeA < densidadeB) {
        printf("🏆 A cidade vencedora é: %s (menor densidade populacional)\n", a.nome);
    } else if (densidadeB < densidadeA) {
        printf("🏆 A cidade vencedora é: %s (menor densidade populacional)\n", b.nome);
    } else {
        printf("⚖️ Empate! Ambas têm a mesma densidade populacional.\n");
    }
}

int main() {
    struct Carta cidade1, cidade2;

    printf("Cadastro da carta da CIDADE 1:\n");
    cadastrarCarta(&cidade1);

    printf("\nCadastro da carta da CIDADE 2:\n");
    cadastrarCarta(&cidade2);

    exibirCarta(cidade1);
    exibirCarta(cidade2);

    compararCartas(cidade1, cidade2);

    return 0;
}
