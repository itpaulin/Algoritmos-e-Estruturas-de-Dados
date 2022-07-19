#include <stdlib.h>
#include <stdio.h>

void merge(int arr[], int lista, int meio, int fim)
{

    int i, j, k;               // auxiliares
    int n1 = meio - lista + 1; // primeiro sub array
    int n2 = fim - meio;       // segundo subarray

    int L[n1], R[n2]; // criando array temporarios

    // Passando os dados para os array temporarios
    for (i = 0; i < n1; i++)
        L[i] = arr[lista + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    i = 0;     // Início pelo INDEX do primeiro subarray
    j = 0;     // Início pelo INDEX do segundo subarray
    k = lista; // Inicio pelo INDEX do merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copiando os elementos restantes no array L temporário caso exista
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Mesma coisa com o F
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/* e is for esquerda index and d is direita index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int e, int d)
{
    if (e < d)
    {
        /* o mesmo que (e+d)/2 porém evitando overflow*/
        int m = e + (d - e) / 2;

        // Ordenar a primeira e a segunda metade
        mergeSort(arr, e, m);
        mergeSort(arr, m + 1, d);

        merge(arr, e, m, d);
    }
}

void printArray(int A[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    /* Numeros Sortidos
    int already_sorted[] = {117, 90, 88, 83, 81, 77, 74, 69, 64, 63, 51,
                            50, 49, 42, 41, 34, 32, 29, 28, 22, 16, 8, 6, 5, 3, 1};
    int already_sorted_sized = sizeof(already_sorted) / sizeof(already_sorted[22]);

    printArray(already_sorted, already_sorted_sized);

    mergeSort(already_sorted, 0, already_sorted_sized - 1);

    printf("\nMergeSort \n");
    printArray(already_sorted, already_sorted_sized);
    */
    /* Sequencia perfeita invertida
    int inversed[] = {117, 90, 88, 83, 81, 77, 74, 69, 64, 63, 51,
                      50, 49, 42, 41, 34, 32, 29, 28, 22, 16, 8, 6, 5, 3, 1};

    int inversed_size = sizeof(inversed) / sizeof(inversed[26]);
    printArray(inversed, inversed_size);

    mergeSort(inversed, 0, inversed_size - 1);

    printf("\n Agora MergeSort: \n");
    printArray(inversed, inversed_size);
    */
    /* Sequencia repetida
     int repeated[] = {7, 7, 7, 7, 7, 1, 1, 9, 9, 0, 4, 4, 4, 5, 4, 5, 7, 1};

     int repeated_size = sizeof(repeated) / sizeof(repeated[18]);

     printArray(repeated, repeated_size);

     mergeSort(repeated, 0, repeated_size - 1);

     printf("\nAgora MergeSort: \n");
     printArray(repeated, repeated_size);
 */
    return 0;
}
