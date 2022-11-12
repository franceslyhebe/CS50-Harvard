#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // Confere o numero de argumentos foi inferior a 2
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // Confere se a key tem 26 de tamanho
    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Confere se o argumento só contem letras
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }


    // Converte a key temporariamente para letras maiúsculas
    string key_upper = key;
    for (int i = 0; i < 26; i++)
    {
        key_upper[i] = toupper(key_upper[i]);
    }

    // Confere se as letras se repetem
    // Cada letra do ALFABETO tem que ser encontrada só uma vez na key
    string ALFABETO = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int matches = 0;
    for (int i = 0; i < 26; i++)
    {
        matches = 0;
        for (int j = 0; j < 26; j++)
        {
            if (ALFABETO[i] == key_upper[j])
            {
                matches++;
            }
        }

        if (matches != 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }

    string texto = get_string("Texto: "); // obtem o texto do usuário
    string cifra = texto;

    for (int i = 0, tamanho = strlen(texto); i < tamanho; i++)
    {
        // Se o caracter não for alfabético, ignora
        if (isalpha(texto[i]) == 0)
        {
            cifra[i] = texto[i];
        }
        // Subtrai 'A' ou 'a' para obter a posição na key
        else if (isupper(texto[i]))
        {
            cifra[i] = key_upper[texto[i] - 'A'];
        }
        else
        {
            cifra[i] = tolower(key_upper[texto[i] - 'a']);
        }

    }
    // Depois de tudo, mostra na tela a frase cifrada
    printf("ciphertext: %s\n", cifra);
}