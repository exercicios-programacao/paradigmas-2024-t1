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

#include "lista.h"

int int_cmp(const void *lhs, const void* rhs){
    if (lhs == rhs)
    {
        return 1;
    }
    else return 0;
}

void Integer_test()
{
    Lista minha_lista;
    Lista_new(&minha_lista,sizeof(int),NULL);

    int isVazio = Lista_isEmpty(&minha_lista);

    if(isVazio = 1)
        printf("\nA lista tah vazia\n");
    else
        printf("\nA lista nao tah vazia\n");

    Lista_imprime(&minha_lista);

    Lista_pushFront(&minha_lista, 20);
    Lista_pushFront(&minha_lista, 30);
    Lista_pushFront(&minha_lista, 40);
    Lista_pushFront(&minha_lista, 50);

    Lista_imprime(&minha_lista);

    printf("\nO tamanho da minha lista eh: %d\n",Lista_size(&minha_lista));

    Lista_delete(&minha_lista);

    isVazio = Lista_isEmpty(&minha_lista);

    if(isVazio = 1)
        printf("\nA lista tah vazia\n");
    else
        printf("\nA lista nao tah vazia\n");

    printf("\nMinha lista foi deletada, entao vou criar uma nova!\n");

    Lista_new(&minha_lista,sizeof(int),NULL);

    if(isVazio = 1)
        printf("\nA lista tah vazia\n");
    else
        printf("\nA lista nao tah vazia\n");

    Lista_imprime(&minha_lista);

    Lista_pushFront(&minha_lista, 20);
    Lista_pushFront(&minha_lista, 30);
    Lista_pushFront(&minha_lista, 40);
    Lista_pushFront(&minha_lista, 50);

    Lista_imprime(&minha_lista);

    Lista_pushBack(&minha_lista, 60);
    Lista_pushBack(&minha_lista, 70);
    Lista_pushBack(&minha_lista, 80);
    Lista_pushBack(&minha_lista, 90);

    Lista_imprime(&minha_lista);

    printf("\nAgora vou procurar uns valores na minha lista!\n");

    int chave = 30;
    int *dest = (int *)malloc(sizeof(int));
    int hasKey =
        Lista_search(&minha_lista,
                     chave,
                     dest,
                     int_cmp
                     );
    if(hasKey == 1)
    {
        printf("\nO valor %d foi encontrado!\n",*dest);
    }
    else{
        printf("\nNenhum valor encontrado!\n");

    }

    free(*dest);

    chave = 81;
    hasKey =
        Lista_search(&minha_lista,
                     chave,
                     &dest,
                     int_cmp
                     );
    if(hasKey == 1)
    {
        printf("\n1 - O valor %d foi encontrado!\n",&dest);
    }
    else{
        printf("\nNenhum valor encontrado!\n");
    }

    chave = 30;
    printf("\nAgora vou remover o valor %d da minha lista!\n",chave);

    Lista_remove(&minha_lista,chave,int_cmp);

    Lista_imprime(&minha_lista);

    printf("\nAgora vou procurar o valor %d na minha lista!\n",chave);
    *dest = (int *)malloc(sizeof(int));
    hasKey =
        Lista_search(&minha_lista,
                     chave,
                     dest,
                     int_cmp
                     );
    if(hasKey == 1)
        printf("\nO valor %d foi encontrado!\n",*dest);
    else{
        printf("\nNenhum valor encontrado!\n",*dest);
        free(*dest);
    }

    Lista_imprime(&minha_lista);

    Lista_first(&minha_lista);

    Lista_last(&minha_lista);

    Lista_next(&minha_lista);

    Lista_first(&minha_lista);

    Lista_next(&minha_lista);

    Lista_next(&minha_lista);

    Lista_next(&minha_lista);

    Lista_next(&minha_lista);

    Lista_next(&minha_lista);

    Lista_next(&minha_lista);
}

