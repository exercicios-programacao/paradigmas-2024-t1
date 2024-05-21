/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lista.h"

void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)){
    lista->primeiro = NULL;
    lista->atual = lista->primeiro;
    lista->ultimo = lista->primeiro;
    lista->tamanho = 0;
    lista->data = malloc(data_size);
}

void Lista_delete(Lista* lista){
    free(lista);
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
    Nodo *aux = (Nodo*) malloc(sizeof(Nodo));
    aux->valor = valor;
    aux->prox = lista->primeiro;
    lista->primeiro = aux;

    lista->tamanho++;
}

void Lista_pushBack(Lista* lista, void* valor){
    if(lista->ultimo == NULL){
        lista->ultimo = lista->primeiro;
    }

    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
    novo->valor = valor;
    novo->prox = NULL;

    lista->ultimo->prox = novo;
    lista->ultimo = novo;

    lista->tamanho++;
}

int Lista_search(Lista* lista, void* chave, void* dest, int (*cmp)(void*, void*)){
    Nodo *aux;
    aux = lista->primeiro;

    while(aux != NULL){
        dest = aux->valor;

        if(cmp(chave, dest) == 0){
            return 1;
        }

        aux = aux->prox;
    }

    return 0;
}

void Lista_first(Lista* lista){
    lista->atual = lista->primeiro;
}

void Lista_last(Lista* lista){
    lista->atual = lista->ultimo;
}

int Lista_next(Lista* lista){
    if(lista->atual->prox != NULL) {
        lista->atual = lista->atual->prox;
        return 1;
    }
    return 0;
}

void Lista_current(Lista* lista, void* dest){
    if(lista->atual == NULL){
        lista->atual = lista->primeiro;
    }

    dest = lista->atual->valor;
}

void Lista_removeCurrent(Lista* lista){
    lista->atual->prox = lista->atual;
    free(lista->atual);
}

void Lista_insertAfter(Lista* lista, void* dado){
    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
    novo->valor = dado;
    novo->prox = lista->atual->prox;

    lista->atual->prox = novo;
}





