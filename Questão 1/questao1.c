#include <stdio.h>

// Implementação da função que calcula a soma dos elementos do array
int soma_array(int array[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma;
}


int main() {
    
    int n;
    scanf("%d", &n);
    int array[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int soma = soma_array(array, n);

    printf("A soma dos elementos do array é: %d\n", soma);

    return 0;
}
