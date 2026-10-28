
#include <stdio.h>
#include <string.h>

#define TOTAL 10

typedef struct {
    char nome[50];
    float valor;
} Despesa;

// Mostra todas as despesas.
void mostrarDespesas(Despesa despesas[], int tamanho) {
    int i = 0;

    while (i < tamanho) {
        printf("%d. %-20s R$ %.2f\n",
               i + 1, despesas[i].nome, despesas[i].valor);
        i++;
    }
}

// Bubble Sort: compara despesas vizinhas e troca
// quando a primeira tem valor maior que a segunda.
void bubbleSort(Despesa despesas[], int tamanho) {
    int i = 0;

    while (i < tamanho - 1) {
        int j = 0;

        while (j < tamanho - 1 - i) {
            if (despesas[j].valor > despesas[j + 1].valor) {
                Despesa auxiliar = despesas[j];
                despesas[j] = despesas[j + 1];
                despesas[j + 1] = auxiliar;
            }
            j++;
        }
        i++;
    }
}

// Quick Sort: usa um pivo para separar os valores
// menores e maiores e ordenar as partes da lista.
void quickSort(Despesa despesas[], int inicio, int fim) {
    int i = inicio;
    int j = fim;
    float pivo = despesas[(inicio + fim) / 2].valor;

    while (i <= j) {
        while (despesas[i].valor < pivo) {
            i++;
        }

        while (despesas[j].valor > pivo) {
            j--;
        }

        if (i <= j) {
            Despesa auxiliar = despesas[i];
            despesas[i] = despesas[j];
            despesas[j] = auxiliar;
            i++;
            j--;
        }
    }

    if (inicio < j) {
        quickSort(despesas, inicio, j);
    }

    if (i < fim) {
        quickSort(despesas, i, fim);
    }
}

int main(void) {
    Despesa despesas[TOTAL];
    Despesa copia[TOTAL];
    int i = 0;

    printf("=== ORGANIZACAO DE DESPESAS PESSOAIS ===\n");
    printf("Digite 10 despesas para organizar.\n\n");

    // O usuario informa o nome e o valor de cada despesa.
    while (i < TOTAL) {
        printf("Digite o nome da despesa %d: ", i + 1);
        fgets(despesas[i].nome, 50, stdin);

        // Remove a quebra de linha do nome digitado.
        despesas[i].nome[strcspn(despesas[i].nome, "\n")] = '\0';

        printf("Digite o valor da despesa: R$ ");
        scanf("%f", &despesas[i].valor);
        getchar();

        i++;
        printf("\n");
    }

    printf("\nDespesas antes da ordenacao:\n");
    mostrarDespesas(despesas, TOTAL);

    // Faz uma copia para os dois algoritmos usarem
    // os mesmos dados originais.
    i = 0;

    while (i < TOTAL) {
        copia[i] = despesas[i];
        i++;
    }

    bubbleSort(despesas, TOTAL);

    printf("\nOrdenacao pelo Bubble Sort:\n");
    mostrarDespesas(despesas, TOTAL);

    quickSort(copia, 0, TOTAL - 1);

    printf("\nOrdenacao pelo Quick Sort:\n");
    mostrarDespesas(copia, TOTAL);

    return 0;
}
