#include <stdio.h>
#include <stdlib.h>

struct TPilha
{
  int m;   //tamanho
  int t;   //topo
  int * v; //valores
};

void criarPilha(struct TPilha *p, int n);
int  elementosNaPilha(struct TPilha  p);
int  buscarNaPilha(struct TPilha  p, int x);
int  inserirNaPilha(struct TPilha *p, int x);
int  excluirDaPilha(struct TPilha *p);
void eliminarPilha(struct TPilha *p);

int main()
{
    struct TPilha p;
    int n, x, i = 1, resp;
    printf ("Digite o tamanho da pilha: ");
    scanf ("%d", &n);

while ( i != 0){
printf("[1] CRIAR PILHA\n");
printf("[2] BUSCAR NA PILHA\n");
printf("[3] INSERIR NA PILHA\n");
printf("[4] EXCLUIR DA PILHA\n");
printf("[5] IMPRIMIR PILHA\n");
printf("[0] PARA SAIR\n");
scanf ("%d",&i);

switch (i){

case 1:
    criarPilha(&p, n);
    break;
case 2:
    scanf ("%d", &x);
    buscarNaPilha(p,x);
    break;
case 3:
    scanf ("%d", &x);
    inserirNaPilha(&p,x);
    break;
case 4:
    resp = excluirDaPilha (&p);
    if(resp == -1) printf("vazia");
    else if (resp == 1) printf("apagado o topo");
    break;
case 5:
    printf ("ainda não disponivel");
    break;
}
}
if (i == 0)eliminarPilha(&p);
}


void criarPilha(struct TPilha *p, int n)
{
  (*p).m  = n;
  (*p).t = -1;
  (*p).v  = (int *)malloc(sizeof(int[n]));
}

int elementosNaPilha(struct TPilha p)
{
  return p.t + 1;
}

int buscarNaPilha(struct TPilha p, int x)
{
  int i, busca;
  busca = -1; //flag para erro
  for (i=0; i <= p.t; i = i + 1)
    if (p.v[i] == x)
    {
      busca = i;
      i = p.t + 1;
    }
  return busca;
}

int inserirNaPilha(struct TPilha *p, int x)
{
  int i, M;
  M = elementosNaPilha(*p);
  if (M < (*p).m)
    if (buscarNaPilha(*p, x) == -1)
    {
      (*p).t = (*p).t + 1;
      (*p).v[(*p).t] = x;
      return 1;
    }
    else return 0; //Elemento já existe
  else return -1; //Overflow
}

int excluirDaPilha(struct TPilha *p)
{
  int i, M;
  M = elementosNaPilha(*p);
  if (M > 0)
  {
    (*p).t = (*p).t - 1;
    return 1;
  }
  else return -1; //Underflow
}

int excluirDaPilha2(struct TPilha *p, int *x)
{
  int i, M;
  M = elementosNaPilha(*p);
  if (M > 0)
  {
    *x = (*p).v[(*p).t];
    (*p).t = (*p).t - 1;
    return 1;
  }
  else return -1; //Underflow
}

void eliminarPilha(struct TPilha *p)
{
  (*p).m = 0;
  (*p).t = -1;
  free((*p).v);
}