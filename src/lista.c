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
    int size;
    void (*free_data)(void*);
} Lista;

void Lista_new(Lista* list, int data_type_size, void (*free_data)(void*)) {
    list->data_type_size = data_type_size;
    list->free_data = free_data;
}

void Lista_pushFront(Lista* list, void* data) {
    NodeLista* new_node = (NodeLista*) malloc(sizeof(NodeLista));

    new_node->data = malloc(list->data_type_size);

    memcpy(new_node->data, data, list->data_type_size);

    new_node->next = list->head;

    list->head = new_node;

    list->size++;
}

void Lista_pushBack(Lista* list, void* data) {
    NodeLista* new_node = (NodeLista*) malloc(sizeof(NodeLista));
    
    new_node->data = malloc(list->data_type_size);

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

    list->size++;
}

Lista_isEmpty(Lista* list) {
    return list->size == 0;
}




