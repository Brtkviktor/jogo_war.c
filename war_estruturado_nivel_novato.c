#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de dados para representar um território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    Territorio territorios[5]; // Vetor fixo com 5 territórios

    printf("=== CADASTRO DE TERRITORIOS ===\n");

    // Cadastro dos territórios
    for (int i = 0; i < 5; i++) {
        printf("\nTerritorio %d:\n", i + 1);

        printf("Nome: ");
        scanf(" %29[^\n]", territorios[i].nome);

        printf("Cor do exercito: ");
        scanf(" %9[^\n]", territorios[i].cor);

        printf("Numero de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    // Exibição dos dados cadastrados
    printf("\n=== LISTA DE TERRITORIOS CADASTRADOS ===\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s | Cor: %s | Tropas: %d\n",
               i + 1,
               territorios[i].nome,
               territorios[i].cor,
               territorios[i].tropas);
    }

    printf("\n=== FIM DO PROGRAMA ===\n");
    return 0;
}
