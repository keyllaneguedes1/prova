#include <stdio.h>

// Implementação da função que multiplica duas matrizes
void multiplica_matrizes(int n, int matriz1[n][n], int matriz2[n][n], int resultado[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main() {
    
    int n;
    scanf("%d", &n);
    int matriz1[n][n], matriz2[n][n], resultado[n][n];

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    multiplica_matrizes(n, matriz1, matriz2, resultado);

    // Imprime a matriz resultante
    printf("Matriz Resultante:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}


