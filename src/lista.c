/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)) {
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

void Lista_delete(Lista* lista) {
    ListaNodo* atual = lista->primeiro;
    while (atual != NULL) {
        ListaNodo* proximo = atual->next;
        free(atual->valor);
        free(atual);
        atual = proximo;
    }
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
}

int Lista_isEmpty(Lista* lista) {
    return (lista->primeiro == NULL);
}

int Lista_size(Lista* lista) {
    return lista->tamanho;
}

void Lista_pushFront(Lista* lista, void* valor) {
    ListaNodo* novo_nodo = (ListaNodo*)malloc(sizeof(ListaNodo));
    novo_nodo->valor = valor;
    novo_nodo->next = lista->primeiro;
    lista->primeiro = novo_nodo;
    if (lista->ultimo == NULL) {
        lista->ultimo = novo_nodo;
    }
    lista->tamanho++;
}

void Lista_pushBack(Lista* lista, void* valor) {
    ListaNodo* novo_nodo = (ListaNodo*)malloc(sizeof(ListaNodo));
    novo_nodo->valor = valor;
    novo_nodo->next = NULL;
    if (lista->ultimo != NULL) {
        lista->ultimo->next = novo_nodo;
    }
    lista->ultimo = novo_nodo;
    if (lista->primeiro == NULL) {
        lista->primeiro = novo_nodo;
    }
    lista->tamanho++;
}

int Lista_search(Lista* lista, void* chave, void* dest, int (*cmp)(void*, void*)) {
    ListaNodo* atual = lista->primeiro;
    while (atual != NULL) {
        if (cmp(atual->valor, chave) == 0) {
            if (dest != NULL) {
                *(int*)dest = *(int*)atual->valor;
            }
            return 1;
        }
        atual = atual->next;
    }
    return 0;
}

void Lista_remove(Lista* lista, void* chave, int (*cmp)(void*, void*)) {
    ListaNodo* atual = lista->primeiro;
    ListaNodo* anterior = NULL;
    while (atual != NULL) {
        if (cmp(atual->valor, chave) == 0) {
            if (anterior == NULL) {
                lista->primeiro = atual->next;
            } else {
                anterior->next = atual->next;
            }
            if (lista->ultimo == atual) {
                lista->ultimo = anterior;
            }
            free(atual->valor);
            free(atual);
            lista->tamanho--;
            return;
        }
        anterior = atual;
        atual = atual->next;
    }
}

void Lista_first(Lista* lista) {
    lista->atual = lista->primeiro;
}

void Lista_last(Lista* lista) {
    lista->atual = lista->ultimo;
}

int Lista_next(Lista* lista) {
    if (lista->atual != NULL) {
        lista->atual = lista->atual->next;
        return (lista->atual != NULL);
    }
    return 0;
}

void Lista_current(Lista* lista, void* dest) {
    if (lista->atual != NULL) {
        *(int*)dest = *(int*)lista->atual->valor;
    }
}

void Lista_insertAfter(Lista* lista, void* dado) {
    if (lista->atual != NULL) {
        ListaNodo* novo_nodo = (ListaNodo*)malloc(sizeof(ListaNodo));
        novo_nodo->valor = dado;
        novo_nodo->next = lista->atual->next;
        lista->atual->next = novo_nodo;
        if (lista->atual == lista->ultimo) {
            lista->ultimo = novo_nodo;
        }
        lista->tamanho++;
    }
}

void Lista_removeCurrent(Lista* lista) {
    if (lista == NULL || lista->atual == NULL) {
        return;
    }

    ListaNodo* atual = lista->atual;
    if (atual->previous) {
        atual->previous->next = atual->next;
    } else {
        lista->primeiro = atual->next;
    }

    if (atual->next) {
        atual->next->previous = atual->previous;
    } else {
        lista->ultimo = atual->previous;
    }

    lista->atual = atual->next ? atual->next : atual->previous;

    free(atual->valor);
    free(atual);

    lista->tamanho--;
}

int Lista_previous(Lista* lista) {
    if (lista->atual != NULL) {
        ListaNodo* anterior = NULL;
        ListaNodo* atual = lista->primeiro;
        while (atual != NULL) {
            if (atual->next == lista->atual) {
                lista->atual = anterior;
                return (lista->atual != NULL);
            }
            anterior = atual;
            atual = atual->next;
        }
    }
    return 0;
}

void Lista_insertBefore(Lista* lista, void* dado) {
    if (lista->atual != NULL) {
        if (lista->primeiro == lista->atual) {
            Lista_pushFront(lista, dado);
        } else {
            ListaNodo* novo_nodo = (ListaNodo*)malloc(sizeof(ListaNodo));
            novo_nodo->valor = dado;
            ListaNodo* anterior = NULL;
            ListaNodo* atual = lista->primeiro;
            while (atual != NULL && atual != lista->atual) {
                anterior = atual;
                atual = atual->next;
            }
            if (anterior != NULL) {
                anterior->next = novo_nodo;
            }
            novo_nodo->next = lista->atual;
            lista->tamanho++;
        }
    }
}



   



   
int int_cmp(void* a, void* b) {
    int *x = (int*)a;
    int *y = (int*)b;
    return (*x - *y);
}

void free_int(void* data) {
    free(data);
}

int main() {
    Lista lista;
    Lista_new(&lista, sizeof(int), free_int);

    int elementos[] = {10, 20, 30, 40, 50};
    for (size_t i = 0; i < sizeof(elementos) / sizeof(elementos[0]); i++) {
        Lista_pushBack(&lista, &elementos[i]);
    }

    if (Lista_isEmpty(&lista)) {
        printf("A lista esta vazia\n");
    } else {
        printf("A lista nao esta vazia\n");
    }

    printf("\n");

    printf("Tamanho da lista: %d\n", Lista_size(&lista));

    printf("\n");

    int chave = 30;
    int encontrado;
    int valor_encontrado;
    encontrado = Lista_search(&lista, &chave, &valor_encontrado, int_cmp);
    if (encontrado) {
        printf("Elemento %d encontrado na lista\n", valor_encontrado);
    } else {
        printf("Elemento %d nao encontrado na lista\n", chave);
    }

    printf("\n");

    printf("Removendo o elemento 20 da lista...\n");
    int chave_remover = 20;
    Lista_remove(&lista, &chave_remover, int_cmp);

    printf("\n");

    Lista_first(&lista);
    int elemento_atual;
    printf("Imprimindo todos os elementos da lista:\n");
    while (1) {
        Lista_current(&lista, &elemento_atual);
        printf("%d ", elemento_atual);
        if (!Lista_next(&lista)) {
            break;
        }
    }

    printf("\n");
    printf("\n");

    Lista_last(&lista);
    printf("Ultimo elemento da lista: ");
    Lista_current(&lista, &elemento_atual);
    printf("%d\n", elemento_atual);

    printf("\n");

    printf("Movendo para o primeiro elemento novamente...\n");
    Lista_first(&lista);
    Lista_current(&lista, &elemento_atual);

    int novo_elemento = 15;
    Lista_insertAfter(&lista, &novo_elemento);

    printf("\n");

    Lista_first(&lista);
    printf("Lista apos insercao:\n");
    while (1) {
        Lista_current(&lista, &elemento_atual);
        printf("%d ", elemento_atual);
        if (!Lista_next(&lista)) {
            break;
        }
    }

    printf("\n");
    printf("\n");

    printf("Removendo elemento atual...\n");
    printf("%d ", elemento_atual);
    Lista_removeCurrent(&lista);

    printf("\n");

    Lista_first(&lista);
    printf("Lista apos remocao:\n");
    while (1) {
        Lista_current(&lista, &elemento_atual);
        printf("%d ", elemento_atual);
        if (!Lista_next(&lista)) {
            break;
        }
    }

    printf("\n");
    printf("\n");

    Lista_last(&lista);

    int novo_elemento_antes = 45;
    Lista_insertBefore(&lista, &novo_elemento_antes);

    Lista_first(&lista);
    printf("Lista apos insercao antes do ultimo elemento:\n");
    while (1) {
        Lista_current(&lista, &elemento_atual);
        printf("%d ", elemento_atual);
        if (!Lista_next(&lista)) {
            break;
        }
    }

    printf("\n");
    printf("\n");

    printf("Movendo para o elemento anterior ao ultimo...\n");
    Lista_previous(&lista);

    printf("\n");

    printf("Removendo elemento atual...\n");
    printf("%d ", elemento_atual);
    Lista_removeCurrent(&lista);

    printf("\n");

    Lista_first(&lista);
    printf("Lista apos remocao do elemento anterior ao ultimo:\n");
    while (1) {
        Lista_current(&lista, &elemento_atual);
        printf("%d ", elemento_atual);
        if (!Lista_next(&lista)) {
            break;
        }
    }

    printf("\n");

    Lista_delete(&lista);

    return 0;
}
