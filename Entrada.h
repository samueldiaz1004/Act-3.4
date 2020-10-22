/*/
Header de la clase Entrada

Clase que almacena individualmente los detalles (Mes, dia, fecha, direccion IP y razon de falla)
de una instancia registrada en el archivo "bitacora.txt". Adicionalmente los adecua para ser
candidatos optimos para los algoritmos de ordenamiento y busqueda en una lista doblemente enlazda.

Owen Jauregui Borbon - A01638122
Luis Humberto Sanchez Vaca - A01638029
Samuel Alejandro Diaz del Guante Ochoa - A01637592
/*/
#ifndef ENTRADA_H
#define ENTRADA_H

#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

class Entrada
{
    public:
        Entrada(string linea);
        unsigned long long getIp();
        void print(ostream &stream);

    private:
        string mes;
        string dia;
        string hora;
        string ip;
        string mensaje;
        unsigned long long id;
        void separacion(vector<string> &datos, string linea);
        void separacionIp(vector<string> &datos, string linea);
        void convertirIp(vector<string> datosIp);

};

#endif
