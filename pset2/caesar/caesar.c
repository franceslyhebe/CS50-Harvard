#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2) //caso nao receba os dois argumentos, terá um erro
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0, arglen = strlen(argv[1]); i < arglen; i++) //Loop para conferir se o argumento é numerico
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int k = atoi(argv[1]); //converte a string em inteiro
    string t = get_string("plaintext: "); //Pegar o texto digitado pelo usuario
    string alpha = t; //Coloca o texto dentro da var alpha
    int text = strlen(t); //pegar o tamanho do texto string.length

    for (int i = 0; i < text; i++)
    {
        if (isalpha(t[i]) == 0) //verifica se a letra é igual a zero
        {
            alpha[i] = t[i];
        }
        else if (islower(t[i])) //verifica se a letra é minúscula
        {
            alpha[i] -= 'a';
            alpha[i] = (alpha[i] + k) % 26;
            alpha[i] += 'a';
        }
        else
        {
            alpha[i] -= 'A';
            alpha[i] = ((alpha[i] + k) % 26);
            alpha[i] += 'A';
        }
    }
    printf("ciphertext: %s\n", alpha); //imprimi o texto codificado
    return 0;
}