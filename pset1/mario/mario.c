#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int height, space, i, a; //declaração do tipo das variaveis
    do
    {
        height = get_int("altura: ");
    }
    while (height < 1 || height > 8); //loop para que a resposta esteja dentro dos criterios

    for (i = 0; i < height; i++)
    {
        for (space = 0; space < height; space++) //loop que adiciona os espaços entre as #
        {
            if (i + space < height - 1) //condição que verifica se ainda terá espaço em branco
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}