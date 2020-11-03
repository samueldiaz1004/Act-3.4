#include "BST.h"

// Constructor de la clase BST, se encarga de leer las ips que 
// se encuentran en el archivo con los accesos ordenados y 
// registrar la cantidad de apariciones (sin considerar el puerto)
// Recibe el nombre del archivo que contiene los accesos ordenados
// Complejidad: O(n)
BST::BST(string fileName)
{
    // Se inicializa la raiz a nullptr
    this->root = nullptr;

    // Variables auxiliares para la insersion de nodos
    string ip_, 
           pastIp = "";
    int ipReps = 0;

    // Se abre el archivo que contiene los accesos ordenados
    fstream file;
    file.open(fileName);

    // Ciclo para leer las ips del archivo de bitacora
    while(getline(file, ip_)) {
        string ip = "";
        int spaces = 0;

        // Ciclo para extraer la ip de cada linea del archivo
        for (int i = 0; i < ip_.length(); i++) {
            // Separacion de los segmentos por espacios
            if (ip_[i] != ' ') {
                // Condicional para seleccionar solo la ip
                if (spaces == 3) {
                    // Condicional para terminar el ciclo y
                    // extraer la ip sin el puerto
                    if (ip_[i] != ':') {
                        ip += ip_[i];
                    } else {
                        break;
                    }
                }
            } else {
                // En caso de encontrar un espacio, se incrementa
                // spaces
                spaces++;
            }
        }

        // Condicional para contar la cantidad de veces que se
        // repitio la ultima ip. Si la ultima ip es diferente a
        // la ip actual, entonces la ultima ip se agrega junto
        // a su contador
        if (ip != pastIp && pastIp != "") {
            // Llamada a insert con la ip anterior y las veces
            // que se repitio
            insert(pastIp, ipReps);
            // Se restablece el contador
            ipReps = 1;
        } else {
            // En caso de ser igual al anterior, se incrementa
            // el contador
            ipReps++;
        }

        // La ip actual pasa a ser la anterior
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
