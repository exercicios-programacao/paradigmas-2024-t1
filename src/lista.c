#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _lista_nodo {
    void *valor;
    struct _lista_nodo *next;
} ListaNodo;
typedef struct {
    ListaNodo *head;
    ListaNodo *tail;
    ListaNodo *current;
    int size;
    int data_size;
    void (*free_data)(void *data);
} Lista;
void Lista_new(Lista *lista, int data_size, void (*free_data)(void *)) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    lista->size = 0;
    lista->data_size = data_size;
    lista->free_data = free_data;
}
void Lista_delete(Lista *lista) {
    ListaNodo *current = lista->head;
    ListaNodo *next;
    while (current != NULL) {
        next = current->next;
        if (lista->free_data != NULL) {
            lista->free_data(current->valor);
        }
        free(current->valor);
        free(current);
        current = next;
    }
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    lista->size = 0;
}
int Lista_isEmpty(Lista *lista) {
    return lista->size == 0;
}

#inlcude "lista.h"

int Lista_size(Lista *lista) {
    return lista->size;
}

void Lista_pushFront(Lista *lista, void *valor) {
    ListaNodo *new_node = (ListaNodo *)malloc(sizeof(ListaNodo));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->valor = malloc(lista->data_size);
    if (new_node->valor == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(new_node->valor, valor, lista->data_size);
    new_node->next = lista->head;

    lista->head = new_node;
    if (lista->size == 0) {
        lista->tail = new_node;
    }
    lista->size++;
}
void Lista_pushBack(Lista *lista, void *valor) {
    ListaNodo *new_node = (ListaNodo *)malloc(sizeof(ListaNodo));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->valor = malloc(lista->data_size);
    if (new_node->valor == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    memcpy(new_node->valor, valor, lista->data_size);
    new_node->next = NULL;

    if (lista->size == 0) {
        lista->head = new_node;
    } else {
        lista->tail->next = new_node;
    }
    lista->tail = new_node;
    lista->size++;
}
int Lista_search(Lista *lista, void *chave, void *dest, int (*cmp)(void *, void *)) {
    ListaNodo *current = lista->head;
    while (current != NULL) {
        if (cmp(current->valor, chave) == 0) {
            memcpy(dest, current->valor, lista->data_size);
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
    if (lista->current != NULL) {
        lista->current = lista->current->next;
        return 1;
    } else {
        return 0;
    }
}
void Lista_current(Lista *lista, void *dest) {
    if (lista->current != NULL) {
        memcpy(dest, lista->current->valor, lista->data_size);
    } else {
        fprintf(stderr, "No current node\n");
        exit(EXIT_FAILURE);
    }
}
void Lista_remove(Lista *lista, void *chave, int (*cmp)(void *, void *)) {
    ListaNodo *current = lista->head;
    ListaNodo *prev = NULL;

    while (current != NULL) {
        if (cmp(current->valor, chave) == 0) {
            if (prev == NULL) { 
                lista->head = current->next;
                if (lista->head == NULL) {
                    lista->tail = NULL;
                }
            } else {
                prev->next = current->next;
                if (current->next == NULL) {
                    lista->tail = prev;
                }
            }

            if (lista->free_data != NULL) {
                lista->free_data(current->valor);
            }
            free(current->valor);
            free(current);
            lista->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}
void Lista_insertAfter(Lista *lista, void *dado) {
    if (lista->current != NULL) {
        ListaNodo *new_node = (ListaNodo *)malloc(sizeof(ListaNodo));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        new_node->valor = malloc(lista->data_size);
        if (new_node->valor == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }

        memcpy(new_node->valor, dado, lista->data_size);
        new_node->next = lista->current->next;

        lista->current->next = new_node;

        if (lista->current == lista->tail) {
            lista->tail = new_node;
        }

        lista->size++;
    } else {
        fprintf(stderr, "No current node\n");
        exit(EXIT_FAILURE);
    }
}
int cmp_int(void *a, void *b) {
    int *num_a = (int *)a;
    int *num_b = (int *)b;
    if (*num_a == *num_b) {
        return 0;
    } else if (*num_a < *num_b) {
        return -1;
    } else {
        return 1;
    }
}
int main() {
    return 0;
}
