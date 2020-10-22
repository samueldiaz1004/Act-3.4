/*/
Header de la clase DoubleLL

Clase que almacena punteros a objetos tipo Entrada mediante la
implementacion de la estructura de datos "Double Linked List".
Puede realizar el ordenamiento de cada Entrada basandose en su
ip y tambien realizar busquedas de la primera o ultima ocurrencia
de una ip especifica.

Owen Jauregui Borbon - A01638122
Luis Humberto Sanchez Vaca - A01638029
Samuel Alejandro Diaz del Guante Ochoa - A01637592
/*/
#ifndef DOUBLELL_H
#define DOUBLELL_H

#include "Entrada.h"

struct Node{
    Entrada* data;
    Node* next;
    Node* prev;

    Node(Entrada* data, Node* next, Node* prev){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    Node(Entrada* data):Node(data, nullptr, nullptr){}
};

class DoubleLL
{
    public:
        DoubleLL();
        ~DoubleLL();
        void push(Entrada* data);
        int length();
        bool isEmpty();
        void quickSort();
        int busqueda(unsigned long long ip, bool reverse);
        void print(ostream& stream, int ini, int fin);

    private:
        Node* head;
        Node* tail;
        int size;
        void pull();
        void quickSort(Node* ini, Node* fin);
        void swap(Node* a, Node* b);
        Node* particionar(Node* ini, Node* fin);
};

#endif
