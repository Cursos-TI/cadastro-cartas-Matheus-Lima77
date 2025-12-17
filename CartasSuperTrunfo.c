#include <stdio.h>
#include <locale.h>
 
int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura a localização para português, problemas com acentuação


    /* Definindo as variáveis */
    char estado1, estado2;
    char codigo1[50], cidade1[50], codigo2[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    int turismo1, turismo2;
    float area1, area2;
    double pib1, pib2;
    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;


    /* Coletando os dados da primeira carta do Super Trunfo */
    printf ("-- Cadastro da primeira carta do Super Trunfo --\n");

    printf("Digite a primeira letra do estado: ");
    scanf(" %c", &estado1);

    while (getchar() != '\n'); // Limpando o buffer do teclado

    printf("Digite o código do estado (1 a 4): ");
    scanf(" %s", codigo1);

    while (getchar() != '\n'); // Limpando o buffer do teclado

    printf("Digite a cidade do estado: ");
    fgets(cidade1, 50, stdin);

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao1);

    printf("Digite a área do estado (em km²): ");
    scanf(" %f", &area1);

    printf("Digite o PIB do estado (em bilhões): ");
    scanf("%lf", &pib1);

    printf("Digite a quantidade de pontos turísticos da cidade: ");
    scanf("%d", &turismo1);


    /* Coletando os dados da segunda carta do Super Trunfo*/
    printf ("\n-- Cadastro da segunda carta do Super Trunfo --\n");

    printf("Digite a primeira letra do estado: ");
    scanf(" %c", &estado2);

    while (getchar() != '\n'); // Limpando o buffer do teclado

    printf("Digite o código do estado (1 a 4): ");
    scanf(" %s", codigo2);

    while (getchar() != '\n'); // Limpando o buffer do teclado

    printf("Digite a cidade do estado: ");
    fgets(cidade2, 50, stdin);

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao2);

    printf("Digite a área do estado (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB do estado (em bilhões): ");
    scanf("%lf", &pib2);

    printf("Digite a quantidade de pontos turísticos da cidade: ");
    scanf("%d", &turismo2);
    

    /* Calculando o PIB per capita e a densidade populacional*/
    densidade1 = populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000.0) / populacao1;

    densidade2 = populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000.0) / populacao2;


    /* Invertendo o valor da densidade populacional*/
    float peso_densidade1 = 1.0 / densidade1;
    float peso_densidade2 = 1.0 / densidade2;
    

    /* Calculando o Super Poder*/
    double super_poder1 = (double)populacao1 + (double)area1 + pib1 + (double)turismo1 + (double)pib_per_capita1 + peso_densidade1;
    double super_poder2 = (double)populacao2 + (double)area2 + pib2 + (double)turismo2 + (double)pib_per_capita2 + peso_densidade2;
    

    /* Exibindo os dados da primeira carta do Super Trunfo */
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %c0%s\n", estado1, codigo1);
    printf("Cidade: %s", cidade1);
    printf("População: %lu habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %lf bilhões\n", pib1);
    printf("Pontos Turísticos: %d\n", turismo1);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidade1);
    printf("PIB per capita: %.2f\n", pib_per_capita1);
    printf("Super Poder: %.2lf\n", super_poder1);

    /* Exibindo os dados da segunda carta do Super Trunfo */
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %c0%s\n", estado2, codigo2);
    printf("Cidade: %s", cidade2);
    printf("População: %lu habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %lf bilhões\n", pib2);
    printf("Pontos Turísticos: %d\n", turismo2);
    printf("Densidade Populacional: %.2f habitantes/km²\n", densidade2);
    printf("PIB per capita: %.2f\n", pib_per_capita2);
    printf("Super Poder: %.2lf\n", super_poder2);

    /* Comparando os atributos das cartas */
    printf("\nComparação das Cartas: (1= Carta %c0%s vence, 0 = Carta %c0%s vence)\n", estado1, codigo1, estado2, codigo2);

    printf("População: %d\n", populacao1 > populacao2);
    printf("Área: %d\n", area1 > area2);
    printf("PIB: %d\n", pib1 > pib2);
    printf("Pontos Turísticos: %d\n", turismo1 > turismo2);
    printf("Densidade Populacional: %d\n", densidade1 < densidade2); // Menor densidade vence
    printf("PIB per Capita: %d\n", pib_per_capita1 > pib_per_capita2);
    printf("Super Poder: %d\n", super_poder1 > super_poder2);

    
    return 0;

}