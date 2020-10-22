/*/
Header de la clase Registro

Clase que se encarga de almacenar datos de tipo Entrada
provenientes del archivo "Bitacora.txt" en una lista doblemente
enlazada. Asimismo ordena y hace busquedas por medio de metodos
de la clase "DoubleLL"

Owen Jauregui Borbon - A01638122
Luis Humberto Sanchez Vaca - A01638029
Samuel Alejandro Diaz del Guante Ochoa - A01637592
/*/

#ifndef REGISTRO_H
#define REGISTRO_H

#include "DoubleLL.h"
#include "BST.h"
#include <fstream>
#include <string>

class Registro
{
    public:
        Registro(string fileName);
        void quickSort();
        void guardar(string fileName);
        void busqueda(string ipIni, string ipFin);
        void print(ostream& stream);
        void inorder(int amount);

    private:
        DoubleLL bitacora;
        void print(ostream& stream, int ini, int fin);
        void separar(vector<string> &datos, string linea);

};

#endif
