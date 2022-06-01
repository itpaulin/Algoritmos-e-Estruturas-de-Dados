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
int  inserirNaFila (struct TFila *f, int x);
int  excluirDaFila (struct TFila *f);
void desfazerFila (struct TFila *f);


main(){
    int p, n, x, c;
    struct TFila fila;
    printf("Tamanho da fila: ");
    scanf("%d", &n);
    criarFila (&fila, n);
    printf(" [0] - FINALIZAR PROGRAMA \n [2] - ELEMENTOS DA FILA \n [3] - BUSCAR NA FILA \n [4] - INSERIR NA FILA \n [5] - EXCLUIR NA FILA\n [6] - ELIMAR NA FILA\n");
    while(1){
        printf("Escolha uma opcao: ");
        scanf("%d", &c);
        if(c == 0)
            break;
        else if(c==2){
            printf("elementos na fila: %d \n ", elementosNaFila(fila));
        }
        else if(c==3){
            printf("Buscar na fila: ");
            scanf("%d", &x);
            if(buscarNaFila (fila, x) == -1)
                printf("Não encontrado \n");
            else
                printf("Posicao: %d \n", buscarNaFila (fila, x));
        }
        else if(c==4){
            printf("Inserir na fila: ");
            scanf("%d", &x);
            inserirNaFila (&fila,  x);
        }
        else if(c==5){
             excluirDaFila (&fila);
        }
        else if(c==6){
            eliminarFila (&fila);
        }
    }
}

void criarFila(struct TFila *f, int n)
{
    (*f).m = n;
    (*f).u = -1;
    (*f).v = (int *)malloc(sizeof(int[n]));
}

int elementosNaFila(struct TFila f)
{
    return f.u + 1;
}
int buscarNaFila(struct TFila f, int x)
{
    int i, busca;
    busca = -1; //flag para erro
    for (i=0; i <= f.u; i = i + 1)
        if (f.v[i] == x)
        {
            busca = i;
            i = f.u + 1;
        }
    return busca;
}

int inserirNaFila (struct TFila *f, int x){
    int M;
    M = elementosNaFila(*f);
    if (M<(*f).m)
    if(buscarNaFila(*f,x) == -1){
        (*f).u= (*f).u + 1;
        (*f).v[(*f).u] = x;
        return 1;
    }
    else return 0;
    else return -1;
}

int excluirDaFila (struct TFila *f){

int i, M;
  M = elementosNaFila(*f);
  if (M > 0)
  {
      for(i=0; i < (*f).u; i++){
        (*f).v[i] = (*f).v[i+1];
      }
    (*f).u = (*f).u - 1;
    return 1;
  }
  else return -1; //Underflow
}

void eliminarFila(struct TFila *f)
{
  (*f).m = 0;
  (*f).u = -1;
  free((*f).v);
}
