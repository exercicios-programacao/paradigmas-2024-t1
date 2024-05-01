/**
 * Este arquivo pode ser utilizado para criar um teste rápido
 * que permita depurar a função que está atualmente sendo
 * implementada de forma mais simples.
 *
 * Para compilar apenas esse programa, utilize `make main`.
 *
 * Você pode alterar como desejar esse programa, ele não será
 * avaliado pelos testes.
 */

#include <stdio.h>
#include "lista.h"

void imprimir(Lista *lista){
    Nodo *aux = lista->primeiro;
    printf("\nLista: [");
    while(aux != NULL){
        printf(" %d,", aux->valor);
        aux = aux->prox;
    }
    printf("]");
}

int main(void) {

    Lista lista;

    Lista_new(&lista, sizeof(int), NULL);
    printf("\nLista criada!");

    if(Lista_isEmpty(&lista)){
        printf("\nLista vazia.");
    } else{
        printf("\nLista não vazia!");
    }

    printf("\nTamanho da lista: %d", Lista_size(&lista));

    Lista_pushFront(&lista, 2);
    imprimir(&lista);

    Lista_pushBack(&lista, 5);
    imprimir(&lista);
}
