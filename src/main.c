#include <stdio.h>
#include "lista.h"

// Função para comparar inteiros
int int_cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main(int argc, char** argv) {
    Lista minhaLista;
    int dados[] = {10, 20, 30, 40, 50};
    Lista_new(&minhaLista, sizeof(int), NULL);

    printf("Inserindo elementos no final da lista...\n");
    for (int i = 0; i < 5; i++) {
        Lista_pushBack(&minhaLista, &dados[i]);
    }

    printf("Tamanho da lista após inserções: %d\n", Lista_size(&minhaLista));
    printf("Elementos na lista: ");
    Lista_first(&minhaLista);
    int temp;
    do {
        Lista_current(&minhaLista, &temp);
        printf("%d ", temp);
    } while (Lista_next(&minhaLista));
    printf("\n");

    printf("Inserindo 5 na frente...\n");
    int novoInicio = 5;
    Lista_pushFront(&minhaLista, &novoInicio);

    printf("Elementos na lista após inserir na frente: ");
    Lista_first(&minhaLista);
    do {
        Lista_current(&minhaLista, &temp);
        printf("%d ", temp);
    } while (Lista_next(&minhaLista));
    printf("\n");

    printf("Procurando o número 30 na lista...\n");
    int chave = 30;
    int encontrado;
    if (Lista_search(&minhaLista, &chave, &encontrado, int_cmp)) {
        printf("Elemento encontrado: %d\n", encontrado);
    } else {
        printf("Elemento não encontrado.\n");
    }

    printf("Removendo o número 30 da lista...\n");
    Lista_remove(&minhaLista, &chave, int_cmp);
    printf("Elementos na lista após remoção: ");
    Lista_first(&minhaLista);
    do {
        Lista_current(&minhaLista, &temp);
        printf("%d ", temp);
    } while (Lista_next(&minhaLista));
    printf("\n");

    printf("Inserindo 35 após o primeiro elemento...\n");
    int novoDado = 35;
    Lista_first(&minhaLista);
    Lista_insertAfter(&minhaLista, &novoDado);

    printf("Elementos na lista após inserção após o primeiro: ");
    Lista_first(&minhaLista);
    do {
        Lista_current(&minhaLista, &temp);
        printf("%d ", temp);
    } while (Lista_next(&minhaLista));
    printf("\n");

    Lista_delete(&minhaLista);
    return 0;
}

