#include <stdio.h>

/*
  Desafio Super Trunfo - Cidades (Nível Novato)
  Continuação do cadastro: agora com cálculo de métricas e comparação de um atributo.

  O programa:
    - Lê duas cartas (Estado, Código, Cidade, População, Área, PIB, Pontos Turísticos)
    - Calcula Densidade Populacional (população/área) e PIB per capita (PIB/população)
      OBS: assumimos que o PIB é informado em BILHÕES de reais. Então, para PIB per capita,
           convertemos: PIB (bilhões) * 1e9 / população.
    - Compara UM atributo escolhido no código (sem interação do usuário)
    - Para Densidade: menor vence. Para os demais: maior vence.
    - Exibe o resultado de forma clara.

  Dicas de entrada:
    - Para ler o caractere do estado sem capturar '\n', usamos " %c" (espaço antes).
    - Para nomes de cidade com espaços, use fgets. Aqui manteremos %s (cidade sem espaço)
      para simplificar, conforme nível básico.
*/

enum Atributo {
    ATR_POPULACAO = 1,
    ATR_AREA      = 2,
    ATR_PIB       = 3,
    ATR_DENSIDADE = 4,
    ATR_PIB_PC    = 5
};

/* >>> ALTERE AQUI O ATRIBUTO DA COMPARAÇÃO <<< */
#define ATRIBUTO_ESCOLHIDO ATR_POPULACAO
/* Opções:
   ATR_POPULACAO, ATR_AREA, ATR_PIB, ATR_DENSIDADE, ATR_PIB_PC
*/

int main(void) {
    /* Carta 1 */
    char estado1;
    char codigo1[4];     // 3 + '\0' (ex.: "A01")
    char cidade1[50];
    int  populacao1;
    int  pontosTuristicos1;
    float area1;
    float pib1;          // supomos em bilhões de R$

    /* Carta 2 */
    char estado2;
    char codigo2[4];
    char cidade2[50];
    int  populacao2;
    int  pontosTuristicos2;
    float area2;
    float pib2;

    /* ----- Entrada Carta 1 ----- */
    printf("\nCarta 1\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);             // espaço antes de %c ignora \n pendente

    printf("Codigo da carta (ex.: A01): ");
    scanf("%3s", codigo1);

    printf("Cidade (sem espacos p/ nivel basico): ");
    scanf("%49s", cidade1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Quantidade de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("Area (em km^2): ");
    scanf("%f", &area1);

    printf("PIB (em bilhoes de R$): ");
    scanf("%f", &pib1);

    /* ----- Entrada Carta 2 ----- */
    printf("\nCarta 2\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo da carta (ex.: B02): ");
    scanf("%3s", codigo2);

    printf("Cidade (sem espacos p/ nivel basico): ");
    scanf("%49s", cidade2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Quantidade de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    printf("Area (em km^2): ");
    scanf("%f", &area2);

    printf("PIB (em bilhoes de R$): ");
    scanf("%f", &pib2);

    /* ----- Calculos derivados ----- */
    double dens1 = (area1 > 0.0f) ? ( (double)populacao1 / (double)area1 ) : 0.0;
    double dens2 = (area2 > 0.0f) ? ( (double)populacao2 / (double)area2 ) : 0.0;

    /* PIB per capita: PIB (bilhoes) -> reais */
    double pibpc1 = (populacao1 > 0) ? ( (double)pib1 * 1e9 / (double)populacao1 ) : 0.0;
    double pibpc2 = (populacao2 > 0) ? ( (double)pib2 * 1e9 / (double)populacao2 ) : 0.0;

    /* ----- Saida formatada do cadastro ----- */
    printf("\n=== CARTAS CADASTRADAS ===\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km^2\n", area1);
    printf("PIB: %.2f bilhoes de R$\n", pib1);
    printf("Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km^2\n", dens1);
    printf("PIB per capita: R$ %.2f\n", pibpc1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km^2\n", area2);
    printf("PIB: %.2f bilhoes de R$\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km^2\n", dens2);
    printf("PIB per capita: R$ %.2f\n\n", pibpc2);

    /* ----- Comparacao (atributo unico, definido em ATRIBUTO_ESCOLHIDO) ----- */
    const char* nomeAtributo = "";
    double v1 = 0.0, v2 = 0.0;
    int menorVence = 0;  // regra especial para densidade

    switch (ATRIBUTO_ESCOLHIDO) {
        case ATR_POPULACAO:
            nomeAtributo = "População";
            v1 = (double)populacao1;
            v2 = (double)populacao2;
            menorVence = 0; // maior vence
            break;
        case ATR_AREA:
            nomeAtributo = "Área (km^2)";
            v1 = (double)area1;
            v2 = (double)area2;
            menorVence = 0; // maior vence
            break;
        case ATR_PIB:
            nomeAtributo = "PIB (bilhões de R$)";
            v1 = (double)pib1;
            v2 = (double)pib2;
            menorVence = 0; // maior vence
            break;
        case ATR_DENSIDADE:
            nomeAtributo = "Densidade Populacional (hab/km^2)";
            v1 = dens1;
            v2 = dens2;
            menorVence = 1; // MENOR vence
            break;
        case ATR_PIB_PC:
            nomeAtributo = "PIB per capita (R$)";
            v1 = pibpc1;
            v2 = pibpc2;
            menorVence = 0; // maior vence
            break;
        default:
            printf("Atributo escolhido invalido.\n");
            return 1;
    }

    printf("=== Comparacao de cartas (Atributo: %s) ===\n", nomeAtributo);
    printf("Carta 1 - %s (%c): %.2f\n", cidade1, estado1, v1);
    printf("Carta 2 - %s (%c): %.2f\n", cidade2, estado2, v2);

    int vencedora = 0; // 0 = empate, 1 = carta1, 2 = carta2
    if (!menorVence) {
        if (v1 > v2)      vencedora = 1;
        else if (v2 > v1) vencedora = 2;
    } else {
        if (v1 < v2)      vencedora = 1;
        else if (v2 < v1) vencedora = 2;
    }

    if (vencedora == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (vencedora == 2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
