#include <stdio.h>
#include <locale.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.
 
int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura a localização para português, problemas com acentuação no virtual studio code do pc

    /* Definindo as variáveis dos dados da primeira carta do Super Trunfo */
    char estado1;
    char codigo1[50], cidade1[50];
    int populacao1, turismo1;
    float area1, pib1;

    /* Definindo as variáveis dos dados da segunda carta do Super Trunfo */
    char estado2;
    char codigo2[50], cidade2[50];
    int populacao2, turismo2;
    float area2, pib2;

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
    scanf("%d", &populacao1);

    printf("Digite a área do estado (em km²): ");
    scanf(" %f", &area1);

    printf("Digite o PIB do estado (em bilhões): ");
    scanf("%f", &pib1);

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
    scanf("%d", &populacao2);

    printf("Digite a área do estado (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB do estado (em bilhões): ");
    scanf("%f", &pib2);

    printf("Digite a quantidade de pontos turísticos da cidade: ");
    scanf("%d", &turismo2);
    
    /* Exibindo os dados da primeira carta do Super Trunfo */
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %c0%s\n", estado1, codigo1);
    printf("Cidade: %s", cidade1);
    printf("População: %d habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", pib1);
    printf("Pontos Turísticos: %d\n", turismo1);

    /* Exibindo os dados da segunda carta do Super Trunfo */
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %c0%s\n", estado2, codigo2);
    printf("Cidade: %s", cidade2);
    printf("População: %d habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", pib2);
    printf("Pontos Turísticos: %d\n", turismo2);

    return 0;

}    