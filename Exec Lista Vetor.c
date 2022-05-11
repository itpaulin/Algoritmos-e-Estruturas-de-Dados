#include <stdlib.h>
#include <stdio.h>

void criarLista(int ***l, int n)
{
 int i;
 *l = (int *)malloc(sizeof(int* [n]));
 for(i=0; i < n; i = i+1)
 (*l)[i] = NULL;
}



int elementosNaLista(int ** l, int n)
{
 int i;
 for(i=0; i < n; i = i+1)
 if (l[i] == NULL) break;
 return i;
}


int buscarNaLista(int ** l, int n, int x)
{
 int i, busca;
 busca = -1; //flag para erro
 for (i=0; i < n; i = i+1)
 {
 if (l[i] == NULL) i = n;
 else if (*(l[i]) == x)
 {
 busca = i;
 i = n;
 }
 }
 return busca;
}



int inserirNaLista(int ** l, int n, int x)
{
 int i, M;
 M = elementosNaLista(l,n);
 if (M<n)
 if (buscarNaLista(l, n, x) == -1)
 {
 l[M] = (int *)malloc(sizeof(int));
 *l[M] = x;
 return 1;
 }
 else return 0; //Elemento já existe
 else return -1; //Overflow
}



int excluirDaLista(int ** l, int n, int x)
{
 int i, indice, M = elementosNaLista(l,n);
 if (M == 0) return -1; //Underflow
 else { indice = buscarNaLista(l, n, x);
 if (indice == -1) return 0; //Elemento não existe
 else {
 if (indice == n-1) { free(l[indice]);
 l[indice] = NULL;
 }
 else
 { free(l[indice]);
 for (i = indice; i < M; i = i+1) l[i] = l[i+1];
 l[M-1] = NULL;
 }
 return 1;
 }
 }
}


void imprimirLista(int ** l, int n)
{
 int i, M;
 printf("ELEMENTOS DA LISTA:\n");
 for (i = 0; i < n; i = i+1)
 if (l[i] == NULL)
 printf("NULL\n");
 else printf("%d\n", *(l[i]));
 printf("\n");
}




void limparLista(int ***l, int n)
{
 int i;
 for(i=0; i < n; i = i+1)
 if ((*l)[i] != NULL) free((*l)[i]);
 free(*l);
}

main (){
int **l, n, x, i=1;
    printf ("Digite o tamanho da lista: ");
    scanf ("%d", &n);

while ( i != 0){
printf("[1] CRIAR LISTA\n");
printf("[2] BUSCAR NA LISTA\n");
printf("[3] INSERIR NA  LISTA\n");
printf("[4] EXCLUIR DA LISTA\n");
printf("[5] IMPRIMIR LISTA\n");
printf("[0] PARA SAIR\n");
scanf ("%d",&i);

switch (i){

case 1:
    criarLista(&l, n);
    break;
case 2:
    scanf ("%d", &x);
    buscarNaLista(l,n,x);
    break;
case 3:
    scanf ("%d", &x);
    inserirNaLista(l,n,x);
    break;
case 4:
    scanf ("%d", &x);
    excluirDaLista (l, n, x);
    break;
case 5:
    imprimirLista (l, n);
    break;
}
}
if (i == 0)limparLista(l,n);
}