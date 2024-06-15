#include "lista.h"


void Lista_imprime(Lista* lista)
{
    ListaNodo *ptLista = lista->head;
    int index = 1;

    //printf("\nImprimindo lista...");
    /*
    if(ptLista == NULL)
    {
        printf("\n...A lista estah vazia!");
    }
    else
    {*/
        while(ptLista != NULL)
        {
            printf("\n%do- %c",index,ptLista->valor);
            index++;
            ptLista = ptLista->next;
        }
        //printf("\n...lista impressa!\n");
    //}
}

void Lista_new(Lista* lista, int data_size, void (*free_data)(void*))
{
    //printf("\nCriando Lista...");
    lista->head = NULL;
    lista->current = NULL;
    lista->tail = NULL;
    lista->size = 0;
    lista->size_of = data_size;
    lista->free_data = free_data;

    //printf("\nO head eh: %s",lista->head);
    //printf("\nO current eh: %s",lista->current);
    //printf("\nO tail eh: %s",lista->tail);
    //printf("\nO size eh: %s",lista->size);
    //printf("\nO size_of eh: %s",lista->size_of);
    //printf("\nO free_data eh: %s",lista->free_data);
    //printf("\n...lista criada!\n");
}

void Lista_delete(Lista* lista)
{
    //printf("\nRemovendo a Lista...");

    ListaNodo *ptAux, *ptLista = lista->head;
    while(ptLista != NULL)
    {
        ptAux = ptLista->next;
        //printf("\n%d estah sendo removido...",ptLista->valor);
        ptLista = lista->free_data;
        ptLista = ptAux;
    }
    lista = lista->free_data;

    //printf("\n...lista removida!\n");
}

int Lista_isEmpty(Lista* lista)
{
    if(lista->head == lista->free_data)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Lista_size(Lista* lista)
{
    return lista->size;
}

void Lista_pushFront(Lista* lista, void* valor)
{
    //printf("\nInserindo o valor %s na frente da lista...",valor);
    ListaNodo *novo;

    novo = (ListaNodo*) malloc(lista->size_of);
    novo->valor = valor;
    novo->next = lista->head;

    if(lista->head == NULL)
    {
        lista->tail = novo;
    }
    lista->head = novo;
    lista->size = lista->size + 1;
    //printf("\n...valor inserido!\n");
}

void Lista_pushBack(Lista* lista, void* valor)
{
    //printf("\nInserindo o valor %s no final da lista...",valor);

    ListaNodo *novo, *ptAux = lista->head;
    novo = (ListaNodo*) malloc(lista->size_of);
    novo->valor = valor;

    if(ptAux == NULL)
    {
        novo->next = lista->head;
        lista->head = novo;
        lista->tail = novo;
    }
    else
    {
        while(ptAux->next != NULL)
        {
            ptAux = ptAux->next;
        }

        ptAux->next = novo;
        novo->next = NULL;
        lista->tail = novo;
    }

    //printf("\n...valor inserido!\n");
}

int Lista_search(
    Lista* lista,
    void* chave,
    void* dest,
    int (*cmp)(void*,void*))
{
    //printf("\nBuscando o valor %d\n",chave);

    ListaNodo *ptLista = lista->head;

    while(ptLista != NULL)
    {
        if(cmp(ptLista->valor,chave) == 1)
        {
            printf("\nValor: %d", ptLista->valor);
            memcpy(dest, &ptLista->valor, lista->size_of);
            return 1;
        }
        ptLista = ptLista->next;
    }

    return 0;
}

void Lista_remove(Lista* lista, void* chave, int (*cmp)(void*,void*))
{
    ListaNodo *ptLista = lista->head, *ptAux;
    int hasRemoved = 0;

    while(ptLista != NULL)
    {
        if(cmp(ptLista->valor,chave) == 1)
        {
            //printf("\nRemovendo elemento %d\n",ptLista->valor);
            ptAux = ptLista->next;
            ptLista->next = ptAux->next;
            ptLista->valor = ptAux->valor;

            if(ptLista->next == NULL){
                lista->tail = ptLista;
            }

            lista->size = lista->size - 1;
            //printf("\nElemento removido!\n");
            hasRemoved = 1;
            break;
        }
        ptLista = ptLista->next;
    }
    /*
    if (hasRemoved = 0)
    {
        //printf("\nElemento %d nao foi encontrado, portanto nao pode ser removido.", chave);
    }*/

}


void Lista_first(Lista* lista)
{
    lista->current = lista->head;
    //printf("\nEstou no elemento: %d\n",lista->current->valor);
}

void Lista_last(Lista* lista)
{
    lista->current = lista->tail;
    //printf("\nEstou no elemento: %d\n",lista->current->valor);
}

int Lista_next(Lista* lista)
{
    if(lista->current->next != NULL){
        lista->current = lista->current->next;
        //printf("\nVoce esta no ultimo elemento\n");
    }
    else{

        //printf("\nEstou no elemnto: %d\n",lista->current->valor);
    }
}

void Lista_current(Lista* lista, void* dest)
{
    dest = lista->current->valor;
}

void Lista_insertAfter(Lista* lista, void* dado)
{
    //printf("/nInserindo %d apos o elemento %d/n", dado, lista->current->valor);
    ListaNodo *novo, *ptAux, *ptLista = lista->current;

    novo = (ListaNodo*) malloc(lista->size_of);
    novo->valor = dado;
    novo->next = ptAux;

    lista->current->next = novo;
    //printf("/Elemento %d inserido com sucesso!/n", dado);
}

void Lista_removeCurrent(Lista* lista)
{

}

int Lista_previous(Lista* lista)
{

}

void Lista_insertBefore(Lista* lista, void* dado)
{

}

