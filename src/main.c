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
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct Lista {
    Node *head;
    Node *tail;
    Node *current;
    int size;
    int data_size;
    void (*free_data)(void*);
} Lista;

void Lista_new(Lista *lista, int data_size, void (*free_data)(void*)) {
    lista->head = lista->tail = lista->current = NULL;
    lista->size = 0;
    lista->data_size = data_size;
    lista->free_data = free_data;
}

void Lista_delete(Lista *lista) {
    Node *current = lista->head;
    while (current != NULL) {
        Node *next = current->next;
        if (lista->free_data) {
            lista->free_data(current->data);
        }
        free(current->data);
        free(current);
        current = next;
    }
    lista->size = 0;
    lista->head = lista->tail = lista->current = NULL;
}

int Lista_size(Lista *lista) {
    return lista->size;
}

void Lista_pushFront(Lista *lista, void *valor) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = malloc(lista->data_size);
    memcpy(node->data, valor, lista->data_size);
    node->next = lista->head;
    lista->head = node;
    if (lista->tail == NULL) {
        lista->tail = node;
    }
    lista->size++;
}

void Lista_pushBack(Lista *lista, void *valor) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = malloc(lista->data_size);
    memcpy(node->data, valor, lista->data_size);
    node->next = NULL;
    if (lista->tail != NULL) {
        lista->tail->next = node;
    }
    lista->tail = node;
    if (lista->head == NULL) {
        lista->head = node;
    }
    lista->size++;
}

int Lista_search(Lista *lista, void *chave, void *dest, int (*cmp)(void*, void*)) {
    Node *current = lista->head;
    while (current != NULL) {
        if (cmp(current->data, chave) == 0) {
            memcpy(dest, current->data, lista->data_size);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void Lista_first(Lista *lista) {
    lista->current = lista->head;
}

void Lista_last(Lista *lista) {
    lista->current = lista->tail;
}

int Lista_next(Lista *lista) {
    if (lista->current != NULL && lista->current->next != NULL) {
        lista->current = lista->current->next;
        return 1;
    }
    return 0;
}

void Lista_current(Lista *lista, void *dest) {
    if (lista->current != NULL) {
        memcpy(dest, lista->current->data, lista->data_size);
    }
}

void Lista_remove(Lista *lista, void *chave, int (*cmp)(void*, void*)) {
    Node *current = lista->head;
    Node *prev = NULL;
    while (current != NULL) {
        if (cmp(current->data, chave) == 0) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                lista->head = current->next;
            }
            if (current->next == NULL) {
                lista->tail = prev;
            }
            if (lista->free_data) {
                lista->free_data(current->data);
            }
            free(current->data);
            free(current);
            lista->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void Lista_insertAfter(Lista *lista, void *dado) {
    if (lista->current == NULL) {
        return;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = malloc(lista->data_size);
    memcpy(new_node->data, dado, lista->data_size);
    new_node->next = lista->current->next;
    lista->current->next = new_node;
    if (new_node->next == NULL) {
        lista->tail = new_node;
    }
    lista->size++;
}

int main() {
    Lista lista;
    Lista_new(&lista, sizeof(int), free);

    int valores[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        Lista_pushBack(&lista, &valores[i]);
    }

    int valor;
    Lista_first(&lista);
    do {
        Lista_current(&lista, &valor);
        printf("%d\n", valor);
    } while (Lista_next(&lista));

    Lista_delete(&lista);

    return 0;

