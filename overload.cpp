#include <bits/stdc++.h>
using namespace std;

void func_overload();
auto suma(double a, int b){ return a + b; }
auto suma(int a, int b){ return a + b; }
auto suma(double a, int b, float c){ return a+b+c; }

class Persona{
private:
    string nombre;
    int edad;

    friend ostream& operator<<(ostream& os, Persona p);
    friend bool operator < (const Persona& p1, const Persona& p2);
public:
    Persona() = default;
    Persona(string n, int e): nombre{n}, edad{e}{}
    Persona operator = (Persona other)
    {
        this->nombre = other.nombre;
        this->edad = other.edad;
        return *this;
    }
    
    // auto get_nombre(){ return nombre; }
    // auto get_edad(){ return edad; }
    ~Persona() = default;
};

ostream& operator << (ostream& os, Persona p)
{
    os << "{" <<  p.nombre << " " << p.edad << "}";
    return os;
}

Persona operator + (const Persona& p1, const Persona& p2)
{
    // * CHALLENGE: 
    // Sobrecargar el operador + para que cuando "sumes" 2 instancias de Persona
    // Devuelva una nueva instancia de Persona la cual tenga los nombres en orden "p2.nombre p1.nombre" y a su vez el promedio de las edades aproximado al techo
}

bool operator < (const Persona& p1, const Persona& p2)
{
    if (p1.edad == p2.edad)
        return p1.nombre < p2.nombre;
    return p1.edad < p2.edad;
}

int main()
{
    Persona p1("Angelo", 18);
    // ASSIGNMENT OPERATOR =
    auto p2 = p1;
    
    //      verificando que se creen distintos objetos producto del copy-assignment constructor
    cout << &p1 << " " << &p2 << endl;

    // OUTPUT OPERATOR <<
    // https://en.cppreference.com/w/cpp/io/basic_ostream
    cout << p1 << endl;
    cerr << p2 << endl;
    clog << p1 << endl;

    // cout << p1.get_nombre() << " " << p1.get_edad() << endl;
    // cout << p2.get_nombre() << " " << p2.get_edad() << endl;

    // * CHALLENGE
    // Persona p3;
    // cin >> p3;
    /**
     * Ingrese nombre: Jeremy
     * Ingrese edad: 20
    */
   // cout << p3 << endl;      // {Jeremy , 20}

   // RELATIONAL OPERATOR
    vector<Persona> people = {
        Persona("Gabriel", 18),
        Persona("Angelo", 18),
        Persona("Matias", 20),
        Persona("Andrea", 16)
    };
    sort(people.begin(), people.end());
    for (Persona& p : people)
        cout << p << " ";
    cout << endl;

    Persona andrea("Andrea", 16), gabriel("Gabriel", 18), angelo("Angelo", 18);
    cout << boolalpha << (andrea < gabriel) << endl;
    cout << boolalpha << (gabriel < angelo) << endl;
    
    // * CHALLENGE
    // 18
    // angelo++;       // 19
    // --angelo;       // 18
    // angelo--;       // 17
    // ++angelo;       // 18

    // for (size_t i = 1; i <= 10; i++)
    //     angelo++;
    // 28
}

void func_overload()
{
    cout << suma(1.5, 1) << "\n";
    cout << suma(2, 2) << "\n";
    cout << suma(2.5, 2.5) << "\n";
    cout << suma(1, 2.5) << "\n";
    cout << suma(1., 2., 3.5) << "\n";
}
