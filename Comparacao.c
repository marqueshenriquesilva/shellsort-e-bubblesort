#define TF 5000 // Tamanho do vetor
#define MAX 32767 // Tamanho máximo dos elementos do vetor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int exibe_menu(void);
void cria(int vetor[TF]);
void exibe(int vetor[TF]);
void bubble_sort(int vetor[TF]);
void shell_sort(int vetor[TF]);

int main(void)
{
    int vetor[TF];
    int opcao = 0;
    clock_t begin, end;

    system("cls");
    printf("\n--- COMPARACAO ENTRE SHELL SORT E BUBBLE SORT ---\n\n");

    while (opcao != 5)
    {
        system("pause");
        system("cls");
        exibe_menu();
        printf("Digite opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
            case 1:
                // Inicializa vetor com numeros aleatorios
                cria(vetor);
                printf("Vetor inicializado\n");
                break;
            case 2:
                // Exibe vetor completo
                exibe(vetor);
                break;
            case 3:
                // Ordena vetor com Shell Sort
                begin = clock();
                shell_sort(vetor);
                end = clock();
                printf("VETOR ORDENADO COM SUCESSO\n");

                // Exibe tempo decorrido na ordenacao do vetor
                printf("TEMPO:\n");
                printf("%f segundos\n", (double)(end - begin) / CLOCKS_PER_SEC);
                break;
            case 4:
                // Ordena vetor com Bubble Sort
                begin = clock();
                bubble_sort(vetor);
                end = clock();
                printf("VETOR ORDENADO COM SUCESSO\n");

                // Exibe tempo decorrido na ordenacao do vetor
                printf("TEMPO:\n");
                printf("%f segundos\n", (double)(end - begin) / CLOCKS_PER_SEC);
                break;
            case 5:
                // Sair do programa
                printf("Saindo do programa...\n");
                break;
            default:
                // Usuario digita opcao invalida
                printf("ERRO: Opcao invalida!\n");
                break;
        }
    }
}

int exibe_menu(void)
{
    // Exibe opcoes do menu
    printf("1. Inicializar vetor de tamanho %d\n", TF);
    printf("2. Exibir vetor\n");
    printf("3. Ordenar vetor com Shell Sort\n");
    printf("4. Ordenar vetor com Bubble Sort\n");
    printf("5. Sair\n");
}

void cria(int vetor[TF])
{
    // Cria vetor com numeros aleatorios
    srand(time(NULL));
    for (int i = 0; i < TF; i++)
    {
        vetor[i] = rand() % MAX;
    }
}

void exibe(int vetor[TF])
{
    // Exibe todos os elementos do vetor
    for (int i = 0; i < TF; i++)
    {
        printf("%d ",vetor[i]);
    }
    printf("\n");
}

void bubble_sort(int vetor[TF])
{
    // Ordena lista usando o algoritmo bubble sort
    int i, j, temp;
    for (i = 0; i < TF-1; i++)
    {
        for (j = 0; j < TF-i-1; j++)
        {
            if (vetor[j] > vetor[j+1])
            {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

void shell_sort(int vetor[TF])
{
    // Ordena lista usando o algoritmo shell sort
    int h, i, j, t;

    // Intervalo de subvetores
    for (h = TF; h /= 2;)
    {
        // Insertion sort com intervalo
        for (i = h; i < TF; i++)
        {
            t = vetor[i];
            for (j = i; j >= h && t < vetor[j - h]; j -= h)
            {
                vetor[j] = vetor[j - h];
            }
            vetor[j] = t;
        }
    }
}
