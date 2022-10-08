#include <bits/stdc++.h>
using namespace std;

class _2DMatrix {
private:
    int** mat = nullptr;
    int rows;
    int cols;
public:
    _2DMatrix() = default;
    ~_2DMatrix()
    {
        delete[] mat;
    }
};

void func();
void constructor();

class Alumno {
private:     // ATRIBUTOS (ingredientes)
    string codigo, nombre;
    int ciclo = 1;
    vector<float> notas;
    vector<Alumno*> amigos;         // si yo no le pongo puntero, tendre copias y eso no es necesario
public:
    // CONSTRUCTOR POR DEFECTO
    Alumno() = default;         // Alumno() {};
    // CONSTRUCTOR POR PARAMETROS
    Alumno(string n) : nombre{n} {};        // Alumno(this, string n)
    Alumno(string n, int c);    // declaras dentro de la clase
    // CONSTRUCTOR POR COPIA
    Alumno(const Alumno& other): codigo{other.codigo}, nombre{other.nombre} {
        // referencia de solo lectura
        this->ciclo = other.ciclo;
        (*this).notas = other.notas;
        amigos = other.amigos;
    }
    // CONSTRUCTOR ASIGNACION COPIA
    Alumno operator = (const Alumno& other)         // operator = (this, const Alumn...)
    {   // operator overloading -> sobrecarga de operadores
        codigo = other.codigo;
        nombre = other.nombre;
        ciclo = other.ciclo;
        notas = other.notas;
        amigos = other.amigos;

        return *this;
    }
    // CONSTRUCTOR CUSTOM
    Alumno operator = (string n)
    {
        nombre = n;
        return *this;
    }

    // GETTER: funcion que devuelve el VALOR de un atributo
    auto get_ciclo() { return ciclo; }
    void avanzar_ciclo() { ciclo++; }
    string get_nombre() { return nombre; }
    
    void add_nota(float nueva_nota){ this->notas.push_back(nueva_nota); }
    string evaluar_ciclo() 
    {
        cout << "Ciclo actual: " << this->ciclo << endl;
        
        float promedio = 0;
        for (size_t i = 0; i < notas.size(); i++)
            promedio += notas[i];
        promedio /= notas.size();

        if (promedio >= 10.5)   
            this->avanzar_ciclo();      // this es un puntero a objeto mismo, a la instancia misma
        
        string res = "Ciclo despues de calcular promedio = " + to_string(this->ciclo);
        return res;    
    }

    ~Alumno() {
        for (size_t i = 0; i < amigos.size(); i++)
            delete amigos[i], amigos[i] = nullptr;
        amigos.clear();
    }
};

// defines/describi afuera
Alumno::Alumno(string n, int c)
{
    nombre = n;
    ciclo = c;
}


void constructores_clases();
void clases_stack();
void clases_heap();
void print(Alumno a);

int main()
{
    clases_heap();   
    return 0;
}

void print(Alumno a)
{ 
    cout << "[" << a.get_nombre() << " " << a.get_ciclo() << "]\n"; 
}

void clases_heap()
{
    int a = 5;
    int *b = &a;
    cout << a << endl;      // valor de a: 5
    cout << &a << endl;     // direccion de a
    cout << b << endl;      // valor de b: la direccion de a
    cout << *b << endl;     // desreferencia(LO QUE CONTIENE LA DIR MEMORIA) de b: valor de a
    cout << &b << endl;     // direccion de b

    Alumno st("German");
    Alumno *a1 = nullptr;       // declarando puntero de clase
    a1 = &st;                               // apuntar a otra variable creada previamente
    
    cout << &st << " " << a1 << endl;       // direccion | valor
    print(st);
    print(*a1);     // desreferenciando puntero

    a1 = new Alumno("Geronimo", 9);           // reasignacion  |  definiendo|construyendo el puntero

    cout << &st << " " << a1 << endl;       // direccion | valor
    print(st);
    print(*a1);     // desreferenciando puntero

    int SZ; cout << "# alumnos", cin >> SZ;
    Alumno* salon = new Alumno[SZ];
    Alumno** matrizAlumnos = nullptr;
}

void clases_stack()
{
    Alumno jose("Jose", 5);
    int N; cout << "# notas: "; cin >> N;
    for (size_t i = 0, nota; i < N; i++)
        cout << "\tnueva nota: ", cin >> nota, jose.add_nota(nota);
    cout << jose.evaluar_ciclo();
}

void constructores_clases() 
{
    // int x;
    // cout << x << endl;

    Alumno a1, a2, *a3 = nullptr;
    cout << a1.get_ciclo() << endl;     // 1
    cout << a2.get_ciclo() << endl;
    Alumno a4("Angello", 2), a5("Miguel");
    print(a4);
    print(a5);

    vector<int> v1 {1, 2, 3}, v2 = v1;
    for (int el : v1) cout << el << " ";
    cout << endl;
    for (int el : v2) cout << el << " ";
    cout << endl;

    Alumno a6(a4);
    print(a6);
    a6.avanzar_ciclo();
    print(a6);      // [Angello 3]
    print(a4);      // [Angello 2]

    auto a7 = a6;
    cout << "\ta7 | a6 ejemplo\n";
    print(a7);
    a7.avanzar_ciclo();
    print(a7);
    print(a6);

    string ff = "Fernando";
    Alumno a8 = ff;
    print(a8);
}

void func()
{
    _2DMatrix m1;       // instancias/creas una particularizacion de la clase
}

void constructor() 
{
    // CONSTRUCTOR: funcion que inicializa objeto(instancia de clase)
    int a;
    int b = 1;
    int c(4);
    int d = b;

    {
        func();
    }

    cout << a << " ";
    cout << b << " ";
    cout << c << " ";
    cout << d << " ";
}
