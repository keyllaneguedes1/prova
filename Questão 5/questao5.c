#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Função para calcular a pontuação de uma palavra
int calcular_pontuacao(const char *palavra) {
    // Tabela de pontuação das letras
    int tabela_pontuacao[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int pontuacao = 0;

    // Percorre cada caractere da palavra
    for (int i = 0; i < strlen(palavra); i++) {
        char letra = toupper(palavra[i]); // Converte para maiúscula
        if (letra >= 'A' && letra <= 'Z') {
            pontuacao += tabela_pontuacao[letra - 'A'];
        }
    }

    return pontuacao;
}

int main() {
    char palavra_jogador1[100];
    char palavra_jogador2[100];
    int pontuacao_jogador1, pontuacao_jogador2;

    // Solicita a palavra do Jogador 1
    printf("Jogador 1, digite sua palavra: ");
    fgets(palavra_jogador1, sizeof(palavra_jogador1), stdin);
    // Remove a nova linha da entrada
    palavra_jogador1[strcspn(palavra_jogador1, "\n")] = '\0';

    // Solicita a palavra do Jogador 2
    printf("Jogador 2, digite sua palavra: ");
    fgets(palavra_jogador2, sizeof(palavra_jogador2), stdin);
    
    palavra_jogador2[strcspn(palavra_jogador2, "\n")] = '\0';

    
    pontuacao_jogador1 = calcular_pontuacao(palavra_jogador1);
    pontuacao_jogador2 = calcular_pontuacao(palavra_jogador2);

    
    printf("Pontuação Jogador 1: %d\n", pontuacao_jogador1);
    printf("Pontuação Jogador 2: %d\n", pontuacao_jogador2);

    if (pontuacao_jogador1 > pontuacao_jogador2) {
        printf("Jogador 1 venceu!\n");
    } else if (pontuacao_jogador1 < pontuacao_jogador2) {
        printf("Jogador 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
