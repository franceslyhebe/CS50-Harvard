#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Solicite o valor inicial ao usuário
    int initial;
    do
    {
          initial = get_int("Start size: ");
    }
    while (initial < 9);
     // TODO: Solicite o valor final ao usuário
     int final;
     do
     {
        final = get_int("End size: ");
     }
    while (initial > final);
     // TODO: Calcule o número de anos até o limite
     if (initial == final) //condiçao para caso o inicial seja igual ao final
     {
          printf("Years: %i\n", 0);
     }
     else
     {
        int year = 0;//laço para contabilizar os anos
          do
          {
               initial = initial + (initial / 3) - (initial  / 4);
               year++;
          }
          while (initial < final);

          printf("Years: %i\n", year);
     }

     // TODO: Imprima o número de anos


}