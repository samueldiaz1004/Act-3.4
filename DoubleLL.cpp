/*/
Implementacion de la clase DoubleLL

Owen Jauregui Borbon - A01638122
Luis Humberto Sanchez Vaca - A01638029
Samuel Alejandro Diaz del Guante Ochoa - A01637592
/*/
#include "DoubleLL.h"

// Constructor de la clase DoubleLL
// No recibe parametros
DoubleLL::DoubleLL(){
    // Inicializa los punteros head y tail como nulos
    this->tail = this->head = nullptr;
    // Inicializa el tamaño de la lista en 0
    size = 0;
}

// Destructor de la clase DoubleLL
DoubleLL::~DoubleLL()
{
    // Mientras la lista no este vacia manda a llamar
    // el metodo pull para remover los elementos
    while (!isEmpty()){
        pull();
    }
}

// Metodo que regresa un entero con la cantidad de
// elementos dentro de la lista
// No recibe parametros
int DoubleLL::length() {
    return this->size;
}

// Metodo que regresa true si la lista no tiene
// elementos, false en caso contrario
// No recibe parametros
bool DoubleLL::isEmpty() {
    return this->size == 0;
}

// Metodo que sirve para agregar elementos al final de la lista
// Recibe un apuntador de tipo entrada con la informacion
// del nuevo elemento
// No regresa nada
void DoubleLL::push(Entrada* data) {
    // Si la lista esta vacia asigna a head y tail un nuevo
    // nodo con los datos que recibio
    if (isEmpty()){
        this->head = this->tail = new Node(data);
    }else{
        // En caso contrario se crea un nodo cuyo prev se asigna a tail
        // el next de tail se asigna a este nodo y finalmente tail
        // cambia a el nuevo nodo creado.
        this->tail = this->tail->next = new Node(data, nullptr, this->tail);
    }
    // Se incrementa el size
    this->size++;
}

// Metodo que sirve para eliminar el primer elemento de la lista
// No recibe ni regresa nada
void DoubleLL::pull() {
    // Checa que la lista no este vacia
    if (!isEmpty()) {
        // Se guarda el nodo de head
        Node *current = this->head;
        // Se cambia head al siguiente elemento
        this->head = this->head->next;
        // Se decrementa el size
        this->size--;
        // Si la lista quedo vacia tail se hace un puntero nulo
        if (isEmpty()){
            this->tail = nullptr;
        }else{
            // En caso contrario el anterior de head se hace
            // un puntero nulo
            this->head->prev = nullptr;
        }
        // Se borra el apuntador dinamico de la informacion
        delete current->data;
        // Se borra el apuntador dinamico del nodo
        delete current;
    }else {
        // Si la lista esta vacia se arroja una excepcion
        throw invalid_argument("Empty list");
    }
}

// Funcion de preparacion para el ordenamiento por algoritmo 
// de ordenamiento "Quick Sort"
// No recibe parametros
// No devuelve ningun valor
// Complejidad: 
//      Mejor de los casos O(n*log(n))
//      Peor de los casos O(n^2)
//      Promedio O(n*log(n))
void DoubleLL::quickSort() {
    // Se pasan los punteros de inicio y fin de la Double Linked List
    quickSort(this->head, this->tail);
}

// Funcion recursiva para el ordenamiento por el algoritmo "Quick Sort"
// Recibe dos punteros a Node para el inicio y fin del segmento
// que se va a ordenar para cada recursion
// No devuelve ningun valor
// Complejidad: 
//      Mejor de los casos O(n*log(n))
//      Peor de los casos O(n^2)
//      Promedio O(n*log(n))
void DoubleLL::quickSort(Node* ini, Node* fin) {
    // Condicional para saber si el inicio esta antes que el fin
    // y si el fin aun sigue siendo un puntero valido
    if (fin != nullptr && ini != fin && fin->next != ini) {
        // Llamada a la funcion "particionar"
        Node* piv = particionar(ini, fin);
        // Recursion para ordenar los datos a la izquierda y a
        // la derecha del pivote
        quickSort(ini, piv->prev);
        quickSort(piv->next, fin);
    }
}

