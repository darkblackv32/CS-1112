#include <bits/stdc++.h>
using namespace std;

const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct Date {
    int d, m, y;
    Date(int dd, int mm, int yy): d{dd}, m{mm}, y{yy}{}
};

int countLeapYears(Date d)
{
    int years = d.y;
    if (d.m <= 2)
        years--;
    
    return years / 4
           - years / 100
           + years / 400;
}

int getDifference(Date dt1, Date dt2)
{
    long int n1 = dt1.y * 365 + dt1.d;
 
    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];
 
    n1 += countLeapYears(dt1);
 
 
    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
 
    return (n2 - n1);
}

class Cita {
protected:
    string descripcion;
    int dia, mes, anno;
    int hora, minutos;
public:
    Cita(string, int, int, int, int, int);

    virtual void ocurre(int, int, int) = 0;
};

Cita::Cita(string des, int d, int m, int a, int h, int min)
{
    descripcion = des;
    dia = d;
    mes = m;
    anno = a;
    hora = h;
    minutos = min;
}

class UnaVez : public Cita{
public:
    UnaVez(string des, int d, int m, int a, int h, int min): Cita(des, d, m, a, h, min){}

    void ocurre(int dia, int mes, int aa)
    {
        string respuesta = "No ocurre\n";
        if (dia == this->dia && mes == this->mes && this->anno == aa)
            respuesta = "Si ocurre\n";
        cout << respuesta;
    }
};

class Diario: public Cita {
public:
    Diario(string des, int d, int m, int a, int h, int min): Cita(des, d, m, a, h, min){}
    
    void ocurre(int dia, int mes, int aa)
    {
        string respuesta = "No ocurre\n";
        if (aa > this->anno)
            respuesta = "Si ocurre\n";
        else if (aa == this->anno && mes > this->mes)
            respuesta = "Si ocurre\n";
        else if (aa == this->anno && mes == this->mes && dia >= this->dia)
            respuesta = "Si ocurre\n";    
        cout << respuesta;
    }
};

class Semanal: public Cita {
public:
    Semanal(string des, int d, int m, int a, int h, int min): Cita(des, d, m, a, h, min){}

    void ocurre(int dia, int mes, int aa) override {
        string respuesta = "No ocurre\n";
        int diff = getDifference(Date(dia, mes, aa), Date(this->dia, this->mes, this->anno));
        if (diff % 7 == 0)
            cout << "Si ocurre\n";
        cout << respuesta;
    }
};

class Mensual: public Cita {
public:
    Mensual(string des, int d, int m, int a, int h, int min): Cita(des, d, m, a, h, min){}
    void ocurre(int dia, int mes, int aa)
    {
        string respuesta = "No ocurre\n";
        if (aa > this->anno && dia == this->dia)
            respuesta = "Si ocurre\n";
        else if (dia == this->dia && mes >= this->mes)
            respuesta = "Si ocurre\n";
        cout << respuesta;
    }
};


int main () {
    vector <Cita*> citas ;
    Cita* uv1 = new UnaVez("CenaNavidad",24,12,2020,21,0) ;
    Cita* d1 = new Diario("Comprarpan",22,12,2020,8,0) ;
    citas.push_back(uv1);
    citas.push_back(d1);
    for (auto& cita : citas) {
        cita->ocurre(24,12,2020);
    }
}