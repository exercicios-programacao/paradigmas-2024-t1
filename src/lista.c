/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

#include "lista.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    int data_size;
    struct _lista_nodo* head;
    struct _lista_nodo* tail;
    struct _lista_nodo* nodoAtual;
    int size_list;
    void (*free_data)(void*);
    //int (*cmp)(void*, void*);
}Lista;

// Define a struct para o no
typedef struct _lista_nodo {
    void* valor;                 // * para o dado armazenado na celula
    struct _lista_nodo* next;         // * para a prox celula
    struct _lista_nodo* prev;         // * para a celula anterior
}Lista_Nodo;

void free_data(void* nodo) {
    if (nodo != NULL)
    {
        free(nodo);
    }
}

int int_cmp(void* lhs, void* rhs)
{
    return *(int*)lhs - *(int*)rhs;
}
double double_cmp(void* lhs, void* rhs)
{
    return *(double_cmp*)lhs - *(double_cmp*)rhs;
}

void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)) {
    Lista* novaLista;
    novaLista = malloc(sizeof(Lista));
    novaLista->head = NULL;
    novaLista->tail = NULL;
    novaLista->nodoAtual = NULL;
    novaLista->data_size = data_size;
    novaLista->size_list = 0;
    lista = novaLista;
    lista->free_data = free_data;
}
int Lista_delete(Lista* lista) {
     if (lista-> == NULL) {
        lista->free_data(lista);
    }
    if (lista->head == NULL) {
        lista->free_data(lista);
        return 1;
    }
    else
    {
        int i;
        Lista_Nodo* nodo;
        nodo = lista->head;
        for (i = 0; i >= lista->size_list; i++) {
            Lista_Nodo* nodo1;
            nodo1 = nodo->next;
            free_data(nodo->next);
            if (nodo->prev != NULL) {
                free_data(nodo->prev);
            }
        }
        return 0;
    }
}
int Lista_isEmpty(Lista* lista) {
    if (lista->head != NULL) {
        return 1;
    }
    else return 0;
}
int Lista_size(Lista* lista) {
    return lista->size_list;
}
void Lista_pushFront(Lista* lista, void* valor) {
    Lista_Nodo* nodo;
    nodo = malloc(sizeof(Lista_Nodo));
    nodo->valor = malloc(sizeof(lista->data_size));
    nodo->valor = valor;
    nodo->next = NULL;
    nodo->prev = NULL;
    if (lista->head == NULL) {
        lista->head = nodo;
    }
    else {
        nodo->next = lista->head;
        lista->head = nodo;
        if (lista->tail == NULL) {
            lista->tail == lista->head;
        }
    }
    lista->size_list += 1;
    lista->free_data(nodo);
}

void Lista_pushBack(Lista* lista, void* valor) {
    Lista_Nodo* nodo = malloc(sizeof(Lista_Nodo)); // Aloca mem p um nv nó da lista

    if (nodo == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }

    nodo->valor = malloc(lista->data_size); //aloca mem para valor a ser armazem no nó
    if (nodo->valor == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para o valor do novo nó.\n");
        free(nodo);
        exit(EXIT_FAILURE);
    }

    memcpy(nodo->valor, valor, lista->data_size); //Copia o cont do valor fornecido p o nó da lista
    nodo->next = NULL;
    nodo->prev = lista->tail;

    if (lista->head == NULL) {
        lista->head = nodo;
    }
    else {
        lista->tail->next = nodo;
    }

    lista->tail = nodo;
    lista->size_list++;
}


/*void Lista_pushBack(Lista* lista, void* valor){
    Lista_Nodo* nodo;
    nodo = malloc(sizeof(Lista_Nodo));
    nodo->valor = malloc(sizeof(lista->data_size));
    nodo->valor = valor;
    nodo->next = NULL;
    nodo->prev = NULL;
    if(lista->head==NULL){
        lista->head = nodo;
    }else if(lista->tail == NULL){
         nodo->prev = lista->head;
        lista->tail = nodo;
    }else{
        nodo->prev = lista->tail;
        lista->tail = nodo;
    }
    lista->size_list+= 1;
    lista->free_data(nodo);
}*/

int Lista_search(Lista* lista, void* chave, void* dest, int (*cmp)(void*, void*)) {
    Lista_Nodo* nodo = lista->head; // Inicializa ponteiro p percorrer a lista
    while (nodo != NULL) { // Percorre a lista
        if (cmp(nodo->valor, chave) == 0) {  // Compara o valor do nó com a chave

            if (dest != NULL) // Se a chave for encontrada, copia o valor do nó para o destino
                *((void**)dest) = nodo->valor;
            return 1; // Elemento encontrado
        }
        nodo = nodo->;
    }
    return 0; // Elemento não encontrado
}

void Lista_first(Lista* lista) {
    if (lista->head != NULL){
        memcpy(lista->nodoAtual->valor, lista->head->valor,  lista->data_size);
        memcpy(lista->nodoAtual->next, lista->head->next, sizeof(lista->head->next));
        memcpy(lista->nodoAtual->prev, lista->head->prev, sizeof(lista->head->prev));
    }
    else
    {
        lista->nodoAtual=NULL;
    }
}

