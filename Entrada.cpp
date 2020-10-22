/*/
Implementacion de la clase Entrada

Owen Jauregui Borbon - A01638122
Luis Humberto Sanchez Vaca - A01638029
Samuel Alejandro Diaz del Guante Ochoa - A01637592
/*/
#include "Entrada.h"

// Constructor de la clase Entrada
// Recibe un string con toda la informacion del acceso ilegal
Entrada::Entrada(string linea)
{
    // Vector que almacena los datos del acceso separados (mes, dia, tiempo, ip, mensaje)
    vector<string> segmento{"","","","",""};
    // Vector que almacena la direccion ip por segmentos (###.###.###.###.####)
    vector<string> segmentoIp{"","","","",""};
    // Se separan los datos del acceso
    separacion(segmento,linea);
    // Se separan las partes de la ip
    separacionIp(segmentoIp,segmento[3]);
    // Se asigan los valores del acceso a su atributo correspondiente
    this->mes = segmento[0];
    this->dia = segmento[1];
    this->hora = segmento[2];
    this->ip = segmento[3];
    this->mensaje = segmento[4];
    // Se crea un entero a partir de la ip segmentada para facilitar su ordenamiento
    convertirIp(segmentoIp);
}

// Metodo de acceso al valor de id (ip formateado)
// No recibe valores
// Regresa un entero (unsigned long long);
// Se utilizo este tipo de dato ya que fue el unico capaz de
// operar y almacenar la ip convenertida (16 digitos)
unsigned long long Entrada::getIp()
{
    return this->id;
}

// Metodo de impresion de los valores del acceso
// Recibe el tipo de salida
// No regresa algun valor
void Entrada::print(ostream &stream)
{
    stream << this->mes << " "
           << this->dia << " "
           << this->hora << " "
           << this->ip << " "
           << this->mensaje;
}

// Metodo para separar la informacion del acceso en un vector
// Recibe el vector por referencia en donde se guardan los datos separados
// y un string con los datos del acceso a separar
// No regresa algun valor
void Entrada::separacion(vector<string> &datos, string linea)
{
    // Contador del elemento que corresponde al dato
    int espacios = 0;
    // Se recorre el string caracter por caracter
    for(auto j : linea){
        // Cuando se encuentra un espacio se cambia de elemento, esto se hace
        // antes de llegar al ultimo elemento (mensaje) que requiere almacenar espacios
        if(j == ' ' && espacios < 4){
            espacios++;
        }
        else{
            // En caso de que no se identifique un espacio se cocatena el caracter
            datos[espacios] += j;
        }
    }
}

// Metodo para separar la informacion dentro de la ip (formato: ###.###.###.###.####)
// Recibe el vector por referencia en donde se guardan los datos separados
// y un string con la ip a separar
// No regresa algun valor
void Entrada::separacionIp(vector<string> &datos, string linea)
{
    // Contador del elemento que corresponde al dato
    int espacios = 0;
    // Se recorre el string caracter por caracter
    for(auto j : linea){
        // Cuando se encuentra un punto (.) o dos puntos (:) se cambia de elemento
        if(j == '.' || j == ':'){
            espacios++;
        }
        else{
            // De cualquier otro caso se concatena el caracter
            datos[espacios] += j;
        }
    }
}

// Metodo que crea un entero (id) para facilitar su ordenamiento
// Recibe un vector con la ip separada en conjuntos
// No regresa algun valor
void Entrada::convertirIp(vector<string> datosIp)
{
    // La ip se calcula de manera que quede en formato (###.###.###.###)
    // Tres digitos por segemento y cuatro para la puerta de acceso
    // Entrada: 423.2.230.77 -> Valor almacenado: 423002230077
    this->id += stoi(datosIp[3]);
    this->id += stoi(datosIp[2]) * pow(10,3);
    this->id += stoi(datosIp[1]) * pow(10,6);
    this->id += stoi(datosIp[0]) * pow(10,9);
}
