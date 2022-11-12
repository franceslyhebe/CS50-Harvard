#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
//Declared variables
    float Dinheiro;
    int contgeral = 0;
    int cont1 = 0;
    int cont50 = 0;
    int cont25 = 0;
    int cont10 = 0;
    int cont05 = 0;
    int cont01 = 0;


    do
    {
        //FLOAT to accept fractional values or with decimal places
        Dinheiro = get_float("Digite o valor do troco: ");
    }
    // Checks if money is equal or greater than 1
    while (Dinheiro <= 0.009);

    //Converts fractional value to integer or approximate using library function math.h
    int centavos = round(Dinheiro * 100);

    while (centavos >= 25)
    {
        centavos = centavos - 25;
        contgeral++;
        cont25++;
    }
    while (centavos >= 10)
    {
        centavos = centavos - 10;
        contgeral++;
        cont10++;
    }
    while (centavos >= 5)
    {
        centavos = centavos - 5;
        contgeral++;
        cont05++;
    }
    while (centavos >= 1)
    {
        centavos = centavos - 1;
        contgeral++;
        cont01++;
    }

    //Print the full coin count report
    printf("\nVocê deve usar um total de %i moeda(s) para o troco de %.2f dóllar(s)\n....................................................................\n",
           //continuação do codigo acima
           contgeral, Dinheiro);
    printf("Sendo desse total: \n");
    printf("                   %i moeda(s) de 0,25c\n", cont25);
    printf("                   %i moeda(s) de 0,10c\n", cont10);
    printf("                   %i moeda(s) de 0,05c\n", cont05);
    printf("                   %i moeda(s) de 0,01c\n\n", cont01);

}