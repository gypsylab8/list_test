#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node {
    void* value;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(void* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Função para inverter a lista encadeada
Node* inverteLista(Node* head) {
    Node* previous = NULL;
    Node* current = head;
    Node* next_node = NULL;

    while (current != NULL) {
        next_node = current->next;
        current->next = previous;
        previous = current;
        current = next_node;
    }

    return previous;
}

// Função auxiliar para imprimir os valores da lista encadeada
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        // A conversão do ponteiro void* para o tipo adequado depende do conhecimento do tipo armazenado na lista.
        // Neste exemplo, vamos assumir que os valores são do tipo char*.
        printf("%s\n", (char*)current->value);
        current = current->next;
    }
}

int main() {
    // Criação dos nós da lista
    Node* node1 = createNode("Oi");
    Node* node2 = createNode("5");
    Node* node3 = createNode("1/1/2005 14:00:00");
    Node* node4 = createNode("1.5");
    Node* node5 = createNode("Tchau");

    // Construção da lista encadeada
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Inverte a lista
    Node* head = inverteLista(node1);

    // Imprime a lista invertida
    printList(head);

    // Libera a memória alocada para a lista encadeada
    Node* current = head;
    while (current != NULL) {
        Node* next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}

