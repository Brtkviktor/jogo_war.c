#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura de dados para territorios
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Declaracao das funcoes
Territorio* criarMapa(int n);
void cadastrarTerritorios(Territorio* mapa, int n);
void exibirMapa(Territorio* mapa, int n);
void atacar(Territorio* atacante, Territorio* defensor);
void liberarMapa(Territorio* mapa);

// Funcao que cria o vetor dinamico de territorios
Territorio* criarMapa(int n) {
    Territorio* mapa = (Territorio*) calloc(n, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    return mapa;
}

// Funcao que cadastra os territorios
void cadastrarTerritorios(Territorio* mapa, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n=== Cadastro do Territorio %d ===\n", i + 1);
        printf("Nome: ");
        scanf(" %29[^\n]", mapa[i].nome);
        printf("Cor do exercito: ");
        scanf(" %9[^\n]", mapa[i].cor);
        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

// Funcao que exibe todos os territorios
void exibirMapa(Territorio* mapa, int n) {
    printf("\n=== MAPA ATUAL ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s | Cor: %s | Tropas: %d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Funcao que simula uma batalha entre dois territorios
void atacar(Territorio* atacante, Territorio* defensor) {
    srand(time(NULL));
    int dadoAtq = rand() % 6 + 1;
    int dadoDef = rand() % 6 + 1;

    printf("\n=== BATALHA ===\n");
    printf("%s (%s) ataca %s (%s)\n",
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);
    printf("Dado Atacante: %d | Dado Defensor: %d\n", dadoAtq, dadoDef);

    if (dadoAtq > dadoDef) {
        printf("Vitoria do atacante!\n");
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
    } else {
        printf("O defensor resistiu ao ataque!\n");
        atacante->tropas--;
    }
}

// Funcao que libera a memoria alocada dinamicamente
void liberarMapa(Territorio* mapa) {
    free(mapa);
}

// Funcao principal com loop de turnos
int main() {
    int n;
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &n);

    Territorio* mapa = criarMapa(n);
    cadastrarTerritorios(mapa, n);
    exibirMapa(mapa, n);

    int turno = 1;
    char escolha;

    do {
        printf("\n=== TURNO %d ===\n", turno);
        int iAtq, iDef;

        printf("Escolha o numero do territorio atacante: ");
        scanf("%d", &iAtq);
        printf("Escolha o numero do territorio defensor: ");
        scanf("%d", &iDef);

        if (iAtq < 1 || iAtq > n || iDef < 1 || iDef > n) {
            printf("Numero de territorio invalido!\n");
        } else if (strcmp(mapa[iAtq - 1].cor, mapa[iDef - 1].cor) == 0) {
            printf("Voce nao pode atacar o proprio territorio!\n");
        } else {
            atacar(&mapa[iAtq - 1], &mapa[iDef - 1]);
        }

        exibirMapa(mapa, n);

        printf("\nDeseja realizar outra batalha? (s/n): ");
        scanf(" %c", &escolha);
        turno++;

    } while (escolha == 's' || escolha == 'S');

    printf("\n=== FIM DO JOGO ===\n");
    liberarMapa(mapa);
    return 0;
}