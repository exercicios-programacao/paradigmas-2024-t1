/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Lista_new(Lista *lista, int data_size, void (*free_data)(void *)) {
  (*lista).data_size = data_size;
  (*lista).free_data = free_data;
}

void Lista_delete(Lista *lista) { (*lista).free_data(lista); }

int Lista_isEmpty(Lista *lista) { return (*lista).head == NULL; }

int Lista_size(Lista *lista) { return (*lista).size; }

void Lista_pushFront(Lista *lista, void *valor) {
  ListaNodo *nodo;

  (*nodo).valor = malloc((*lista).data_size);
  memcpy((*nodo).valor, valor, (*lista).data_size);

  (*nodo).next = (*lista).head;
  (*lista).head = nodo;
}

void Lista_pushBack(Lista *lista, void *valor) {
  ListaNodo *nodo;

  (*nodo).valor = malloc((*lista).data_size);
  memcpy((*nodo).valor, valor, (*lista).data_size);

  (*nodo).next = NULL;
  (*lista).tail->next = nodo;
  (*lista).tail = nodo;
}

int Lista_search(Lista *lista, void *chave, void *dest,
                 int (*cmp)(void *, void *)) {
  ListaNodo *nodo = (*lista).head;

  while (nodo != NULL) {
    int cmpResult = cmp(chave, nodo->valor);

    if (cmpResult == 0) {
      dest = nodo->valor;
      return 1;
    }

    nodo = nodo->next;
  };

  return 0;
}

void Lista_remove(Lista *lista, void *chave, int (*cmp)(void *, void *)) {
  ListaNodo *nodoAtual = (*lista).head;
  ListaNodo *nodoAnterior = NULL;

  while (nodoAtual != NULL) {
    int cmpResult = cmp(chave, nodoAtual->valor);

    if (cmpResult == 0) {
			nodoAnterior->next = nodoAtual->next;
			free(nodoAtual);
			return;
    }

    nodoAnterior = nodoAtual;
    nodoAtual = nodoAtual->next;
  }
}

void Lista_first(Lista* lista){
	(*lista).elementoAtual = (*lista).head;
}

void Lista_last(Lista* lista) {
	(*lista).elementoAtual = (*lista).tail;
}

int Lista_next(Lista* lista) {
	(*lista).elementoAtual = (*lista).elementoAtual->next;

	if((*lista).elementoAtual == NULL) {
		return 0;
	}

	return 1;
}

void Lista_current(Lista* lista, void* dest) {
	dest = (*lista).elementoAtual;
}

void Lista_insertAfter(Lista* lista, void* dado) {
	ListaNodo* nodo;

	(*nodo).valor = malloc((*lista).data_size);
	memcpy((*nodo).valor, dado, (*lista).data_size);

	(*nodo).next = (*lista).elementoAtual->next;
	(*lista).elementoAtual->next = nodo;
}

void Lista_removeCurrent(Lista* lista) { return; }

int Lista_previous(Lista* lista) { return 0; }

void Lista_insertBefore(Lista* lista, void* dado) { return; }