// Funcion para realizar la separacion de numeros mayores y 
// menores con respecto a un pivote (en este caso, el primer 
// elemento del segmento). Los numeros mayores se acomodan a la
// derecha del pivote, mientras los menores se colocan a su izquierda
// Recibe dos punteros a Node para el inicio y fin del segmento
// en el que se realizara la division
// Complejidad: O(n)
Node* DoubleLL::particionar(Node* ini, Node* fin) {
    // El nodo "ini" se selecciona como el pivote
    // Se toma la ip del primer elemento para las comparaciones
    unsigned long long piv = ini->data->getIp();
    // Se definen las variables i y j que serviran como indicadores
    // para los segmentos de elementos desordenados, los mayores 
    // al pivote y los menores al pivote
    Node *i = ini->next,
         *j = i;
    // Se hace un ciclo hasta que j llegue al final del segmento
    // a separar
    while (j != fin->next) {
        // en caso de que la Ip del dato en el puntero j sea menor
        // o igual al del pivote, se manda al segmento de los
        // elementos menores
        if (j->data->getIp() <= piv) {
            swap(i, j);
            // En caso de que i->next sea valido, se asigna el
            // puntero del siguiente siguiente nodo a i. De lo
            // contrario significa que pasamos el final de la
            // Double Linked List, por lo tanto se le asigna el
            // puntero al nodo "fin"
            i = (i->next == nullptr)? fin : i->next;
        }
        // Se avanza j, pasando al siguiente nodo a comparar
        j = j->next;
    }
    // En caso de que el elemento que sigue de i sea invalido,
    // se hace un intercambio del pivote (ini) con i, debido a 
    // que tuvimos que retroceder retroceder un elemento. 
    // Normalmente se haría el intercambio con el anterior a i
    if (i->next != nullptr){
        swap(ini, i->prev);
    } else {
        swap(ini, i);
    }
    return i->prev;
}

// Funcion para intercambiar los punteros a Entrada que contienen
// dos objetos de tipo Node distintos
// Recibe dos punteros a objetos de tipo Node
// No devuelve ningun valor
void DoubleLL::swap(Node* a, Node* b) {
    // Se guarde el data de b en una variable temporal
    Entrada* temp = b->data;
    // Se intercambian los valores de data con el uso de la
    // variable temporal
    b->data = a->data;
    a->data = temp;
}

// Funcion que sirve para imprimir la informacion de la lista
// Recibe el tipo de salida para impresion, la posicion donde
// se quiere iniciar y terminar de imprimir
// No regresa nada
void DoubleLL::print(ostream &stream, int ini, int fin) {
    // Se guarda el nodo head
    Node* current = this->head;
    // Se itera hasta llegar a la posicion inicial que se pide
    for (int i = 0; i < ini; i++){
        // Se va avanzando al siguiente nodo
        current = current->next;
    }
    // Se itera a partir de la posicion inicial hasta la final
    for (int i = ini; i <= fin; i++){
        // Se imprimen la informacion del elemento
        current->data->print(stream);
        stream << endl;
        // Se va avanzando al siguiente nodo
        current = current->next;
    }
}

// Funcion que sirve para encontrar la posicion de un elemento por su ip
// Recibe la ip sin puerto y un booleano que indica como se quiere recorrer
// la lista. Regresa un entero con la posicion encontrada
// Complejidad: 
//      Mejor de los casos O(1)
//      Peor de los casos O(n)
//      Promedio O(n)
int DoubleLL::busqueda(unsigned long long ip, bool reverse) {
    // Se crea un puntero a nodo y un entero con la posicion
    Node* current;
    int pos;
    // Si reverse es falso
    if (!reverse){
        // Current inicia en head y pos en 0
        current = this->head;
        pos = 0;
        // Se checa que current no llegue a un puntero nulo
        while (current != nullptr){
            // Se guarda la ip sin puerto del elemento actual
            unsigned long long ipAux = current->data->getIp() / 10000;
            // Si la ip del elemento es mayor o igual a la que buscamos
            // Se regresa la posicion
            if (ipAux >= ip){
                return pos;
            }else{
                // En caso contrario se avanza al siguiente elemento
                // y se incrementa pos
                current = current->next;
                pos++;
            }
        }
    }else{
        // Si reverse es true
        // Current inicia en tail y pos en size - 1
        current = this->tail;
        pos = this->size - 1;
        // Se checa que current no llegue a un puntero nulo
        while (current != nullptr){
            // Se guarda la ip sin puerto del elemento actual
            unsigned long long ipAux = current->data->getIp() / 10000;
            // Si la ip del elemento es menor o igual a la que buscamos
            // Se regresa la posicion
            if (ipAux <= ip){
                return pos;
            }else{
                // En caso contrario se avanza al elemento previo
                // y se decrementa pos
                current = current->prev;
                pos--;
            }
        }
    }
    // En caso de llegar a un puntero nulo significa que no se encontro la ip
    // y se regresa -1
    return -1;
}