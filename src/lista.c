#include "lista.h"
#include <stdlib.h>
#include <string.h>

void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    lista->size = 0;
    lista->data_size = data_size;
    lista->free_data = free_data;
}

void Lista_delete(Lista* lista) {
    ListaNodo *current = lista->head;
    while (current != NULL) {
        ListaNodo *next = current->next;
        if (lista->free_data) {
            lista->free_data(current->valor);
        }
        free(current->valor);
        free(current);
        current = next;
    }
    lista->head = lista->tail = lista->current = NULL;
    lista->size = 0;
}

int Lista_isEmpty(const Lista* lista) {
    return lista->size == 0;
}

int Lista_size(const Lista* lista) {
    return lista->size;
}

void Lista_pushFront(Lista* lista, void* valor) {
    ListaNodo* node = (ListaNodo*)malloc(sizeof(ListaNodo));
    node->valor = malloc(lista->data_size);
    memcpy(node->valor, valor, lista->data_size);
    node->next = lista->head;
    node->prev = NULL;

    if (lista->head != NULL) {
        lista->head->prev = node;
    }
    lista->head = node;
    if (lista->tail == NULL) {
        lista->tail = node;
    }
    lista->size++;
}

void Lista_pushBack(Lista* lista, void* valor) {
    ListaNodo* node = (ListaNodo*)malloc(sizeof(ListaNodo));
    node->valor = malloc(lista->data_size);
    memcpy(node->valor, valor, lista->data_size);
    node->next = NULL;
    node->prev = lista->tail;

    if (lista->tail != NULL) {
        lista->tail->next = node;
    }
    lista->tail = node;
    if (lista->head == NULL) {
        lista->head = node;
    }
    lista->size++;
}

int Lista_search(Lista* lista, void* chave, void* dest, int (*cmp)(void*, void*)) {
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
    ListaNodo *current = lista->head;
    while (current != NULL) {
        if (cmp(current->valor, chave) == 0) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                lista->head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                lista->tail = current->prev;
            }
            if (lista->free_data) {
                lista->free_data(current->valor);
            }
            free(current->valor);
            free(current);
            lista->size--;
            return;
        }
        current = current->next;
    }
}

void Lista_first(Lista* lista) {
    lista->current = lista->head;
}

void Lista_last(Lista* lista) {
    lista->current = lista->tail;
}

int Lista_next(Lista* lista) {
    if (lista->current != NULL && lista->current->next != NULL) {
        lista->current = lista->current->next;
        return 1;
    }
    return 0;
}

void Lista_current(Lista* lista, void* dest) {
    if (lista->current != NULL) {
        memcpy(dest, lista->current->valor, lista->data_size);
    }
}

void Lista_insertAfter(Lista* lista, void* dado) {
    if (lista->current == NULL) return;
    ListaNodo* node = (ListaNodo*)malloc(sizeof(ListaNodo));
    node->valor = malloc(lista->data_size);
    memcpy(node->valor, dado, lista->data_size);
    node->next = lista->current->next;
    node->prev = lista->current;

    if (lista->current->next != NULL) {
        lista->current->next->prev = node;
    }
    lista->current->next = node;

    if (node->next == NULL) {
        lista->tail = node;
    }
    lista->size++;
}

void Lista_removeCurrent(Lista* lista) {
    if (lista->current == NULL) return;
    ListaNodo* toRemove = lista->current;
    if (toRemove->prev) {
        toRemove->prev->next = toRemove->next;
    } else {
        lista->head = toRemove->next;
    }
    if (toRemove->next) {
        toRemove->next->prev = toRemove->prev;
    } else {
        lista->tail = toRemove->prev;
    }
    lista->current = toRemove->next;

    if (lista->free_data) {
        lista->free_data(toRemove->valor);
    }
    free(toRemove->valor);
    free(toRemove);
    lista->size--;
}

int Lista_previous(Lista* lista) {
    if (lista->current != NULL && lista->current->prev != NULL) {
        lista->current = lista->current->prev;
        return 1;
    }
    return 0;
}

void Lista_insertBefore(Lista* lista, void* dado) {
    if (lista->current == NULL) return;
    ListaNodo* node = (ListaNodo*)malloc(sizeof(ListaNodo));
    node->valor = malloc(lista->data_size);
    memcpy(node->valor, dado, lista->data_size);
    node->prev = lista->current->prev;
    node->next = lista->current;

    if (lista->current->prev != NULL) {
        lista->current->prev->next = node;
    }
    lista->current->prev = node;

    if (node->prev == NULL) {
        lista->head = node;
    }
    lista->size++;
}

