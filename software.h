#include <iostream>
#include "material.h"
#ifndef software_h
#define software_h
using namespace std;

class software:public material
{
private:
    string sistemaOper;

public:
    software();
    software(string, int, string);
    void setOS(string);
    string getOS();
    void muestraDatos();
    int cantidadDiasPrestamo();
};

software::software()
{
    sistemaOper = "N/A";
    idMaterial = -1;
    titulo = "N/A";
}

software::software(string op, int id, string tit)
{
    sistemaOper = op;
    idMaterial = id;
    titulo = tit;
}

void software::setOS(string os)
{
    sistemaOper = os;
}

string software::getOS()
{
    return sistemaOper;
}

void software::muestraDatos()
{
    cout << "ID de Material: " << idMaterial << endl;
    cout << "Tipo de Material: Software" << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Sistema Operativo: " << sistemaOper << endl;
}

int software::cantidadDiasPrestamo()
{
    return 1;
}




#endif