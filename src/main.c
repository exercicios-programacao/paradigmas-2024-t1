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
        Lista_pushBack(&intlist, &nums[i]);
    }
    
    Lista_next(&intlist);
    Lista_next(&intlist);
    
    Lista_removeCurrent(&intlist);

    while (intlist.current != NULL) {
        printf("%d\n", *(int*)intlist.current->data);
        
        Lista_next(&intlist);
    }
}
