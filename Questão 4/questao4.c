#include <stdio.h>

int main() {
    int troco, somatotal;
    int moedas_25, moedas_10, moedas_5, moedas_1;

    // solicita a entrada válida ao usuário
    while (1) {
        printf("Troco devido: ");
        if (scanf("%d", &troco) != 1 || troco < 0) {
            // Limpar buffer de entrada
            while (getchar() != '\n');
            printf("Entrada inválida. Por favor, insira um número inteiro maior ou igual a 0.\n");
        } else {
            break;
        }
    }

    // cálculo das moedas necessárias
    moedas_25 = troco / 25;
    troco %= 25;

    moedas_10 = troco / 10;
    troco %= 10;

    moedas_5 = troco / 5;
    troco %= 5;

    moedas_1 = troco;
    
    somatotal = moedas_25 + moedas_10 + moedas_5 + moedas_1;

    printf("%d \n", somatotal);
    
    return 0;
}

