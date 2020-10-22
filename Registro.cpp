/*/
Implementacion de la clase Registro

Owen Jauregui Borbon - A01638122
Luis Humberto Sanchez Vaca - A01638029
Samuel Alejandro Diaz del Guante Ochoa - A01637592
/*/

#include "Registro.h"

// Constructor de la clase Registro
// Recibe una string que es el nombre del archivo "bitacora.txt"
Registro::Registro(string fileName)
{
    // Objeto fstream para acceder a la informacion en el archivo
    ifstream archivo;
    string line;
    archivo.open(fileName);
    // Recorre todo el archivo linea por linea para ser almacenado
    while(getline(archivo,line)){
        // Se ejecuta un push a la lista doblemente enlazada por cada elemento
        bitacora.push(new Entrada(line));
    }
    // Cerrar archivo
    archivo.close();
}

// Metodo de ordenamiento quick sort
// Solo llama a quick sort, el algoritmo
// esta implementado en la clase DoubleLL
// No recibe ni regresa algun valor
void Registro::quickSort()
{
    bitacora.quickSort();
}

// Metodo para guardar las entradas ordenadas en un archivo nuevo
// Recibe un un string con el nombre del archivo en donde se va a guardar
// No regresa algun valor
void Registro::guardar(string fileName)
{
    ofstream archivo;
    archivo.open(fileName);
    // Metodo print para imprimir la informacion en el stream del archivo
    print(archivo);
    archivo.close();
}

// Metodo para realizar la busqueda e impresion a pantalla de las entradas dentro
// de un rango de ip
// Recibe dos strings con las ip de inicio y fin en el formato "###.###.###.###"
// ipIni e ipFin no contienen el puerto. Ejemplo de entrada: 423.2.230.77
// No regresa algun valor
void Registro::busqueda(string ipIni, string ipFin)
{
    vector<string> ini = {"","","",""};
    vector<string> fin = {"","","",""};
    unsigned long long ip1, ip2;
    //Separacion de las ip por segmento
    separar(ini,ipIni);
    separar(fin,ipFin);
    // Ip ajustada a formato deseado de busqueda
    ip1 = stoi(ini[3]);
    ip1 += stoi(ini[2]) * pow(10,3);
    ip1 += stoi(ini[1]) * pow(10,6);
    ip1 += stoi(ini[0]) * pow(10,9);
    ip2 = stoi(fin[3]);
    ip2 += stoi(fin[2]) * pow(10,3);
    ip2 += stoi(fin[1]) * pow(10,6);
    ip2 += stoi(fin[0]) * pow(10,9);
    //Se realizan las busquedas de los indices para cada rango
    int indiceIni = bitacora.busqueda(ip1,false);
    int indiceFin = bitacora.busqueda(ip2,true);
    // Si ambos indices se encuentran en un rango valido de los accesos,
    // se imprime a pantalla las entradas deseadas
    if (indiceIni != -1 && indiceFin != -1){
        print(cout,indiceIni,indiceFin);
    }
}

// Metodo para desplegar valores de la bitacora ordenada
// Recibe un un objeto tipo ostream como referencia
// No regresa algun valor
void Registro::print(ostream& stream)
{
    // Escribe todos los datos de la bitacora (DoubleLL) a un archivo nuevo
    bitacora.print(stream, 0, bitacora.length() - 1);
}

// Metodo para desplegar valores de la bitacora ordenada
// Recibe un objeto tipo ostream como referencia y dos indices enteros
// No regresa algun valor
void Registro::print(ostream& stream, int ini, int fin)
{
    // Solo despliega a consola, de forma ascendente, la porcion deseada de entradas en la bitacora
    // Entrada valida: de 40.83.671.11 a 70.16.722.45
    this->bitacora.print(stream,ini,fin);
}

// Metodo para separar la informacion dentro de la ip (formato: ###.###.###.###.####)
// Recibe el vector por referencia en donde se guardan los datos separados
// y un string con la ip a separar
// No regresa algun valor
void Registro::separar(vector<string> &datos, string linea)
{
    // Contador del elemento que corresponde al dato
    int espacios = 0;
    // Se recorre el string caracter por caracter
    for(auto j : linea){
        // Cuando se encuentra un punto (.) se cambia de elemento
        if(j == '.'){
            espacios++;
        }
        else{
            // De no serlo, se concatena el caracter
            datos[espacios] += j;
        }
    }
}
