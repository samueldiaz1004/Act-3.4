/*/
Act 2.3 - Actividad Integral estructura de datos lineales
Programa para el ordenamiento y busqueda en un
registro de accesos ilegales a un servidor almacenados
en el archivo "bitacora.txt"

Owen Jauregui Borbon - A01638122
Luis Humberto Sanchez Vaca - A01638029
Samuel Alejandro Diaz del Guante Ochoa - A01637592

Fecha de creacion: 07/10/2020
Fecha de edicion: 11/10/2020
/*/

#include <iostream>
#include "Registro.h"
using namespace std;

int main()
{
    bool opcion;
    string ipIni;
    string ipFin;
    Registro bitacora("bitacora2.txt");
    bitacora.quickSort();
    bitacora.guardar("bitacoraOrdenada.txt");
    do{
        cout << "Selecciona una opcion:" << endl;
        cout << "1. Realizar busqueda" << endl;
        cout << "0. Salir del programa" << endl;
        cin >> opcion;
        if(opcion){
            cin.ignore();
            cout << "Ip inicio: ";
            getline(cin,ipIni);
            cout << "Ip fin: ";
            getline(cin,ipFin);
            cout << "Resultados" << endl;
            // Formato de entrada: ###.###.###.###
            // (ipIni < ipFin) para despliegue de entradas ascendentes
            bitacora.busqueda(ipIni,ipFin);
            cout << endl;
        }
    }
    while(opcion);
    return 0;
}
