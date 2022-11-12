#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Numero maximo de candidatos
#define MAX 9

// Tipo que Candidato vai receber
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array de candidatos com base na estrutura de tipo criada acima
candidate candidates[MAX];

// Numero de candidatos
int candidate_count;

// Declarando tipo das funções
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Checar o numero minimo de candidatos
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Array com os candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX) //checar numero maximo de canditato
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Laço que percorre os votos
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Checar caso o nome seja inválido
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Mostrar o vencedor
    print_winner();
}

// Atualização dos votos
bool vote(string name)
{
   for (int i = 0; i < candidate_count ; i++) //Laço para percorrer cada nome votado
    {
        if (strcmp(name, candidates[i].name) == 0) //strcmp vai comparar os nomes e se forem iguais, atualiza os votos
        {
            candidates[i].votes++; //Atualiza os votos de cada candidato
            return true;
        }
    }
    return false;
}

// Imprimi os vencedores
void print_winner(void)
{
    int winner = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > winner) //Procura o candidato que teve maior numero de votos
        {
            winner = candidates[i].votes; //Substitui o candidato até encontrar o que tem o mairo numero de votos
        }
    }
    for (int o = 0; o < candidate_count; o++)
    {
        if (candidates[o].votes == winner)
        {
            printf("%s\n", candidates[o].name); //imprimi o vencedor dos vencedores
        }
    }
}

