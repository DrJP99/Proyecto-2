#include <iostream>
#include "material.h"
#ifndef libro_h
#define libro_h
using namespace std;

class libro:public material
{
private:
    int numPag;
    string autor;

public:
    libro();
    libro(int, string, int, string);
    void setNumPag(int);
    void setAutor(string);
    int getNumPag();
    string getAutor();
    void muestraDatos();
    int cantidadDiasPrestamo();
};

libro::libro()
{
    numPag = -1;
    autor = "N/A";
    idMaterial = -1;
    titulo = "N/A";
}

libro::libro(int pag, string a, int id, string tit)
{
    numPag = pag;
    autor = a;
    idMaterial = id;
    titulo = tit;
}

void libro::setNumPag(int num)
{
    numPag = num;
}

void libro::setAutor(string aut)
{
    autor = aut;
}

int libro::getNumPag()
{
    return numPag;
}

string libro::getAutor()
{
    return autor;
}

void libro::muestraDatos()
{
    cout << "ID de Material: " << idMaterial << endl;
    cout << "Tipo de Material: Libro" << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Numero de Paginas: " << numPag << endl;
}

int libro::cantidadDiasPrestamo()
{
    return 10;
}


#endif

