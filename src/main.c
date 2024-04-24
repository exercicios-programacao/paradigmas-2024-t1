/**
 * Este arquivo pode ser utilizado para criar um teste rápido
 * que permita depurar a função que está atualmente sendo
 * implementada de forma mais simples.
 *
 * Para compilar apenas esse programa, utilize `make main`.
 *
 * Você pode alterar como desejar esse programa, ele não será
 * avaliado pelos testes.
 */

#include <stdio.h>
#include <stddef.h>
#include "lista.c"

int main(int argc, char** argv) {

    Lista intlist;
    Lista_new(&intlist, sizeof(int), NULL);

    int nums[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        Lista_pushBack(&intlist, &nums[i]);
    }

    int intKey = 5;
    
    Lista_next(&intlist);
    Lista_next(&intlist);
    Lista_previous(&intlist);
    Lista_removeCurrent(&intlist);
    Lista_remove(&intlist, &intKey, int_cmp);

    while (intlist.current != NULL) {
        printf("%d\n", *(int*)intlist.current->data);
        
        Lista_next(&intlist);
    }

    int a = 1;
    int b = 1;

    long c = 1l;
    long d = 1l;
    
    int containsIntKey = Lista_search(&intlist, &intKey, int_cmp);
    printf("Contem a chave int 5: %d\n", containsIntKey);

    Lista_delete(&intlist);

    Lista longList;
    Lista_new(&longList, sizeof(long), NULL);

    long longs[] = {1l, 2l, 3l, 4l, 5l};

    for (int i = 0; i < 5; i++) {
        Lista_pushBack(&longList, &longs[i]);
    }

    Lista_next(&longList);

    while (longList.current != NULL) {
        printf("%ld\n", *(long*)longList.current->data);
        
        Lista_next(&longList);
    }

    long longKey = 1l;

    int containsLongKey = Lista_search(&longList, &longKey, long_cmp);
    printf("Contem a chave long 1: %d\n", containsLongKey);

    Lista_delete(&longList);

    Lista floatList;
    Lista_new(&floatList, sizeof(float), NULL);

    float floats[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};

    for (int i = 0; i < 5; i++) {
        Lista_pushBack(&floatList, &floats[i]);
    }

    Lista_next(&floatList);

    while (floatList.current != NULL) {
        printf("%f\n", *(float*)floatList.current->data);
        
        Lista_next(&floatList);
    }

    float floatKey = 3.0f;
    
    int containsFloatKey = Lista_search(&floatList, &floatKey, float_cmp);

    Lista_delete(&floatList);

    //to-do: verificar se todos os métodos foram implementados
    //to-do: criar uma branch separada e criar uma lista duplamente encadeada
}
