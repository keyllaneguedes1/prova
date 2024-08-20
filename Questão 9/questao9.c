#include <stdio.h>
#include <string.h>

// Função para verificar o vencedor
const char* verificarResultado(const char *escolhaSheldon, const char *escolhaRaj) {
    // Mapa de vitórias
    if (strcmp(escolhaSheldon, escolhaRaj) == 0) {
        return "De novo!";
    } else if (
        (strcmp(escolhaSheldon, "tesoura") == 0 && (strcmp(escolhaRaj, "papel") == 0 || strcmp(escolhaRaj, "lagarto") == 0)) ||
        (strcmp(escolhaSheldon, "papel") == 0 && (strcmp(escolhaRaj, "pedra") == 0 || strcmp(escolhaRaj, "Spock") == 0)) ||
        (strcmp(escolhaSheldon, "pedra") == 0 && (strcmp(escolhaRaj, "lagarto") == 0 || strcmp(escolhaRaj, "tesoura") == 0)) ||
        (strcmp(escolhaSheldon, "lagarto") == 0 && (strcmp(escolhaRaj, "Spock") == 0 || strcmp(escolhaRaj, "papel") == 0)) ||
        (strcmp(escolhaSheldon, "Spock") == 0 && (strcmp(escolhaRaj, "tesoura") == 0 || strcmp(escolhaRaj, "pedra") == 0))
    ) {
        return "Bazinga!";
    } else {
        return "Raj trapaceou!";
    }
}

int main() {
    int T;
    scanf("%d", &T); // Número de casos de teste
    
    for (int i = 1; i <= T; i++) {
        char escolhaSheldon[10], escolhaRaj[10];
        scanf("%s %s", escolhaSheldon, escolhaRaj); // Leitura das escolhas
        
        const char *resultado = verificarResultado(escolhaSheldon, escolhaRaj);
        printf("Caso #%d: %s\n", i, resultado);
    }
    
    return 0;
}
