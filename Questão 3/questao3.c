#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 17

// Função para calcular a soma de verificação usando o algoritmo de Luhn
int verificarLuhn(const char *numero) {
    int soma = 0;
    int n = strlen(numero);
    
    for (int i = n - 1; i >= 0; i -= 2) {
        soma += numero[i] - '0'; // Adiciona o dígito diretamente
    }
    
    for (int i = n - 2; i >= 0; i -= 2) {
        int dobro = 2 * (numero[i] - '0');
        soma += dobro / 10 + dobro % 10; // Adiciona os dígitos do dobro
    }
    
    return soma % 10 == 0;
}

// Função para determinar a marca do cartão
const char* determinarMarca(const char *numero) {
    int n = strlen(numero);
    
    if (n == 15 && (numero[0] == '3') && (numero[1] == '4' || numero[1] == '7')) {
        return "AMEX";
    }
    
    if (n == 16 && numero[0] == '5' && (numero[1] >= '1' && numero[1] <= '5')) {
        return "MASTERCARD";
    }
    
    if ((n == 13 || n == 16) && numero[0] == '4') {
        return "VISA";
    }
    
    return "INVALID";
}

// Função para remover caracteres não numéricos
void removerCaracteresNaoNumericos(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (isdigit(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char numero[MAX_LEN + 1];

    printf("Number: ");
    if (fgets(numero, sizeof(numero), stdin) == NULL) {
        printf("INVALID\n");
        return 1;
    }
    
    numero[strcspn(numero, "\n")] = '\0';
    removerCaracteresNaoNumericos(numero);
    
    // Verifica se o número do cartão é válido
    if (verificarLuhn(numero)) {
        printf("%s\n", determinarMarca(numero));
    } else {
        printf("INVALID\n");
    }
    
    return 0;
}
