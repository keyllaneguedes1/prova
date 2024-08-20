#include <stdio.h>
#include <math.h>

// Função para calcular o tamanho mínimo do lado do terreno
int calcular_tamanho_terreno(int area_casa, int percentual) {
    // Calcula a área mínima necessária do terreno
    double area_necessaria = (double)area_casa / (percentual / 100.0);
    
    // Calcula o lado do terreno
    double lado_terreno = sqrt(area_necessaria);
    
    // Retorna o lado do terreno truncado para o inteiro mais próximo
    return (int)lado_terreno;
}

int main() {
    int A, B, C;

 
    while (1) {
        
        
        if (scanf("%d %d %d", &A, &B, &C) != 3 || A <= 0 || B <= 0 || C <= 0 || C > 100) {
            break;
        }
        
        if (A == 0 && B == 0 && C == 0) {
            break;
        }

        int area_casa = A * B;

        // Calcula o tamanho mínimo do terreno
        int lado_terreno = calcular_tamanho_terreno(area_casa, C);

        // Imprime o tamanho do lado do terreno
        printf("%d\n", lado_terreno);
    }

    return 0;
}