void Lista_last(Lista* lista) { // Implementação da func last para ajustar o 'elemento atual' da lista para o último elemento
    if (lista->last != NULL){
        memcpy(lista->nodoAtual->valor, lista->last->valor, lista->data_size);
        memcpy(lista->nodoAtual->next, lista->last->next, sizeof(lista->last->next));
        memcpy(lista->nodoAtual->prev, lista->last->prev, sizeof(lista->last->prev));
    }
    else
    {
        lista->nodoAtual=NULL;
    }
}

void Lista_current(Lista* lista, void* dest) { // Implementação da func current para ter o valor do 'elemento atual'
    if (lista->nodoAtual != NULL){
        Lista_nodo * nodo_destino;
        nodo_destino = malloc(sizeof(Lista_Nodo));
        dest = nodo_destino
        
        memcpy(dest->valor, lista->nodoAtual->valor, lista->data_size);
        memcpy(dest->next, lista->nodoAtual->next, sizeof(lista->nodoAtual->next));
        memcpy(dest->prev, lista->nodoAtual->prev, sizeof(lista->nodoAtual->prev));
    }
    else
    {
        dest=NULL;
    }
}

int Lista_next(Lista* lista) { // Implementação da função next p avançar para o próximo 'elemento atual'
    if (lista->nodoAtual != NULL){
        memcpy(lista->nodoAtual->valor, lista->nodoAtual->valor, lista->data_size);
        memcpy(lista->nodoAtual->next, lista->nodoAtual->next, sizeof(lista->nodoAtual->next));
        memcpy(lista->nodoAtual->prev, lista->nodoAtual->prev, sizeof(lista->nodoAtual->prev));
    }
    else
    {
        lista->nodoAtual=NULL;
    }
    
    if (lista->tail != NULL && lista->tail->next != NULL) {
        lista->tail = lista->tail->next; // Ajusta o 'elemento atual' para o próximo elemento
        return 1; // Existe um próximo elemento
    }
    return 0; // Não existe próximo elemento
}

void Lista_remove(Lista* lista, void* chave, int (*cmp)(void*, void*)) {
    Lista_Nodo* nodo = lista->head; // Inicia ponteiros p percorrer a lista e armazenar o nó anterior ao nó removido
    Lista_Nodo* prev = NULL;

    while (nodo != NULL) {
        if (cmp(nodo->valor, chave) == 0) {  // Verifica se o valor do nó corresponde a chave usando a função de comparação fornecida
            if (prev == NULL) {
                // Se o elemento a ser removido for o primeiro
                lista->head = nodo->next;
                if (lista->head == NULL)
                    lista->tail = NULL;
            }
            else {
                prev->next = nodo->next;
                if (prev->next == NULL)
                    lista->tail = prev;
            }
            free_data(nodo->valor);  // Libera a mem alocada p o valor do nó e pro próprio nó
            free(nodo);
            lista->size_list--; // Reduz o tamanho da lista
            return;
        }
        prev = nodo;
        nodo = nodo->next;
    }
}

void Lista_removeCurrent(Lista* lista) { // Implementação da função removeCurrent p remover o 'elemento atual' da lista
    if (lista->tail != NULL) {
        Lista_Nodo* nodo = lista->tail; // Armazena o 'elemento atual' em um ponteiro p ser removido
        if (nodo->prev != NULL) {    // Se o 'elemento atual' tiver um nó anterior, o próximo nó após o 'elemento atual' agora aponta p o nó anterior
            nodo->prev->next = nodo->next;
        }
        else {
            lista->head = nodo->next;
        }
        if (nodo->next != NULL) { // Se o 'elemento atual' tiver um próximo nó, o nó anterior ao próximo nó agora aponta p o nó anterior do 'elemento atual'
            nodo->next->prev = nodo->prev;
        }
        else {
            lista->tail = nodo->prev;
        }
        lista->free_data(nodo->valor); // Libera a memória alocada p o valor do nó e p o próprio nó
        free(nodo);
        lista->size_list--;
    }
}

void Lista_insertAfter(Lista* lista, void* dado) {
    if (lista->tail != NULL) {
        Lista_Nodo* novo_nodo = malloc(sizeof(Lista_Nodo));
        if (novo_nodo != NULL) {
            novo_nodo->valor = malloc(lista->data_size);
            if (novo_nodo->valor != NULL) {
                memcpy(novo_nodo->valor, dado, lista->data_size);
                novo_nodo->next = lista->tail->next;
                if (novo_nodo->next != NULL) {
                    novo_nodo->next->prev = novo_nodo;
                }
                else {
                    lista->tail = novo_nodo;
                }
                novo_nodo->prev = lista->tail;
                lista->tail->next = novo_nodo;
                lista->size_list++;
                return;
            }
            free(novo_nodo);
        }
    }
}
/*int main() {
   Lista* intlist;

    intlist = NULL;
    Lista_new(intlist, sizeof(int), free_data);
    for (int i = 0; i < 10; i++) {
        Lista_pushBack(intlist, &i);
    }
    Lista_Nodo* nodo;
    nodo = intlist->head;
    while (nodo != NULL) {
        printf("%d", &nodo->valor);
        nodo = nodo->next;
    }
}*/
