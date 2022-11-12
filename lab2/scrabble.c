#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// tabela de pontos do jogo
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word); //Declarando a funcao

int main(void)
{
    // Capturando as palavras de cada jogador
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Guardando os pontos de cada jogador baseada na funcao compute score(que faz o calculo)
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Compara e imprime o vencedor
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word) //inicio da funcao que faz o calculo
{
    int score = 0;
    for (int i = 0, tamanho = strlen(word); i < tamanho; i++)
    {
        if (isalpha(word[i]))
        {
            if (isupper(word[i]))
            {
                score += POINTS[word[i] - 'A'];
            }
            else
            {
                score += POINTS[word[i] - 'a'];
            }
        }
    }
    return score;
}