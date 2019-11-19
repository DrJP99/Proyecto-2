#include <iostream>
#include "material.h"
#ifndef disco_h
#define disco_h
using namespace std;

class disco:public material
{
private:
    int duracion;

public:
    disco();
    disco(int, int, string);
    void setDuracion(int);
    int getDuracion();
    void muestraDatos();
    int cantidadDiasPrestamo();
};

disco::disco()
{
    duracion = -1;
    idMaterial = -1;
    titulo = "N/A";
}

disco::disco(int d, int id, string tit)
{
    duracion = d;
    idMaterial = id;
    titulo = tit;
}

void disco::setDuracion(int d)
{
    duracion = d;
}

int disco::getDuracion()
{
    return duracion;
}

void disco::muestraDatos()
{
    cout << "ID de Material: " << idMaterial << endl;
    cout << "Tipo de Material: Disco" << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Duracion: " << duracion << endl;
}

int disco::cantidadDiasPrestamo()
{
    return 3;
}


#endif