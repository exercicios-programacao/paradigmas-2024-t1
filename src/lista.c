/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

#include <stdlib.h>
#include <string.h>

typedef struct NodeLista {
    void* data;
    struct NodeLista* next;
} NodeLista;

typedef struct Lista {
    int data_type_size;
    NodeLista* head;
    NodeLista* tail;
    NodeLista* current;
    int size;
    void (*free_data)(void*);
} Lista;

void Lista_new(Lista* list, int data_type_size, void (*free_data)(void*)) {
    list->data_type_size = data_type_size;
    list->free_data = free_data;
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    list->size = 0;
}

void Lista_pushFront(Lista* list, void* data) {
    NodeLista* new_node = (NodeLista*) malloc(sizeof(NodeLista));

    new_node->data = malloc(list->data_type_size);

    memcpy(new_node->data, data, list->data_type_size);

    new_node->next = list->head;

    list->head = new_node;

    if (list->tail == NULL) {
        list->tail = new_node;
    }

    if (list->current == NULL) {
        list->current = list->head;
    }

    list->size++;
}

void Lista_pushBack(Lista* list, void* data) {
    if (list == NULL || data == NULL) {
        return;
    }

    NodeLista* new_node = (NodeLista*) malloc(sizeof(NodeLista));
    if (new_node == NULL) {
        return;
    }

    new_node->data = malloc(list->data_type_size);
    if (new_node->data == NULL) {
        free(new_node);
        return;
    }

    memcpy(new_node->data, data, list->data_type_size);
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        NodeLista* current_node = list->head;
        
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }

        current_node->next = new_node;
    }

    list->tail = new_node;

    if (list->current == NULL) {
        list->current = new_node;
    }

    list->size++;
}

int Lista_isEmpty(Lista* list) {
    if (list->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

int Lista_size(Lista* list) {
    return list->size;
}

void Lista_first(Lista* list) {
    list->current = list->head;
}

void Lista_last(Lista* list) {
    list->current = list->tail;
}

void Lista_next(Lista* list) {
    if (list->current != NULL && list->current->next != NULL){
        list->current = list->current->next;
    } else {
        list->current = list->head;
    }
}

void Lista_current(Lista* list, void* dest) {
    if (list->current != NULL) {
        memcpy(dest, list->current->data, list->data_type_size);
    }
}

/**
 * Insere um novo elemento na lista após o 'elemento atual'.
 */
void Lista_insertAfter(Lista* lista, void* dado) {
    if (lista->current == NULL) {
        return;
    }


    NodeLista* new_node = (NodeLista*) malloc(sizeof(NodeLista));
    if (new_node == NULL) {
        return;
    }

    new_node->data = malloc(lista->data_type_size);

    memcpy(new_node->data, dado, lista->data_type_size);
    new_node->next = lista->current->next;

    lista->current->next = new_node;

    if (lista->tail == lista->current) {
        lista->tail = new_node;
    }

    lista->size++;
}

