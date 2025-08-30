#include <stdio.h>

int main() {
    // Carta 1
    char estado1, codigo1[4], nome1[30];
    unsigned long pop1;
    float area1, pib1;
    int pontos1;

    // Carta 2
    char estado2, codigo2[4], nome2[30];
    unsigned long pop2;
    float area2, pib2;
    int pontos2;

    // Entrada Carta 1
    printf("Carta 1 - Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Codigo (ex: A01): ");
    scanf("%s", codigo1);
    printf("Cidade (nome): ");
    scanf(" %[^\n]", nome1);
    printf("Populacao (habitantes): ");
    scanf("%lu", &pop1);
    printf("Area (km2): ");
    scanf("%f", &area1);
    printf("PIB (milhoes de R$): ");
    scanf("%f", &pib1);
    printf("Pontos Turisticos (numero): ");
    scanf("%d", &pontos1);

    // Entrada Carta 2
    printf("\nCarta 2 - Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Codigo (ex: A01): ");
    scanf("%s", codigo2);
    printf("Cidade (nome): ");
    scanf(" %[^\n]", nome2);
    printf("Populacao (habitantes): ");
    scanf("%lu", &pop2);
    printf("Area (km2): ");
    scanf("%f", &area2);
    printf("PIB (milhoes de R$): ");
    scanf("%f", &pib2);
    printf("Pontos Turisticos (numero): ");
    scanf("%d", &pontos2);

    // Calculos adicionais
    float dens1 = pop1 / area1;
    float dens2 = pop2 / area2;
    float pibCap1 = (pib1 * 1000000) / pop1;
    float pibCap2 = (pib2 * 1000000) / pop2;

    // Comparação de cartas
    printf("\n--- Comparacao de Cartas (Atributo: Populacao) ---\n");
    printf("Carta 1 - %s (%c): %lu habitantes\n", nome1, estado1, pop1);
    printf("Carta 2 - %s (%c): %lu habitantes\n", nome2, estado2, pop2);

    if (pop1 > pop2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
    } else if (pop2 > pop1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
