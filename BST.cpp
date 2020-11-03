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

// Destructor de la clase BST
// Complejidad O(n)
BST::~BST()
{
    // Llamar a metodo para borrar todos los nodos del arbol
    removePostorder(this->root);
}

// Metodo iterativo que coloca un nodo manteniendo las propiedades del BST
// Recibe el numero de la ip (sin puerto) en formato string y
// las veces que se repite en la bitacora
// No regresa algun dato
// Complejidad:
//      Mejor de los casos O(1)
//      Peor de los casos O(n)
//      Promedio O(log(n))
void BST::insert(string ip, int n)
{
    // Se crea un nuevo nodo con la informacion que se
    // desea colocar en el BST
    NodeBST* nvo = new NodeBST(ip, n);
    // Caso 1:
    // El BST esta vacio
    if(this->root == nullptr){
        // Se asigna a root el nuevo nodo
        this->root = nvo;
        // termina la operacion
        return;
    }
    // Nodos auxiliares para insertar nuevo nodo
    NodeBST* current = this->root;
    NodeBST* previous;
    // Caso 2:
    // Recorrer el BST hasta una hoja adecuada
    while(current != nullptr){
        // Si el nodo es menor al que se esta comparando
        // entonces current se desplaza a la izquierda del nodo al que apunta
        if(n < current->cont){
            previous = current;
            current = current->left;
        }
        // Si el nodo es mayor al que se esta comparando
        // o su valor es igual pero la ip es mayor,
        // entonces current se desplaza a la derecha del nodo al que apunta
        else{
            previous = current;
            current = current->right;
        }
    }
    // Si es menor, colocar el nuevo nodo a la izquierda
    // de la hoja a la que esta apuntando
    if(n < previous->cont){
        previous->left = nvo;
    }
    // De cualquier otra forma, colocar el nuevo nodo a
    // la derecha de la hoja a la que esta apuntando
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

// Metodo recursivo que elimina todos los nodos del BST
// Recibe apuntador a un nodo, empezando por la raiz
// No regresa algun dato
// Complejidad: O(n)
void BST::removePostorder(NodeBST* current)
{
    // Sigue la estructura de un recorrido postorder
    // para eliminar los nodos de las hojas hacia la raiz
    if(current != nullptr){
        removePostorder(current->left);
        removePostorder(current->right);
        delete current;
    }
}
