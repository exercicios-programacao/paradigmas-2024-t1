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
#include <stddef.h>
#include "lista.c"

int main(int argc, char** argv) {

    Lista intlist;
    Lista_new(&intlist, sizeof(int), NULL);

    int nums[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        Lista_pushFront(&intlist, &nums[i]);
    }

    NodeLista* currentNode = intlist.head;
    
    while (currentNode != NULL) {
        printf("%d\n", *(int*)currentNode->data);
        currentNode = currentNode->next;
        //to-do: está printando um valor negativo estranho no último node, verificar o que está acontecendo
    }
}
