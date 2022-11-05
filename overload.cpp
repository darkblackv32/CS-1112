#include <bits/stdc++.h>
using namespace std;

void func_overload();
void overload_1();
void overload_2();
auto suma(double a, int b){ return a + b; }
auto suma(int a, int b){ return a + b; }
auto suma(double a, int b, float c){ return a+b+c; }

class Persona{
private:
    string nombre;
    int edad;

    friend Persona operator + (const Persona& p1, const Persona& p2);
    friend ostream& operator <<(ostream& os, Persona p);
    friend istream& operator >>(istream& input, Persona& p);
    friend bool operator <(const Persona& p1, const Persona& p2);
public:
    Persona() = default;
    Persona(string n, int e): nombre{n}, edad{e}{}
    Persona operator = (Persona other)
    {
        this->nombre = other.nombre;
        this->edad = other.edad;
        return *this;
    }
    // * CHALLENGE:
    // ? Sobrecargar un operador unario sufijo (++ -- ! -)
    void operator ! ()
    {   // para todo metodo definido en una clase, 
        // se tiene como primer argumento implicito el especificador this
        reverse(this->nombre.begin(), this->nombre.end());      // Juan nauJ
        this->edad = -this->edad;
    }

    void operator >> (string second_name)
    {
        this->nombre += " " + second_name;
        // cout << this->nombre << endl;
    }

    void operator >> (int _edad)
    {
        this->edad = _edad;
    }

    ostream& operator >> (ostream& os)
    {
        os << this->nombre << " | " << this->edad << endl;
        return os;
    }
    
    operator pair<string, int>(/*this*/)
    {   // this implicito => 1 argumento en la funcion
        return { this->nombre, this->edad };
        // return make_pair(this->nombre, this->edad);
    }

    operator string(){ return this->nombre; }
    // PREFIX
    // void operator ++ ()
    // SUFFIX
    // void operator ++ (int)

    ~Persona() = default;
};

istream& operator >>(istream& input, Persona& p)
{ 
    cout<<"Ingrese nombre: "; input >> p.nombre;
    cout<<"Ingrese la edad: "; input >> p.edad;
    return input;
} 

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

    Persona *nueva_persona = new Persona();
    
    nueva_persona->edad = ceil(((p1.edad + p2.edad)/2));
    nueva_persona->nombre = p2.nombre + " " + p1.nombre;

    return *nueva_persona;
}

bool operator < (const Persona& p1, const Persona& p2)
{
    if (p1.edad == p2.edad)
        return p1.nombre < p2.nombre;
    return p1.edad < p2.edad;
}

int main()
{
    func_overload();
    overload_1();
    overload_2();   
}

// class Entero {
//     int value;
//     Entero(int _v): value(_v){}
// }

// Entero a(5);
// int b(a);

void overload_1()
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
    Persona p3;
    cin >> p3;
    /**
     * Ingrese nombre: Jeremy
     * Ingrese edad: 20
    */
   cout << p3 << endl;      // {Jeremy , 20}

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

    Persona andrea("Andrea", 16), gabriel("Gabriel", 20), angelo("Angelo", 18);
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

    auto nueva_p = angelo + gabriel;
    cout << nueva_p << endl;
}

void overload_2()
{
    Persona juan("Juan", 21);
    cout << juan << endl;

    bool flag = true;
    cout << boolalpha << !flag << endl;

    !juan;
    cout << juan << endl;       // nauJ -21

    juan >> "Sebastian";
    juan >> 18;

    // ++juan;             // la funcion sobrecargada se llama desde las instancia

    cout << juan << endl;       // el objeto Persona es un argumento de la funcion sobrecargada
    juan >> cout;

    auto par_persona = pair<string, int>(juan);
    cout << "\tPAR CREADO\n";
    cout << par_persona.first << endl;      // nauJ Sebastian
    cout << par_persona.second << endl;     // 18
    
    cout << "\toperator string()\n";
    cout << string(juan) << endl;
}

void func_overload()
{
    cout << suma(1.5, 1) << "\n";
    cout << suma(2, 2) << "\n";
    cout << suma(2.5, 2.5) << "\n";
    cout << suma(1, 2.5) << "\n";
    cout << suma(1., 2., 3.5) << "\n";
}
