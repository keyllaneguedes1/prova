#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 27

// Função para calcular o tamanho da string
int calcularTamanho(const char *str) {
    int tamanho = 0;
    while (str[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}

// Função para criptografar a palavra
void criptografarPalavra(const char *palavra, const char *chave, char *resultado) {
    int i = 0;
    while (palavra[i] != '\0') {
        if (isupper(palavra[i])) {
            resultado[i] = toupper(chave[palavra[i] - 'A']);
        } else if (islower(palavra[i])) {
            resultado[i] = tolower(chave[palavra[i] - 'a']);
        } else {
            resultado[i] = palavra[i];
        }
        i++;
    }
    resultado[i] = '\0'; // Adiciona o terminador de string
}

int main() {
    char chave[MAX_SIZE];
    char palavra[MAX_SIZE];
    char palavraCriptografada[MAX_SIZE];

    while (1) {
        printf("Chave de criptografia (26 letras): ");
        scanf("%26s", chave);

        if (calcularTamanho(chave) != 26) {
            printf("A chave de criptografia informada não contém 26 letras.\n");
        } else {
            printf("Informe a palavra que deseja criptografar: ");
            scanf("%26s", palavra);
            
            criptografarPalavra(palavra, chave, palavraCriptografada);
            
            printf("\nPalavra normal: %s\n", palavra);
            printf("Palavra criptografada: %s\n", palavraCriptografada);
            break;
        }
    }
    return 0;
}
