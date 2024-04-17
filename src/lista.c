/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */
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



