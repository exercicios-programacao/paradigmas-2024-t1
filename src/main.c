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


void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)) {
    lista->head = NULL;
    lista->current = NULL;
    lista->data_size = data_size;
    lista->free_data = free_data;
    lista->tail = NULL; 
    lista->next = NULL;
}
