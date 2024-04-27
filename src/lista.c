/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

#include <stdlib.h>
#include <assert.h>

#include "lista.h"

void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)){
    lista->primeiro = NULL;
    lista->tamanho = 0;
}

void Lista_delete(Lista* lista){

}

int Lista_isEmpty(Lista* lista){
    if(lista->primeiro == NULL){
        return 1;
    }
    return 0;
}

int Lista_size(Lista* lista){
    return lista->tamanho;
}

void Lista_pushFront(Lista* lista, void* valor){
    lista->primeiro->prox = *lista->primeiro;
    lista->primeiro->valor = valor;
}

void Lista_pushBack(Lista* lista, void* valor){

}

int Lista_search(Lista* lista, void* chave, void* dest, int (*cmp)(void*,void*)){

}

void Lista_first(Lista* lista){
    return lista[0];
}

void Lista_last(Lista* lista){
    return lista[lista->size - 1];
}

int Lista_next(Lista* lista){

}

void Lista_current(Lista* lista, void* dest){

}

void Lista_remove(Lista* lista, void* chave, int (*cmp)(void*,void*)){

}

void Lista_insertAfter(Lista* lista, void* dado){

}



