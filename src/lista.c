/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void default_free(void *data)
{
  free(data);
}

void Lista_new(Lista *lista, int data_size, void (*free_data)(void *))
{
  Lista *newList = (Lista *)malloc(sizeof(Lista));

  newList->elementoAtual = NULL;
  newList->head = NULL;
  newList->tail = NULL;
  newList->size = 0;
  newList->data_size = data_size;

  if (free_data == NULL)
  {
    newList->free_data = default_free;
  }
  else
  {
    newList->free_data = free_data;
  }

  memcpy(lista, newList, sizeof(Lista));
}

void Lista_delete(Lista *lista)
{
  ListaNodo *nodo = (*lista).head;

  while (nodo != NULL)
  {
    ListaNodo *nextNodo = nodo->next;

    lista->free_data(nodo->valor);
    lista->free_data(nodo);

    nodo = nextNodo;
  };

  lista->head = NULL;
  lista->tail = NULL;
  lista->elementoAtual = NULL;
  lista->size = 0;
}

int Lista_isEmpty(Lista *lista) { return (*lista).size == 0; }

int Lista_size(Lista *lista) { return lista->size; }

void Lista_pushFront(Lista *lista, void *valor)
{
  ListaNodo *nodo = (ListaNodo *)malloc(sizeof(ListaNodo));

  nodo->valor = malloc((*lista).data_size);
  memcpy(nodo->valor, valor, (*lista).data_size);

  if (Lista_size(lista) == 0)
  {
    (*lista).tail = nodo;
  }
  nodo->next = (*lista).head;
  (*lista).head = nodo;
  (*lista).size++;
}

void Lista_pushBack(Lista *lista, void *valor)
{
  ListaNodo *nodo = (ListaNodo *)malloc(sizeof(ListaNodo));
  nodo->next = NULL;
  nodo->valor = malloc((*lista).data_size);
  memcpy(nodo->valor, valor, (*lista).data_size);

  if (Lista_size(lista) == 0)
  {
    (*lista).size++;
    (*lista).head = nodo;
    (*lista).tail = nodo;
    return;
  }

  (*lista).tail->next = nodo;
  (*lista).tail = nodo;
  (*lista).size++;
}

int Lista_search(Lista *lista, void *chave, void *dest,
                 int (*cmp)(void *, void *))
{
  ListaNodo *nodo = (*lista).head;

  while (nodo != NULL)
  {
    int cmpResult = cmp(chave, nodo->valor);

    if (cmpResult == 0)
    {
      dest = nodo->valor;
      return 1;
    }

    nodo = nodo->next;
  };

  return 0;
}

void Lista_remove(Lista *lista, void *chave, int (*cmp)(void *, void *))
{
  ListaNodo *nodoAtual = (*lista).head;
  ListaNodo *nodoAnterior = NULL;

  while (nodoAtual != NULL)
  {
    int cmpResult = cmp(chave, nodoAtual->valor);

    if (cmpResult == 0)
    {
      nodoAnterior->next = nodoAtual->next;
      free(nodoAtual);
      return;
    }

    nodoAnterior = nodoAtual;
    nodoAtual = nodoAtual->next;
  }
}

void Lista_first(Lista *lista)
{
  (*lista).elementoAtual = (*lista).head;
}

void Lista_last(Lista *lista)
{
  (*lista).elementoAtual = (*lista).tail;
}

int Lista_next(Lista *lista)
{
  if ((*lista).elementoAtual->next == NULL)
  {
    return 0;
  }

  (*lista).elementoAtual = (*lista).elementoAtual->next;
  return 1;
}

void Lista_current(Lista *lista, void *dest)
{
  memcpy(dest, (*lista).elementoAtual->valor, (*lista).data_size);
}

void Lista_insertAfter(Lista *lista, void *dado)
{
  ListaNodo *nodo = (ListaNodo *)malloc(sizeof(ListaNodo));

  nodo->valor = malloc((*lista).data_size);
  memcpy(nodo->valor, dado, (*lista).data_size);

  nodo->next = (*lista).elementoAtual->next;
  (*lista).elementoAtual->next = nodo;
}

void Lista_removeCurrent(Lista *lista) { return; }

int Lista_previous(Lista *lista) { return 0; }

void Lista_insertBefore(Lista *lista, void *dado) { return; }
