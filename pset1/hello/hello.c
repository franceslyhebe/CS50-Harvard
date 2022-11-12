#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("Qual é o seu nome?"); //pede um nome ao usuario e guarda a resposta na str
    printf("Olá, %s\n", answer);//Imprimi uma frase e um nome

    printf("Hello World \n");//imprimi apenas hello world
}