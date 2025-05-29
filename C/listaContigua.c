#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int len;
    int size;
    int *data; 
} List;


List *lista_criar(int size) {
    List *list = (List*) malloc(sizeof(List));

    if (list == NULL) {
        return NULL;
    }

    list->data = (int*) malloc(sizeof(int) * size);

    if (list->data == NULL) {
        free(list->data);
        return NULL;
    }
    
    list->size = size;
    list->len = 0;

    return list;

}

void lista_implodir(List *list) {
    free(list->data);
    free(list);
}

int lista_adicionar_final(List *list, int valor) {
    if(list->len >= list->size) {
        printf("Faltou espaço\n");
        return -1;
    }

    list->data[list->len] = valor;
    list->len ++;
    
    return 1;

}

int lista_adicionar_posi(List *list, int posi, int valor) {
    if (list->len >= list->size) {
        printf("Faltou espaço\n");
        return -1;
    }
    
    if (posi > list->len) {
        printf("Não é possivel adicionar pois a lista pequena de mais :(\n");
        return 0;
    }

    for(int i = list->len; i >= posi; i--) {
        list->data[i + 1] = list->data[i];
    }

    list->data[posi] = valor;
    list->len ++;

    return 0;
}

int lista_remover(List *list, int index) {
    if (index < 0 && list->len <= 0) {
        printf("Index inválido\n");
        return -1;
    }
    
    
    for(int i = index; i < list->len; i++){
        list->data[i] =  list->data[i+1];
    }


    list->len --;
}

void lista_mostrar(List *list) {
    int i = 0;
    
    for(i = 0; i < list->len; i++) {
        printf("%i ", list->data[i]);
    }

    printf("\n");
}

int adicionar_ordem_crescente(List *list, int valor) {
    if (list->len >= list->size) {
        printf("Erro ao adicionar item :(\n");
        return -1;
    }
    
    if (list->len == 0) {
        lista_adicionar_final(list, valor);
        return 0;
    }

    int i = 0;

    while (i > list->len) {
        if (valor >= list->data[i]) break;
        i++;
    }

    lista_adicionar_posi(list, i, valor);

    return 0;
}


int main(int argc, char **argv) {

    List *list = lista_criar(10);

    adicionar_ordem_crescente(list, 10);
    adicionar_ordem_crescente(list, 2);
    adicionar_ordem_crescente(list, 1);
    adicionar_ordem_crescente(list, 1);

    lista_mostrar(list);

    lista_implodir(list);

    return 0;

}