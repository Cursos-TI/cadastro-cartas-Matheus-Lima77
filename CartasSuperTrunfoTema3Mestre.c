#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    /* Variáveis das Cartas */
    char estado1, estado2, codigo1[50], codigo2[50], cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    int turismo1, turismo2;
    float area1, area2;
    double pib1, pib2, densidade1, densidade2, pib_per_capita1, pib_per_capita2;

    /* Variáveis de Seleção e Comparação */
    int opcao1, opcao2;
    double valor1_atr1, valor1_atr2, valor2_atr1, valor2_atr2;
    char nome_atr1[30], nome_atr2[30];

   /* Cadastro */
    printf("-- Cadastro da Carta 1 --\n");
    printf("Estado (Letra): "); scanf(" %c", &estado1);
    printf("Código: "); scanf("%s", codigo1);
    while (getchar() != '\n');
    printf("Cidade: "); fgets(cidade1, 50, stdin);
    cidade1[strcspn(cidade1, "\n")] = 0;
    printf("População: "); scanf("%lu", &populacao1);
    printf("Área: "); scanf("%f", &area1);
    printf("PIB: "); scanf("%lf", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &turismo1);

    printf("\n-- Cadastro da Carta 2 --\n");
    printf("Estado (Letra): "); scanf(" %c", &estado2);
    printf("Código: "); scanf("%s", codigo2);
    while (getchar() != '\n');
    printf("Cidade: "); fgets(cidade2, 50, stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área: "); scanf("%f", &area2);
    printf("PIB: "); scanf("%lf", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &turismo2);

    /* Cálculos Matemáticos */
    densidade1 = (double)populacao1 / area1;
    densidade2 = (double)populacao2 / area2;
    pib_per_capita1 = (pib1 * 1000000000.0) / populacao1;
    pib_per_capita2 = (pib2 * 1000000000.0) / populacao2;

   /* MENU DINÂMICO DE ATRIBUTOS */
    printf("\n*** Escolha os atributos para o Duelo ***\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica\n6. PIB per Capita\n");
    
    printf("Primeiro Atributo: ");
    scanf("%d", &opcao1);

    printf("\nEscolha o Segundo Atributo:\n");
    // Menu Dinâmico: não mostra a opção 1
    if (opcao1 != 1) printf("1. População\n");
    if (opcao1 != 2) printf("2. Área\n");
    if (opcao1 != 3) printf("3. PIB\n");
    if (opcao1 != 4) printf("4. Pontos Turísticos\n");
    if (opcao1 != 5) printf("5. Densidade Demográfica\n");
    if (opcao1 != 6) printf("6. PIB per Capita\n");

    do {
        printf("Opção: ");
        scanf("%d", &opcao2);
        if (opcao1 == opcao2) printf("Erro: Escolha um atributo diferente do primeiro!\n");
    } while (opcao1 == opcao2);

    /* Switch */
    for (int i = 1; i <= 2; i++) {
        int op_atual = (i == 1) ? opcao1 : opcao2;
        double *v1 = (i == 1) ? &valor1_atr1 : &valor1_atr2;
        double *v2 = (i == 1) ? &valor2_atr1 : &valor2_atr2;
        char *nome = (i == 1) ? nome_atr1 : nome_atr2;

        switch (op_atual) {
            case 1: strcpy(nome, "População"); *v1 = populacao1; *v2 = populacao2; break;
            case 2: strcpy(nome, "Área"); *v1 = area1; *v2 = area2; break;
            case 3: strcpy(nome, "PIB"); *v1 = pib1; *v2 = pib2; break;
            case 4: strcpy(nome, "Turismo"); *v1 = turismo1; *v2 = turismo2; break;
            case 5: strcpy(nome, "Densidade"); *v1 = densidade1; *v2 = densidade2; break;
            case 6: strcpy(nome, "PIB p/ Cap"); *v1 = pib_per_capita1; *v2 = pib_per_capita2; break;
            default: printf("Opção Inválida!"); return 0;
        }
    }

    /* CÁLCULO DA SOMA E RESULTADO */
    double pts1 = (opcao1 == 5 ? 1/valor1_atr1 : valor1_atr1) + (opcao2 == 5 ? 1/valor1_atr2 : valor1_atr2);
    double pts2 = (opcao1 == 5 ? 1/valor2_atr1 : valor2_atr1) + (opcao2 == 5 ? 1/valor2_atr2 : valor2_atr2);

    printf("\n=================================");
    printf("\n   RESULTADO DO DUELO FINAL");
    printf("\n=================================");
    printf("\nCartas: %s vs %s", cidade1, cidade2);
    printf("\nAtributo 1 [%s]: %.2lf vs %.2lf", nome_atr1, valor1_atr1, valor2_atr1);
    printf("\nAtributo 2 [%s]: %.2lf vs %.2lf", nome_atr2, valor1_atr2, valor2_atr2);
    
    // Soma Real dos valores
    double soma_exibicao1 = valor1_atr1 + valor1_atr2;
    double soma_exibicao2 = valor2_atr1 + valor2_atr2;
    printf("\nSoma dos Atributos: %.2lf vs %.2lf", soma_exibicao1, soma_exibicao2);
    
    printf("\n---------------------------------");
    
    if (pts1 == pts2) {
        printf("\nRESULTADO: Empate!\n");
    } else {
        // Operador Ternário para exibir o vencedor
        printf("\nRESULTADO: Vencedor é %s!\n", (pts1 > pts2) ? cidade1 : cidade2);
    }
    printf("=================================\n");

    return 0;
}