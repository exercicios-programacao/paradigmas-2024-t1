#ifndef _PARADIGMAS_T1_LISTA_H_
#define _PARADIGMAS_T1_LISTA_H_

#include <stddef.h>

typedef struct _lista_nodo {
    void* valor;
    struct _lista_nodo* next;
    struct _lista_nodo* prev;  // Adicionando ponteiro para o elemento anterior
} ListaNodo;

typedef struct {
    ListaNodo *head;
    ListaNodo *tail;
    ListaNodo *current;
    int size;
    int data_size;
    void (*free_data)(void*);
} Lista;

void Lista_new(Lista* lista, int data_size, void (*free_data)(void*));
void Lista_delete(Lista* lista);
int Lista_isEmpty(const Lista* lista);
int Lista_size(const Lista* lista);
void Lista_pushFront(Lista* lista, void* valor);
void Lista_pushBack(Lista* lista, void* valor);
int Lista_search(Lista* lista, void* chave, void* dest, int (*cmp)(void*, void*));
void Lista_remove(Lista* lista, void* chave, int (*cmp)(void*, void*));
void Lista_first(Lista* lista);
void Lista_last(Lista* lista);
int Lista_next(Lista* lista);
void Lista_current(Lista* lista, void* dest);
void Lista_insertAfter(Lista* lista, void* dado);
void Lista_removeCurrent(Lista* lista);
int Lista_previous(Lista* lista);
void Lista_insertBefore(Lista* lista, void* dado);

#endif /* _PARADIGMAS_T1_LISTA_H_ */

