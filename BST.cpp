#include "BST.h"

BST::BST(string fileName)
{
    this->root = nullptr;

    fstream file;
    file.open(fileName);
    string ip_, 
           pastIp = "";
    int ipReps = 0;

    while(getline(file, ip_)) {
        string ip = "";
        int spaces = 0;

        for (int i = 0; i < ip_.length(); i++) {
            if (ip_[i] != ' ') {
                if (spaces == 3) {
                    if (ip_[i] != ':') {
                        ip += ip_[i];
                    } else {
                        break;
                    }
                }
            } else {
                spaces++;
            }
        }

        if (ip != pastIp && pastIp != "") {
            insert(pastIp, ipReps);
            ipReps = 1;
        } else {
            ipReps++;
        }

        pastIp = ip;
    }
}

BST::~BST()
{
    removePostorder(root);
}

void BST::insert(string ip, int n)
{
    NodeBST* nvo = new NodeBST(ip, n);

    if(this->root == nullptr){
        this->root = nvo;
        return;
    }

    NodeBST* current = this->root;
    NodeBST* previous;

    while(current != nullptr){
        if(n < current->cont){
            previous = current;
            current = current->left;
        }
        else{
            previous = current;
            current = current->right;
        }
    }

    if(n < previous->cont){
        previous->left = nvo;
    }
    else{
        previous->right = nvo;
    }
}

// Metodo de preparacion para la llamada
// recursiva de inorder
// Recibe el numero de ip's que se quieren
// imprimir, no regresa nada
// Complejidad: O(n)
void BST::inorder(int amount) {
    inorder(amount, this->root);
    cout << endl;
}

// Metodo recursivo que imprime el arbol mostrando
// la ip y el numero de accesos en orden descendente
// Recibe la cantidad de ip's a mostrar como
// referencia y el nodo actual, no regresa nada
// Complejidad: O(n)
void BST::inorder(int &amount, NodeBST *current) {
    // Se checa que el nodo contenga un valor
    if(current != nullptr) {
        // Se llama inorder con el hijo derecho como actual
        inorder(amount, current->right);
        // Se checa que aun este en el rango de accesos a mostrar
        if (amount > 0) {
            // Se imprime la informacion del nodo
            cout << "IP: " << current->ip << " Accesos: " << current->cont << endl;
            // Se decrementa el contador
            amount--;
        }
        // Se llama inorder con el hijo izquierdo como actual
        inorder(amount, current->left);
    }
}

void BST::removePostorder(NodeBST* current)
{
    if(current != nullptr){
        removePostorder(current->left);
        removePostorder(current->right);
        delete current;
    }
}
