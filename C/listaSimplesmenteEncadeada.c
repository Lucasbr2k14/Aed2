#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *node_create(int value) {
    Node *node = (Node*) malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

void inserir_inicio(Node **head, int value) {
    Node *new_node = node_create(value);
    new_node->next = *head;
    *head = new_node;
}

void inserir_final(Node **head, int value) {
    if (*head == NULL) return;

    Node *pos = *head;
    
    while (pos->next != NULL) {
        pos = pos->next;
    }
    
    Node *new_node = node_create(value);
    pos->next = new_node;
}

void inserir_posi(Node **head, int index, int value) {
    if (*head == NULL || index < 0) return;
    
    if (index == 0 ) {
        inserir_inicio(head, value);
        return;
    }


    Node *pos = *head;
    int i = 0;

    while(i < index-1 && pos != NULL) {
        pos = pos->next;
        i++;
    }
    
    if (pos == NULL) {
        printf("Erro ao adicionar na posição: %i\n", index);
        return;
    }

    Node *new_node = node_create(value);
    new_node->next = pos->next;
    pos->next = new_node;

}

void excluir_node(Node **head, int index) {
    if (*head == NULL || index < 0) return;

    if (index == 0) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    int i = 0;
    
    Node *pos = *head;

    while((pos != NULL) && (i < index-1)) {
        pos = pos->next;
        i++;
    }

    Node *temp = pos->next;
    pos->next = temp->next;
    free(temp);
}

int length(Node **head) {
    Node *pos = *head;

    int i = 0;

    while (pos != NULL) {
        pos = pos->next;
        i++;
    }
    return i;
}

Node *pegar_posi(Node **head, int index) {
    Node *pos = *head;
    int i = 0;

    while ((pos != NULL) && (i < index -1)) {
        i++;
        pos = pos->next;
    }

    return pos;
}

Node *meio(Node **head) {
    Node *fast = *head;
    Node *slow = *head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void mostrar_lista(Node **head) {
    Node *pos = *head;

    while (pos != NULL) {
        printf("%i ", pos->value);
        pos = pos->next;
    }

    printf("\n");
}

int main(int argc, char **argv) {
    Node *head = NULL;

    inserir_inicio(&head, 9092);
    inserir_inicio(&head, 12);
    // inserir_inicio(&head, 20);
    // inserir_final(&head, 10);
    inserir_final(&head, 9123);

    // printf("Tamanho da lista: %i\n", length(&head));

    // inserir_posi(&head, 5, 123);
    // excluir_node(&head, 5);
    // excluir_node(&head, 0);
    Node *m = meio(&head);

    printf("Meio: %i\n", m->value);

    mostrar_lista(&head);

    return 0;    
}