/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

#include "lista.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)) {
    if (lista) {
        lista->head = NULL;
        lista->tail = NULL;
        lista->size = 0;
        lista->data_size = data_size;
        lista->free_data = free_data;
    }
}

void Lista_delete(Lista* lista) {
    ListaNodo* current = lista->head;
    while (current != NULL) {
        ListaNodo* next = current->next;
        if (lista->free_data != NULL) {
            lista->free_data(current->valor);
        }
        free(current->valor);
        free(current);
        current = next;
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}

int Lista_isEmpty(Lista* lista) {
    return lista->head == NULL;
}

int Lista_size(Lista* lista) {
    return lista->size;
}

void Lista_pushFront(Lista* lista, void* valor) {
    if (lista == NULL || valor == NULL) {
        return;
    }

    ListaNodo* novo = (ListaNodo*)malloc(sizeof(ListaNodo));
    if (novo == NULL) {
        return;
    }

    novo->valor = malloc(lista->data_size);
    if (novo->valor == NULL) {
        free(novo);
        return;
    }

    memcpy(novo->valor, valor, lista->data_size);
    novo->next = lista->head;
    lista->head = novo;
    if (lista->tail == NULL) {
        lista->tail = novo;
    }
    lista->size++;
}

void Lista_pushBack(Lista* lista, void* valor) {
    if (lista == NULL || valor == NULL) {
        return;
    }

    ListaNodo* novo = (ListaNodo*)malloc(sizeof(ListaNodo));
    if (novo == NULL) {
        return;
    }

    novo->valor = malloc(lista->data_size);
    if (novo->valor == NULL) {
        free(novo);
        return;
    }

    memcpy(novo->valor, valor, lista->data_size);
    novo->next = NULL;
    if (lista->tail == NULL) {
        lista->head = novo;
        lista->tail = novo;
    } else {
        lista->tail->next = novo;
        lista->tail = novo;
    }
    lista->size++;
}

int Lista_search(Lista* lista, void* chave, void* dest, int (*cmp)(void*, void*)) {
    if (lista == NULL || chave == NULL || dest == NULL || cmp == NULL) {
        return 0;
    }

    ListaNodo* current = lista->head;
    while (current != NULL) {
        if (cmp(current->valor, chave) == 0) {
            memcpy(dest, current->valor, lista->data_size);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void Lista_remove(Lista* lista, void* chave, int (*cmp)(void*, void*)) {
    if (lista == NULL || chave == NULL || cmp == NULL) {
        return;
    }

    ListaNodo* current = lista->head;
    ListaNodo* previous = NULL;

    while (current != NULL) {
        if (cmp(current->valor, chave) == 0) {
            if (previous != NULL) {
                previous->next = current->next;
            } else {
                lista->head = current->next;
            }
            if (lista->free_data != NULL) {
                lista->free_data(current->valor);
            }
            free(current->valor);
            free(current);
            lista->size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}



