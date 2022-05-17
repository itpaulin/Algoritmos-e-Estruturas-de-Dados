#include <stdio.h>
#include <stdlib.h>

struct TFila
{
  int m;   //tamanho
  int * v; //valores
  int u; // ultimo
};

void criarFila(struct TFila *f, int n);
int  elementosNaFila(struct TFila f);
int  buscarNaFila (struct TFila  f, int x);
/*int  inserirNaFila (struct TPilha *p, int x);
int  excluirDaFila (struct TPilha *p);
void desfazerFila (struct TPilha *p); */


void main(){
    
    struct TFila f;
    int n, x, i = 1, resp;
    printf ("Digite o tamanho da fila: ");
    scanf ("%d", &n);


while ( i != 0){
printf("[1] CRIAR FILA\n");
printf("[2] ELEMENTOS NA FILA\n");
printf("[3] BUSCAR NA FILA\n");
printf("[4] INSERIR NA FILA\n");
printf("[5] EXCLUIR DA FILA\n");
printf("[6] DESFAZER FILA\n");
printf("[0] SAIR\n");
scanf ("%d",&i);

switch (i){

case 1:
    criarFila (&f, n);
    break;
case 2:
    elementosNaFila(f);
    break;
case 3:
    scanf ("%d", &x);
    buscarNaFila;
    break;
/*case 4:
    scanf ("%d", &x);
    inserirNaFila ;
    break;
case 5:
    excluirDaFila ;
    break;
case 6: 
    desfazerFila;
    break;
}
}
if (i == 0)eliminarPilha(&p);*/
}
}
}

void criarFila(struct TFila *f, int n)
{
  (*f).m  = n;
  (*f).v  = (int *)malloc(sizeof(int[n]));
}

int elementosNaFila (struct TFila f){
    return f.m;
}

int buscarNaFila (struct TFila f, int x){
    int i, busca;
    busca = -1; 
    for (i=0; i <= f.m; i++)
        if (f.v[i] == x)
        {
            busca = i;
            i = f.m + 1;
        }
        
    return busca;
}

int inserirNaFila (struct TFila *f, int x){
    int i, M;
    M = elementosNaFila(*f);
    if (M < (*f).m)
        if (buscarNaFila(*f,x) == - 1)
        {
            (*f).u = (*f).u + 1;
            (*f).v[(*f).u] = x;
            return 1;
        }
        else return 0; // elemento ja existe
    else return -1; //overflow
}
