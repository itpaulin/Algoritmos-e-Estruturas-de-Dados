#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


int inserirFila(struct Node** head_ref, int new_data){

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->data  = new_data; // DATA NAO ARMAZENAR DADO E PASSAR PARA O NOVO N�

    new_node->next = NULL; // ULTIMO SER NULO

    if (*head_ref == NULL) // se a fila estiver vazia esse ser� o cabe�alho
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;

return 1;
}

void imprimeFila(struct Node* n){

    while (n != NULL) {
        printf(" %d \n", n->data);
        n = n->next;
    }
} 

void excluirFila(struct Node** head_ref){

    struct Node *temp = *head_ref, *prev;
        *head_ref = temp->next; // mudando o cabe�alho pro proximo depois do primeiro
        free(temp); // liberando memoria "excluindo"
        return printf("exclu�do com sucesso.");
}





int main()
{
    int i= -1;
    int x;
    struct Node* head = NULL;

while (i != 0){

    printf("\n###FILA JA CRIADA###\n [1] INSERIR UM NUMERO\n [2] IMPRIMIR FILA\n [3] EXCLUIR NOH\n [0] SAIR\n");
    scanf("%d", &i);
    switch (i)
{
case 1:
    scanf ("%d", &x);
    inserirFila(&head, x);
    break;
case 2:
    imprimeFila(head);
    break;
case 3:
    excluirFila(&head);
    break;

}
}
    return 0;
}
