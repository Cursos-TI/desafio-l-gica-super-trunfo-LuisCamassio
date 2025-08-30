#include <stdio.h>

int main() {
    // Variáveis das cartas
    char estado1, codigo1[4], nome1[30];
    unsigned long pop1;
    float area1, pib1;
    int pontos1;

    char estado2, codigo2[4], nome2[30];
    unsigned long pop2;
    float area2, pib2;
    int pontos2;

    // Entrada das cartas (reaproveitado dos níveis anteriores)
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

    // Cálculos adicionais
    float dens1 = pop1 / area1;
    float dens2 = pop2 / area2;
    float pibCap1 = (pib1 * 1000000) / pop1;
    float pibCap2 = (pib2 * 1000000) / pop2;

    // Menu de atributos
    int opcao1, opcao2;
    printf("\n--- Escolha o 1º atributo ---\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("6 - PIB per Capita\n");
    printf("Opcao: ");
    scanf("%d", &opcao1);

    printf("\n--- Escolha o 2º atributo (diferente do primeiro) ---\n");
    for (int i = 1; i <= 6; i++) {
        if (i != opcao1) {
            switch(i) {
                case 1: printf("1 - Populacao\n"); break;
                case 2: printf("2 - Area\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turisticos\n"); break;
                case 5: printf("5 - Densidade Demografica\n"); break;
                case 6: printf("6 - PIB per Capita\n"); break;
            }
        }
    }
    printf("Opcao: ");
    scanf("%d", &opcao2);

    // Função para pegar valores de atributos
    float v1a, v2a, v1b, v2b; // valores de carta1 e carta2 para os 2 atributos

    // Atributo 1
    switch(opcao1) {
        case 1: v1a = pop1; v2a = pop2; break;
        case 2: v1a = area1; v2a = area2; break;
        case 3: v1a = pib1; v2a = pib2; break;
        case 4: v1a = pontos1; v2a = pontos2; break;
        case 5: v1a = dens1; v2a = dens2; break;
        case 6: v1a = pibCap1; v2a = pibCap2; break;
        default: v1a = v2a = 0;
    }

    // Atributo 2
    switch(opcao2) {
        case 1: v1b = pop1; v2b = pop2; break;
        case 2: v1b = area1; v2b = area2; break;
        case 3: v1b = pib1; v2b = pib2; break;
        case 4: v1b = pontos1; v2b = pontos2; break;
        case 5: v1b = dens1; v2b = dens2; break;
        case 6: v1b = pibCap1; v2b = pibCap2; break;
        default: v1b = v2b = 0;
    }

    // Comparação considerando regra especial da densidade
    float soma1 = 0, soma2 = 0;

    // Primeiro atributo
    if (opcao1 == 5) { // Densidade (menor vence)
        soma1 += (v1a < v2a) ? 1 : 0;
        soma2 += (v2a < v1a) ? 1 : 0;
    } else {
        soma1 += (v1a > v2a) ? 1 : 0;
        soma2 += (v2a > v1a) ? 1 : 0;
    }

    // Segundo atributo
    if (opcao2 == 5) {
        soma1 += (v1b < v2b) ? 1 : 0;
        soma2 += (v2b < v1b) ? 1 : 0;
    } else {
        soma1 += (v1b > v2b) ? 1 : 0;
        soma2 += (v2b > v1b) ? 1 : 0;
    }

    // Exibindo valores comparados
    printf("\n--- Resultado da Comparacao ---\n");
    printf("Carta 1 - %s\n", nome1);
    printf("Carta 2 - %s\n", nome2);

    printf("\nAtributo 1 escolhido: %.2f (Carta1) x %.2f (Carta2)\n", v1a, v2a);
    printf("Atributo 2 escolhido: %.2f (Carta1) x %.2f (Carta2)\n", v1b, v2b);

    printf("\nSoma dos pontos -> Carta1: %.0f | Carta2: %.0f\n", soma1, soma2);

    if (soma1 > soma2) {
        printf("Resultado final: Carta 1 (%s) venceu!\n", nome1);
    } else if (soma2 > soma1) {
        printf("Resultado final: Carta 2 (%s) venceu!\n", nome2);
    } else {
        printf("Resultado final: Empate!\n");
    }

    return 0;
}


