#include <iostream>
#include "reserva.h"
#ifndef material_h
#define material_h
using namespace std;

class material
{
protected:
    int idMaterial;
    string titulo;

public:
    material();
    material(int, string);
    virtual void muestraDatos() = 0;
    virtual int cantidadDiasPrestamo() = 0;
    virtual void setId(int);
    virtual void setTitulo(string);
    virtual int getId();
    virtual string getTitulo();
};

material::material()
{
    idMaterial = -1;
    titulo = "N/A";
}

material::material(int id, string t)
{
    idMaterial = id;
    titulo = t;
}

void material::setId(int id)
{
    idMaterial = id;
}

void material::setTitulo(string tit)
{
    titulo = tit;
}

int material::getId()
{
    return idMaterial;
}

string material::getTitulo()
{
    return titulo;
}

#endif