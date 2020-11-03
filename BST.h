/*/
Header de la clase BST

Clase que almacena la informacion ip junto al su numero de accesos
ilegales registrados en una bitacora ordenada.
La esctructuara de la clase esta basada en un "binary search tree"
y tiene como funcion principal anexar dichas entradas y despliegar
una cantidad especifica en orden de mayor a menor numero de accesos.

Owen Jauregui Borbon - A01638122
Luis Humberto Sanchez Vaca - A01638029
Samuel Alejandro Diaz del Guante Ochoa - A01637592
/*/

#ifndef BST_H
#define BST_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct NodeBST
{
    NodeBST* right = nullptr;
    NodeBST* left = nullptr;
    string ip;
    int cont;

    NodeBST(string ip, int cont)
    {
        this->ip = ip;
        this->cont = cont;
    }
};

class BST
{
    public:
        BST(string fileName);
        ~BST();
        void inorder(int amount);

    private:
        NodeBST* root;
        void insert(string ip, int n);
        void inorder(int& amount, NodeBST* current);
        void removePostorder(NodeBST* current);
};

#endif
