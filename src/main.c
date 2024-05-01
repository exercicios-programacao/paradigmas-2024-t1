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

int main(int argc, char **argv)
{
    Lista intlist;

    Lista_new(&intlist, sizeof(int), NULL);

    for (int i = 0; i < 10; i++)
    {
        Lista_pushBack(&intlist, &i);
    }

    int size = Lista_size(&intlist);
    printf("%i\n", size);

    return 0;
}
