#include <stdio.h>
#include <math.h>

int buscaBinaria(int *vetor, int n, int busca);

int main(void) {
    int retorno, escolha;
    int lista[128];

    printf("Qual o numero que deseja buscar?\n-> ");
    scanf("%d", &escolha);

    for (int k = 0; k < 128; k++) {
        lista[k] = k * 2;  // A lista será carregada com valores.
    }

    retorno = buscaBinaria(lista, 128, escolha);
    if (retorno < 0) {
        printf("O item não foi encontrado na lista.\n");
        return 1;
    } else {
        printf("\nO item foi encontrado na %dª posição\n\n\nAqui está a lista completa..\n", retorno + 1);
        for (int k = 0; k < 128; k++) {
            printf("%d ", lista[k]);
        }
    }
    return 0;
}

int buscaBinaria(int *vetor, int n, int busca) {
    int minimo = 0, maximo = n - 1, meio, etapas = 0;

    while (minimo <= maximo) {
        meio = (minimo + maximo) / 2;
        if (vetor[meio] < busca) {
            minimo = meio + 1;
            etapas++;
        } else if (vetor[meio] > busca) {
            maximo = meio - 1;
            etapas++;
        } else {
            printf("Depois de %d etapas...\n", etapas);
            return meio;
        }
    }
    return -1;
}
