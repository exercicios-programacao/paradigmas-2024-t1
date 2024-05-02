/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

#include "lista.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void List_new(Lista* lista, int data_size, void (*free_data)(void*)){
	if(lista){
	  lista->head = NULL;
	  lista->tail = NULL;
	  lista->cursor = NULL;
	  lista->size = 0;
	  lista->data_size = data_size;
	  lista->free_data = free_data;
	}
}

void Lista_delete(Lista* lista){
	ListaNodo* current = lista->head;
	while(current != NULL){
		
	}
}
