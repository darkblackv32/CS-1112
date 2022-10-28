#include <bits/stdc++.h>
using namespace std;

struct Alumno;
class Utecino;
class Pollo;
class Vaca;

struct Alumno { 
    string nombre;
    int edad;

    Alumno() = default;
    Alumno(string n, int e): nombre{n}, edad{e}{}
};

ostream& operator<<(ostream& os, Alumno a)
{
    os << "(" << a.nombre << " " << a.edad << ")";
    return os;
}

// AMISTAD ENTRE FUNCION Y CLASE
class Utecino {
private:
    string nombre;
    int edad;

    friend ostream& operator<<(ostream& os, const Utecino a);
public:
    Utecino() = default;
    Utecino(string n, int e): nombre{n}, edad{e}{}
};

ostream& operator<<(ostream& os, const Utecino a)
{
    os << "(" << a.nombre << " " << a.edad << ")";
    return os;
}

// AMISTAD ENTRE CLASE Y CLASE
class Pollo {
private:
    int nro_plumas;
    // vector<Vaca> amigos;

    friend Vaca;
public:
    Pollo(int n): nro_plumas(n){}

    // void print_amigos()
    // {
    //     for (Vaca p: this->amigos)
    //         cout << p.toneladas << " ";
    // }
};

class Vaca {
private:
    int toneladas;
    vector<Pollo> amigos;
public:
    Vaca(int n): toneladas(n){}

    void print_amigos()
    {
        for (Pollo p: this->amigos)
            cout << p.nro_plumas << " ";
    }
};

// class ProfesorUniversitario{
// protected:
// public:
// };

// class Profesor{

// };

// class Alumno{

// };

// class ProfesorAyudante : public Profesor, public Alumno{

// };

int main()
{
    return 0;
}