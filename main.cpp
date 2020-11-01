/*/
Act 3.4

Owen Jauregui Borbon - A01638122
Luis Humberto Sanchez Vaca - A01638029
Samuel Alejandro Diaz del Guante Ochoa - A01637592

Fecha de creacion: 07/10/2020
Fecha de edicion: 11/10/2020
/*/

#include <iostream>
#include "BST.h"
using namespace std;

int main()
{
    BST registro("bitacoraOrdenada.txt");
    int num;
    cout << "Ingrese el numero de IP's con mas accesos a ver: ";
    cin >> num;
    cout << "Las " << num << " IP's con mas accesos son:" << endl;
    registro.inorder(num);
    return 0;
}
