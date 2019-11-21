#include <iostream>
#include <fstream>
#include "fecha.h"
#include "reserva.h"
#include "material.h"
#include "libro.h"
#include "software.h"
#include "disco.h"
using namespace std;

int main()
{
    material *mat[20];
    reserva *res[50];
    ifstream inMaterial, inReserva;
    char tipo, menu;
    int id, numPag, duracion, iX, iY;
    string titulo, autor, os;
    int dia, mes, ano, idMat, idClient;
    fecha f1, fReservacion;
    bool check;
    int idC, idM;

    for(iX = 0; iX < 50; iX++)
    {
        fecha f;
        res[iX] = new reserva(-1, -1, f);
    }

    inMaterial.open("Material.txt");
    iX = 0;
    while(!inMaterial.eof())
    {
        inMaterial >> id >> titulo >> tipo;
        switch(tipo)
        {
            case 'B':
                inMaterial >> numPag >> autor;
                mat[iX] = new libro(numPag, autor, id, titulo);
                break;
            case 'C':
                inMaterial >> duracion;
                mat[iX] = new disco(duracion, id, titulo);
                break;
            case 'S':
                inMaterial >> os;
                mat[iX] = new software(os, id, titulo);
                break;
        }
        iX++;
    }

    inMaterial.close();

    inReserva.open("Reserva.txt");
    iX = 0;
    while(!inReserva.eof())
    {
        inReserva >> dia >> mes >> ano >> idMat >> idClient;
        fecha f1(dia, mes, ano);
        res[iX] = new reserva(idMat, idClient, f1);
        iX++;
    }

    inReserva.close();

    do
    {
        cout << "***MENU***" << endl;
        cout << "a) Consultar lista de Materiales" << endl;
        cout << "b) consultar lista de Reservaciones" << endl;
        cout << "c) Consultar Reservaciones de un Material Dado" << endl;
        cout << "d) Consultar reservaciones de una Fecha Dada" << endl;
        cout << "e) Hacer una Reservacion" << endl;
        cout << "f) Terminar" << endl << endl;

        cin >> menu;

        switch(menu)
        {
            case 'a':
            case 'A':
                for(iX = 0; iX < 20; iX++)
                {
                    mat[iX] -> muestraDatos();
                    cout << endl;
                }
                break;
            case 'b':
            case 'B':
                for(iX = 0; (iX < 50) && ((res[iX] -> getidMaterial()) != -1); iX++)
                {
                    res[iX] -> toString();
                    for(iY = 0; res[iX] -> getidMaterial() != mat[iY] -> getId(); iY++);
                    cout << "Titulo: " << mat[iY] -> getTitulo() << endl;
                    cout << endl;
                }

                break;
            case 'c':
            case 'C':
                for(iX = 0; iX < 50 && (res[iX] -> getidMaterial()) != -1; iX++)
                {
                    for(iY = 0; iY < 20; iY-=-1)
                    {
                        if(res[iX] -> getidMaterial() == mat[iY] -> getId())
                        {
                            cout << "Titulo: " << mat[iY] -> getTitulo() << endl;
                            cout << "Inicio de Reserva: " << res[iX] -> getFechaReserva() << endl;
                            cout << "Fin de Reserva: " << res[iX] -> calculaFechaFinReserva(mat[iY] -> cantidadDiasPrestamo()) << endl << endl;
                        }
                    }
                }
                break;
            case 'd':
            case 'D':
                check = false;
                cout << "Ingresa la Fecha: " << endl;
                cin >> f1;
                for(iX = 0; iX < 50 && (res[iX] -> getidMaterial()) != -1; iX++)
                {
                        for(iY = 0; iY < 20; iY++)
                        {
                            if(f1 >= res[iX] -> getFechaReserva() && f1 <= res[iX] -> calculaFechaFinReserva(mat[iY] -> cantidadDiasPrestamo()))
                            {
                                if(res[iX] -> getidMaterial() == mat[iY] -> getId())
                                {
                                    cout << "Titulo: " << mat[iY] -> getTitulo() << endl;
                                    cout << "ID de Cliente: " << res[iX] -> getIdCliente() << endl << endl;
                                    check = true;
                                }
                            }
                        }
                }
                if (!check)
                {
                    cout << "No hay Material reservado en esta Fecha" << endl << endl;
                }
                break;
            case 'e':
            case 'E':
                cout << "Ingresa tu ID: ";
                cin >> idC;
                cout << "Ingresa el ID del Material que deseas Reservar: ";
                check = false;
                do {
                    cin >> idM;
                    for(iX = 0; iX < 20; iX++)
                    {
                        if(idM == mat[iX] -> getId())
                        {
                            check = true;
                        }
                    }
                    if(!check)
                    {
                        cout << "ID de MAterial invalido, ingresa otro: ";
                    }
                } while(!check);
                cout << "Ingresa la Fecha en que deseas Reservar: " << endl;
                do {
                    check = true;
                    cin >> fReservacion;
                    for(iX = 0; iX < 50 && (res[iX] -> getidMaterial()) != -1 && check; iX++)
                    {
                        for(iY = 0; iY < 20; iY++)
                        {
                            if(idM == res[iX] -> getidMaterial())
                            {
                                if(fReservacion >= (res[iX] -> getFechaReserva()) && fReservacion <= (res[iX] -> calculaFechaFinReserva(mat[iY] -> cantidadDiasPrestamo())))
                                {
                                    check = false;
                                }
                            }
                        }
                    }
                    if(!check)
                    {
                        cout << "Este Material ya esta Reservado en esa Fecha, elije una diferente: " << endl;
                    }
                    else
                    {
                        for(iX = 0; res[iX] -> getidMaterial() != -1; iX++);
                        res[iX] = new reserva(idM, idC, fReservacion);
                        cout << "Reservacion hecha exitosamente!" << endl;
                    }
                } while(!check);
                break;
            case 'f':
            case 'F':
                break;
        }

        cout << endl;

    } while(menu != 'f' && menu != 'F');


    return 0;
}