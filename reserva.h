#include <iostream>
#include "fecha.h"
#ifndef reserva_h
#define reserva_h
using namespace std;

class reserva
{
private:
    int idMaterial;
    int idCliente;
    fecha fechaReserva;

public:
    reserva();
    reserva(int, int, fecha);
    void setidMaterial(int);
    void setIdCliente(int);
    void setFechaReserva(fecha);
    int getidMaterial();
    int getIdCliente();
    void toString();
    fecha getFechaReserva();
    fecha calculaFechaFinReserva(int);
};

reserva::reserva()
{
    fecha f1;
    idMaterial = -1;
    idCliente = -1;
    fechaReserva = f1;
}

reserva::reserva(int m, int c, fecha f)
{
    idMaterial = m;
    idCliente = c;
    fechaReserva = f;
}

void reserva::setidMaterial(int m)
{
    idMaterial = m;
}

void reserva::setIdCliente(int c)
{
    idCliente = c;
}

void reserva::setFechaReserva(fecha f)
{
    fechaReserva = f;
}

int reserva::getidMaterial()
{
    return idMaterial;
}

int reserva::getIdCliente()
{
    return idCliente;
}

void reserva::toString()
{
    cout << "ID de Material: " << idMaterial << endl;
    cout << "ID de Cliente: " << idCliente << endl;
    cout << "Fecha de Reservacion: " << fechaReserva << endl;
}

fecha reserva::getFechaReserva()
{
    return fechaReserva;
}

fecha reserva::calculaFechaFinReserva(int duracion)
{
    fecha fr = fechaReserva;

    fr = fr + duracion;

    return fr;
}


#endif
