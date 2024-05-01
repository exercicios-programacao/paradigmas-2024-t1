#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>


void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)) {
    lista->head = NULL;
    lista->current = NULL;
    lista->data_size = data_size;
    lista->free_data = free_data;
    lista->tail = NULL; 
    lista->next = NULL;
}

void Lista_delete(Lista* lista) {
    ListaNodo* head = lista->head;
    while (head != NULL) {
        ListaNodo* prox = head->next;
        if (lista->free_data != NULL)
            lista->free_data(head->valor);
        free(head);
        head = prox;
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}

int Lista_isEmpty(Lista* lista) {
    return lista->size == 0;
}

int Lista_size(Lista* lista) {
    return lista->size;
}


void Lista_pushFront(Lista* lista, void* valor) {
    ListaNodo* novo_no = malloc(sizeof(ListaNodo));
    if (novo_no == NULL) {
    printf("Falha ao alocar memória"); 
    return; 
    }
    novo_no->valor = valor;
    novo_no->next = lista->head;
    lista->head = novo_no;
    lista->size++;
}

void Lista_pushBack(Lista* lista, void* valor) {
    ListaNodo* novo_no = malloc(sizeof(ListaNodo));
    novo_no->valor = valor;
    novo_no->next = NULL;
    if (lista->head == NULL) {
        lista->head = novo_no;
    } else {
        ListaNodo* current = lista->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = novo_no;
    }
    lista->size++;
}

int Lista_search(Lista* lista, void* chave, void* dest, int (*cmp)(void*,void*)) {
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

void Lista_first(Lista* lista) {
   lista->current = lista->head;
}

typedef struct Node* ListaPtr;

struct Node {
    int data;
    struct Node* next;
};

void Lista_last(Lista* lista) {
    if (lista->head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    struct Node* current = lista->head; 
    while (current->next != NULL) {
        current = current->next;
    }


    
}
int Lista_next(Lista* lista) {
    struct Node* current = lista->head;
    int count = 0; 
    while (current != NULL) {
        count++; 
        current = current->next;
    }
    return 0;
}


void Lista_current(Lista* lista, void* dest) {
    if (lista->current != NULL) {
    memcpy(dest, lista->current->valor, lista->data_size);
    }
}


void Lista_remove(Lista* lista, void* chave, int (*cmp)(void*,void*)) {
    if (lista->current == NULL) {
        printf("Não há elemento atual.\n");
        return;
    }

    if (cmp(lista->current->valor, chave) == 0) {
        ListaNodo* no_a_ser_removido = lista->current;
        lista->current = lista->current->next;

        if (lista->free_data != NULL)
            lista->free_data(no_a_ser_removido->valor);

        free(no_a_ser_removido);
        lista->size--;
    } else {
        printf("A chave não corresponde ao elemento atual.\n");
    }
}


void Lista_insertAfter(Lista* lista, void* dado) {
    if (lista->current == NULL) {
        printf("Não há elemento atual.\n");
        return;
    }

    ListaNodo* novo_no = malloc(sizeof(ListaNodo));
    if (novo_no == NULL) {
        printf("Falha ao alocar memória.\n");
        return;
    }

    novo_no->valor = dado;
    novo_no->next = lista->current->next;
    lista->current->next = novo_no;
    lista->size++;
}

