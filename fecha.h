#include <iostream>
#ifndef fecha_h
#define fecha_h
using namespace std;

class fecha
{
private:
    int dd, mm, aa;

public:
    fecha();
    fecha(int, int, int);
    void setDia(int);
    void setMes(int);
    void setAno(int);
    int getDia();
    int getMes();
    int getAno();
    int diasEnMes();
    void setFecha(int, int, int);
    string nombreMes();
    bool esBisesto();
    friend fecha operator+(fecha, int);
    friend bool operator>(fecha, fecha);
    friend bool operator<(fecha, fecha);
    friend bool operator==(fecha, fecha);
    friend bool operator>=(fecha, fecha);
    friend bool operator<=(fecha, fecha);
    friend istream& operator>>(istream&, fecha&);
    friend ostream& operator<<(ostream&, fecha);
};

fecha::fecha()
{
    dd = 1;
    mm = 1;
    aa = 1;
}

fecha::fecha(int d, int m, int a)
{
    dd = d;
    mm = m;
    aa = a;
}

void fecha::setDia(int d)
{
    dd = d;
}

void fecha::setMes(int m)
{
    mm = m;
}

void fecha::setAno(int a)
{
    aa = a;
}

int fecha::getDia()
{
    return dd;
}

int fecha::getMes()
{
    return mm;
}

int fecha::getAno()
{
    return aa;
}

void fecha::setFecha(int d, int m, int a)
{
    dd = d;
    mm = m;
    aa = a;
}

string fecha::nombreMes()
{
    string nombre;

    switch (mm)
    {
        case 1:
            nombre = "Enero";
            break;
        case 2:
            nombre = "Febrero";
            break;
        case 3:
            nombre = "Marzo";
            break;
        case 4:
            nombre = "Abril";
            break;
        case 5:
            nombre = "Mayo";
            break;
        case 6:
            nombre = "Junio";
            break;
        case 7:
            nombre = "Julio";
            break;
        case 8:
            nombre = "Agosto";
            break;
        case 9:
            nombre = "Septiembre";
            break;
        case 10:
            nombre = "Octubre";
            break;
        case 11:
            nombre = "Noviembre";
            break;
        case 12:
            nombre = "Diciembre";
            break;
    }

    return nombre;
}

bool fecha::esBisesto()
{
    if (aa % 4 == 0 && (aa % 100 != 0 || aa % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int fecha::diasEnMes()
{
    int dias;
    fecha f1(dd, mm, aa);

    switch (mm)
    {
        case 1:
            dias = 31;
            break;
        case 2:
            if(f1.esBisesto())
            {
                dias = 29;
            }
            else
            {
                dias = 28;
            }
            break;
        case 3:
            dias = 31;
            break;
        case 4:
            dias = 30;
            break;
        case 5:
            dias = 31;
            break;
        case 6:
            dias = 30;
            break;
        case 7:
            dias = 31;
            break;
        case 8:
            dias = 31;
            break;
        case 9:
            dias = 30;
            break;
        case 10:
            dias = 31;
            break;
        case 11:
            dias = 30;
            break;
        case 12:
            dias = 31;
            break;
    }

    return dias;
}

fecha operator+(fecha f1, int i)
{
    int dia = f1.dd;
    int mes = f1.mm;
    int ano = f1.aa;
    dia += i;
    if (dia > f1.diasEnMes())
    {
        mes++;
        dia -= f1.diasEnMes();
        if(mes > 12)
        {
            mes -= 12;
            ano++;
        }
    }

    fecha fr(dia, mes, ano);
    return fr;
}

bool operator>(fecha f1, fecha f2)
{
    if(f1.aa > f2.aa)
    {
        return true;
    }
    else if(f1.aa < f2.aa)
    {
        return false;
    }
    else
    {
        if(f1.mm > f2.mm)
        {
            return true;
        }
        else if(f1.mm < f2.mm)
        {
            return false;
        }
        else
        {
            if(f1.dd > f2.dd)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

}

bool operator<(fecha f1, fecha f2)
{
    if(f1.aa < f2.aa)
    {
        return true;
    }
    else if(f1.aa > f2.aa)
    {
        return false;
    }
    else
    {
        if(f1.mm < f2.mm)
        {
            return true;
        }
        else if(f1.mm > f2.mm)
        {
            return false;
        }
        else
        {
            if(f1.dd < f2.dd)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

}

bool operator==(fecha f1, fecha f2)
{
    if(f1.aa == f2.aa && f1.mm == f2.mm && f1.dd == f2.dd)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator>=(fecha f1, fecha f2)
{
    if(f1 > f2 || f1 == f2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator<=(fecha f1, fecha f2)
{
    if(f1 < f2 || f1 == f2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

istream& operator>>(istream& is, fecha& f1)
{
    cout << "Dia: ";
    is >> f1.dd;
    cout << "Mes: ";
    is >> f1.mm;
    cout << "Ano: ";
    is >> f1.aa;

    return is;
}

ostream& operator<<(ostream& os, fecha f1)
{
    os << f1.dd << " de " << f1.nombreMes() << ", " << f1.aa;

    return os;
}




#endif