void String_test()
{
    Lista minha_lista;
    Lista_new(&minha_lista,sizeof(char*),"\n");

    int isVazio = Lista_isEmpty(&minha_lista);

    if(isVazio = 1)
        printf("\nA lista tah vazia\n");
    else
        printf("\nA lista nao tah vazia\n");

    Lista_imprime(&minha_lista);

    Lista_pushFront(&minha_lista, "B");
    Lista_pushFront(&minha_lista, "Maçã");
    Lista_pushFront(&minha_lista, "Limão");
    Lista_pushFront(&minha_lista, "Melão");

    Lista_imprime(&minha_lista);

    printf("\nO tamanho da minha lista eh: %d\n",Lista_size(&minha_lista));

    Lista_delete(&minha_lista);

    isVazio = Lista_isEmpty(&minha_lista);

    if(isVazio = 1)
        printf("\nA lista tah vazia\n");
    else
        printf("\nA lista nao tah vazia\n");

    printf("\nMinha lista foi deletada, entao vou criar uma nova!\n");

    Lista_new(&minha_lista,sizeof(int),NULL);

    if(isVazio = 1)
        printf("\nA lista tah vazia\n");
    else
        printf("\nA lista nao tah vazia\n");

    Lista_imprime(&minha_lista);

    Lista_pushFront(&minha_lista, "Banana");
    Lista_pushFront(&minha_lista, "Maca");
    Lista_pushFront(&minha_lista, "Limao");
    Lista_pushFront(&minha_lista, "Melao");

    Lista_imprime(&minha_lista);

    Lista_pushBack(&minha_lista, "Melancia");
    Lista_pushBack(&minha_lista, "Abacate");
    Lista_pushBack(&minha_lista, "Laranja");
    Lista_pushBack(&minha_lista, "Morango");

    Lista_imprime(&minha_lista);

    printf("\nAgora vou procurar uns valores na minha lista!\n");

    char chave = "Abacate";
    char *dest = (char *)malloc(sizeof(char));
    char hasKey =
        Lista_search(&minha_lista,
                     chave,
                     dest,
                     int_cmp
                     );
    if(hasKey == 1)
    {
        printf("\nO valor %d foi encontrado!\n",*dest);
    }
    else{
        printf("\nNenhum valor encontrado!\n");

    }

    free(*dest);

    chave = "Kiwi";
    hasKey =
        Lista_search(&minha_lista,
                     chave,
                     &dest,
                     int_cmp
                     );
    if(hasKey == 1)
    {
        printf("\n1 - O valor %d foi encontrado!\n",&dest);
    }
    else{
        printf("\nNenhum valor encontrado!\n");
    }

    chave = "Melancia";
    printf("\nAgora vou remover o valor %d da minha lista!\n",chave);

    Lista_remove(&minha_lista,chave,int_cmp);

    Lista_imprime(&minha_lista);

    printf("\nAgora vou procurar o valor %d na minha lista!\n",chave);
    *dest = (char *)malloc(sizeof(char));
    hasKey =
        Lista_search(&minha_lista,
                     chave,
                     dest,
                     int_cmp
                     );
    if(hasKey == 1)
        printf("\nO valor %d foi encontrado!\n",*dest);
    else{
        printf("\nNenhum valor encontrado!\n",*dest);
        free(*dest);
    }

    Lista_imprime(&minha_lista);

    Lista_first(&minha_lista);

    Lista_last(&minha_lista);

    Lista_next(&minha_lista);

    Lista_first(&minha_lista);

    Lista_next(&minha_lista);

    Lista_next(&minha_lista);

    Lista_next(&minha_lista);

    Lista_next(&minha_lista);

    Lista_next(&minha_lista);

    Lista_next(&minha_lista);
}

void Struct_test()
{

}

int main(int argc, char** argv) {
    printf("Iniciando os testes...!\n");

    //Integer_test();
    String_test();
    return 0;
}
