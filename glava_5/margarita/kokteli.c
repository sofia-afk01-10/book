#include <stdio.h>

typedef union {
    float lemon;
    int lime_pieces;
} lemon_lime;

typedef struct {
    float tequila;
    float cointreau;
    lemon_lime citrus;
} margarita;

int main() 
{
    
    margarita m1 = {2.0, 1.0, {2.0}};
    printf("--- Рецепт 1 ---\n");
    printf("%2.1f порции текилы\n%2.1f порции куантро\n%2.1f порции сока\n\n", m1.tequila, m1.cointreau, m1.citrus.lemon);

    margarita m2 = {2.0, 1.0, {0.5}};
    printf("--- Рецепт 2 ---\n");
    printf("%2.1f порции текилы\n%2.1f порции куантро\n%2.1f порции сока\n\n", m2.tequila, m2.cointreau, m2.citrus.lemon);

    margarita m3 = {2.0, 1.0, {.lime_pieces = 1}};
    printf("--- Рецепт 3 ---\n");
    printf("%2.1f порции текилы\n%2.1f порции куантро\n%i кусочек лайма\n", m3.tequila, m3.cointreau, m3.citrus.lime_pieces);

    return 0;
}
