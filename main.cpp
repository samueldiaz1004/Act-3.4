/*/
Act 3.4 - Actividad Integral de BST
Programa para encontrar las n IP's con mayor
cantidad de accesos ilegales registrados en
el archivo "bitacoraOrdenada.txt"

Owen Jauregui Borbon - A01638122
Luis Humberto Sanchez Vaca - A01638029
Samuel Alejandro Diaz del Guante Ochoa - A01637592

Fecha de creacion: 23/10/2020
Fecha de edicion: 02/11/2020
/*/

#include "BST.h"

int main()
{
    BST registro("bitacoraOrdenada.txt");
    bool opcion;

    do {
        int num;
        cout << "Ingrese el numero de IP's con mas accesos a ver: ";
        cin >> num;
        cout << "Las " << num << " IP's con mas accesos son:" << endl;
        registro.inorder(num);
        cout << "Seleccione una opcion:" << endl;
        cout << "Hacer otra consulta - 1" << endl;
        cout << "Salir - 0" << endl;
        cin >> opcion;
    }
    while(opcion);

    return 0;
}
