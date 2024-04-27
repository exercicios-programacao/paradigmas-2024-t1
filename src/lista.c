/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

#include "lista.h"
#include <stddef.h>
#include <stdlib.h>
#include <cstring>

void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)){
    if (lista) {
        lista->head = NULL;
        lista->tail = NULL;
        lista->size = 0;
        lista->data_size = data_size;
        lista->free_data = free_data;
    }
   
}

void Lista_delete(Lista* lista){
  if (lista) {
        lista->head = NULL;
        lista->tail = NULL; 
        lista->size = 0;
    }
}

int Lista_isEmpty(Lista* lista) {
    return lista->head == NULL;
}

int Lista_size(Lista* lista) {
    return lista->size;
}

void Lista_pushFront(Lista* lista, void* valor) {
    ListaNodo* novo_nodo = (ListaNodo*)malloc(sizeof(ListaNodo));
    if (novo_nodo == NULL) {
        return;
    }
    novo_nodo->valor = valor;
    novo_nodo->next = lista->head;

    if (Lista_isEmpty(lista)) {
        lista->tail = novo_nodo;
    }

    lista->head = novo_nodo;
    lista->size++;
}

void Lista_pushBack(Lista* lista, void* valor) {
    ListaNodo* novo_nodo = (ListaNodo*)malloc(sizeof(ListaNodo));
    if (novo_nodo == NULL) {
        return;
    }
    novo_nodo->valor = valor;
    novo_nodo->next = NULL;

    if (Lista_isEmpty(lista)) {
        lista->head = novo_nodo;
    } else {
        lista->tail->next = novo_nodo;
    }

    lista->tail = novo_nodo;
    lista->size++;
}

int Lista_search(
        Lista* lista, 
        void* chave, 
        void* dest, 
        int (*cmp)(void*,void*)) {
    ListaNodo* current = lista->head;

    while (current != NULL) {
        if (cmp(current->valor, chave) == 0) {
            if (dest != NULL) {
                memcpy(dest, current->valor, lista->data_size);
            }
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void Lista_remove(Lista* lista, void* chave, int (*cmp)(void*,void*)) {
    ListaNodo* current = lista->head;
    ListaNodo* previous = NULL;

    while (current != NULL) {
        if (cmp(current->valor, chave) == 0) {
            if (previous == NULL) {
                lista->head = current->next;
                if (lista->head == NULL) {
                    lista->tail = NULL;
                }
            } else {
                previous->next = current->next;
                if (current->next == NULL) {
                    lista->tail = previous;
                }
            }

            if (lista->free_data) {
                lista->free_data(current->valor);
            }
            free(current);
            lista->size--;
            return; 
        }
        previous = current;
        current = current->next;
    }
}

