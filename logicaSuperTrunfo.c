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

    // Cadastro das cartas (reaproveitado do nível anterior)
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

    // Calculos adicionais
    float dens1 = pop1 / area1;
    float dens2 = pop2 / area2;

    // Menu interativo
    int opcao;
    printf("\n--- Escolha o atributo para comparacao ---\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\n--- Comparacao de Cartas ---\n");

    switch(opcao) {
        case 1: // População
            printf("Atributo: Populacao\n");
            printf("Carta 1 - %s: %lu habitantes\n", nome1, pop1);
            printf("Carta 2 - %s: %lu habitantes\n", nome2, pop2);

            if (pop1 > pop2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (pop2 > pop1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Area\n");
            printf("Carta 1 - %s: %.2f km2\n", nome1, area1);
            printf("Carta 2 - %s: %.2f km2\n", nome2, area2);

            if (area1 > area2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (area2 > area1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("Carta 1 - %s: %.2f milhoes\n", nome1, pib1);
            printf("Carta 2 - %s: %.2f milhoes\n", nome2, pib2);

            if (pib1 > pib2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (pib2 > pib1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turisticos\n");
            printf("Carta 1 - %s: %d pontos\n", nome1, pontos1);
            printf("Carta 2 - %s: %d pontos\n", nome2, pontos2);

            if (pontos1 > pontos2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (pontos2 > pontos1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade (regra invertida)
            printf("Atributo: Densidade Demografica\n");
            printf("Carta 1 - %s: %.2f hab/km2\n", nome1, dens1);
            printf("Carta 2 - %s: %.2f hab/km2\n", nome2, dens2);

            if (dens1 < dens2) {  // aqui vence o menor valor
                printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
            } else if (dens2 < dens1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default: // opção inválida
            printf("Opcao invalida! Tente novamente.\n");
    }

    return 0;
}

