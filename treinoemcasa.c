#include <stdio.h>
#include <stdlib.h>

struct TAlimento
{
    char nome;  // nome do alimento
    float kcal; // caloria que ele possui
};

struct TDieta
{
    char listaDeAlimentos[20]; // uma lista dos alimentos
    int totalAlimentos;        // FOR para contar quantos alimentos tem na lista acima
    float Tkcal;               // TOTAL de kcal
};

void criarDieta(struct TDieta *d)
{
    
}

int main()
{
    int i = -1;

    while (i != 0)
    {
        printf("###DIETA###\n 1- Criar dieta.\n 2- Inserir alimento na dieta.\n 3- Imprimir resumo da dieta, com a lista de alimentos e o total de calorias.\n 4- Sair\nSelecione uma opcao: ");
        scanf("%d", &i);

        switch (i)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            i = 0;
            break;
        }
    }
}

