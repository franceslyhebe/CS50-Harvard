#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
//Declarando as variaveis
    int letras = 0;
    int palavras = 1;
    int frases = 0;
    float resultado;

//Capturar texto do usuário
    string s = get_string("Insira seu texto: ");

//cria um loop verificando todos caracteres do texto
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //verifica se o caractere é alguma letra maiuscula ou minuscula
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            letras++;
        }
        //verifica se o caractere é um espaço (o que significa que acabou uma palavra)
        else if (s[i] == ' ')
        {
            palavras++;
        }
        //verifica se o caractere é algum tipo de pontuação, para contar as frases
        else if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            frases++;
        }
    }

//Calcula a quantidade de letras e frases para cada 100 palavras
    float letrasm = ((float) letras / palavras) * 100;
    float frasesm = ((float) frases / palavras) * 100;

//Coleman
    resultado = ((0.0588 * letrasm) - (0.296 * frasesm) - 15.8);

    int a = (int) round(resultado);

    if (a < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (a > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.i\n", a);
    }
}