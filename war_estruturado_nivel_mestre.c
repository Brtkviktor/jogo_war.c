#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura de dados para territórios
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Estrutura para jogadores
typedef struct {
    char nome[30];
    char* missao; // armazenada dinamicamente
} Jogador;

// Declaração das funções
Territorio* criarMapa(int n);
void cadastrarTerritorios(Territorio* mapa, int n);
void exibirMapa(Territorio* mapa, int n);
void atacar(Territorio* atacante, Territorio* defensor);
void atribuirMissao(Jogador* jogador, char* missoes[], int totalMissoes);
void exibirMissao(Jogador* jogador);
int verificarMissao(Jogador* jogador, Territorio* mapa, int n);
void liberarMapa(Territorio* mapa);

// Função: cria um vetor dinâmico de territórios
Territorio* criarMapa(int n) {
    Territorio* mapa = (Territorio*) calloc(n, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    return mapa;
}

// Função: cadastra territórios
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

// Função: exibe o mapa atual
void exibirMapa(Territorio* mapa, int n) {
    printf("\n=== MAPA ATUAL ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s | Cor: %s | Tropas: %d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Função: simula uma batalha
void atacar(Territorio* atacante, Territorio* defensor) {
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

// Função: atribui uma missão aleatória
void atribuirMissao(Jogador* jogador, char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    jogador->missao = (char*) malloc(strlen(missoes[sorteio]) + 1);
    strcpy(jogador->missao, missoes[sorteio]);
}

// Função: exibe missão do jogador
void exibirMissao(Jogador* jogador) {
    printf("\nMissao de %s: %s\n", jogador->nome, jogador->missao);
}

// Função: verifica se a missão foi cumprida
int verificarMissao(Jogador* jogador, Territorio* mapa, int n) {
    int contador = 0;

    // Exemplo de missão simples: 3 territórios vermelhos
    for (int i = 0; i < n; i++) {
        if (strcmp(mapa[i].cor, "vermelho") == 0)
            contador++;
    }

    if (strcmp(jogador->missao, "Conquistar 3 territorios vermelhos") == 0 && contador >= 3) {
        return 1; // Missão cumprida
    }
    return 0; // Ainda não cumprida
}

// Função: libera memória
void liberarMapa(Territorio* mapa) {
    free(mapa);
}

// Função principal - controle do jogo
int main() {
    srand(time(NULL)); // inicializa o gerador aleatorio

    int n;
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &n);

    Territorio* mapa = criarMapa(n);
    cadastrarTerritorios(mapa, n);
    exibirMapa(mapa, n);

    // Cadastro dos jogadores
    int numJogadores = 2;
    Jogador jogadores[numJogadores];

    for (int i = 0; i < numJogadores; i++) {
        printf("\nDigite o nome do jogador %d: ", i + 1);
        scanf(" %29[^\n]", jogadores[i].nome);
    }

    // Missoes possiveis
    char* missoes[] = {
        "Conquistar 3 territorios vermelhos",
        "Dominar todos os territorios azuis",
        "Manter 5 territorios com mais de 10 tropas"
    };
    int totalMissoes = sizeof(missoes) / sizeof(missoes[0]);

    // Sorteia missao para cada jogador
    for (int i = 0; i < numJogadores; i++) {
        atribuirMissao(&jogadores[i], missoes, totalMissoes);
        exibirMissao(&jogadores[i]);
    }

    // Loop de turnos
    int turno = 1;
    int vencedor = 0;

    do {
        printf("\n=== TURNO %d ===\n", turno);
        exibirMapa(mapa, n);

        // Verifica se algum jogador venceu
        for (int i = 0; i < numJogadores; i++) {
            if (verificarMissao(&jogadores[i], mapa, n)) {
                printf("\nJogador %s venceu cumprindo a missao: %s!\n",
                       jogadores[i].nome, jogadores[i].missao);
                vencedor = 1;
                break;
            }
        }
        if (vencedor) break;

        // Escolha dos territórios
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

        turno++;
    } while (!vencedor);

    printf("\n=== FIM DO JOGO ===\n");

    liberarMapa(mapa);
    for (int i = 0; i < numJogadores; i++) {
        free(jogadores[i].missao);
    }

    return 0;
}