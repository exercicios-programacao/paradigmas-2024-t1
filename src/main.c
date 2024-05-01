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

    // REQUIRE(true == bool(Lista_isEmpty(&intlist)));
    int isEmpty = Lista_isEmpty(&intlist);
    printf("%i\n", isEmpty);

    // REQUIRE(0 == Lista_size(&intlist));
    int size = Lista_size(&intlist);
    printf("%i\n", size);

    Lista_delete(&intlist);
}
