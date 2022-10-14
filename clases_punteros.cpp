#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class Alumno {
private:     
    string codigo, nombre;
    int ciclo = 1, ao_ingreso=-1, nro_ingresante=-1;
    vector<float> notas;
    vector<Alumno*> amigos;
public:
    // CONSTRUCTOR POR DEFECTO
    Alumno() = default;         
    // CONSTRUCTOR PARAMETROS
    Alumno(string n) : nombre{n} {};    // DECLARACION + DEFINICION
    Alumno(string n, int c);            // DECLARACION
    Alumno(string n, int c, string cod): nombre(n), ciclo(c), codigo(cod)
    {
        // substr(pos, tam)
        this->ao_ingreso = stoi(codigo.substr(0, 4));   // 0 1 2 3
        this->nro_ingresante = stoi(codigo.substr(4, codigo.size()-4));
    }
    Alumno(string, string, int, int, int);      // DECLARAR

    // CONSTRUCTOR POR COPIA
    Alumno(const Alumno& other): codigo{other.codigo}, nombre{other.nombre} 
    {   // ! ASEGURATE DE COPIAR TODOS LOS PARAMETROS
        this->ciclo = other.ciclo;
        (*this).notas = other.notas;
        amigos = other.amigos;
        ao_ingreso = other.ao_ingreso;
        nro_ingresante = other.nro_ingresante;
    }
    
    Alumno operator = (const Alumno& other)         
    {   // OPERATOR OVERLOADING
        codigo = other.codigo;
        nombre = other.nombre;
        ciclo = other.ciclo;
        notas = other.notas;
        amigos = other.amigos;

        return *this;
    }   
    /*
    a1 = Alumno()
    a2 = a1
    */
    
    Alumno operator = (string n)
    {
        nombre = n;
        return *this;
    }

    void operator++() {
        ciclo++;      // self pointer a la instancia
    }

    auto get_ciclo() { return ciclo; }
    int get_ao(){ return this->ao_ingreso; }
    int get_nro() { return nro_ingresante; }
    void avanzar_ciclo() { ciclo++; }
    void reasignar_ciclo(int delta) { ciclo += delta;}
    string get_nombre() { return nombre; }
    
    void add_nota(float nueva_nota){ this->notas.push_back(nueva_nota); }
    void add_friend(Alumno* new_friend) { 
        this->amigos.push_back(new_friend); 
        new_friend->amigos.push_back(this);
    }

    void show_friends()
    {
        cout << "\t";
        for (Alumno* a : this->amigos)
            cout << "[" << a->get_nombre() << " " << a->get_ciclo() << " " << a->get_ao() << " " << a->get_nro() << "] "; 
            // cout << a << " ";
        cout << endl;
    }

    string evaluar_ciclo() 
    {
        cout << "Ciclo actual: " << this->ciclo << endl;
        
        float promedio = 0;
        for (size_t i = 0; i < notas.size(); i++)
            promedio += notas[i];
        promedio /= notas.size();

        if (promedio >= 10.5)   
            this->avanzar_ciclo();      
        
        string res = "Ciclo despues de calcular promedio = " + to_string(this->ciclo);
        return res;    
    }

    ~Alumno() {
        // for (size_t i = 0; i < amigos.size(); i++)
        //     delete amigos[i], amigos[i] = nullptr;
        // amigos.clear();
    }
};

// DEFINICION
Alumno::Alumno(string n, int c)
{
    nombre = n;
    ciclo = c;
}

Alumno::Alumno(string n, string cod, int ciclo, int ao, int nro): codigo{cod}, ao_ingreso(ao), nro_ingresante{nro}
{
    this->nombre = n;
    this->ciclo = ciclo;
}

void print(Alumno a)        // parametro = *jeremy | parametro(*jeremy)
{ 
    cout << "[" << a.get_nombre() << " " << a.get_ciclo() << " " << a.get_ao() << " " << a.get_nro() << "]\n"; 
}

void operator_over()
{
    auto jeremy = new Alumno("Jeremy", 5, "202013245");
    print(*jeremy);
    ++(*jeremy);
    print(*jeremy);

    auto angelo = Alumno("Angelo", 2);
    print(angelo);
    ++angelo;
    print(angelo);
    angelo.reasignar_ciclo(2);
    print(angelo);
    angelo.reasignar_ciclo(-1);
    print(angelo);

    int mat[2][2] = {{1, 2}, {3, 4}};
    // + - / * ++ -- =
}

void class_in_class()
{
    vector<Alumno> alumnos {
       Alumno("Juan"),
       Alumno("Adrian", 5),
       Alumno("Carlos", 6, "202023423"),
       Alumno("Daniel", "20212312", 4, 2021, 12312)
    };      // &

    for (const auto& a : alumnos)
        print(a);

    // Definir relaciones entre amigos y voy a consultar los amigos que yo tengo y voy a editarles variables a ellos
    alumnos[0].add_friend(&alumnos[1]);     // indexing, ptr/ref, class methods
    auto& adrian = alumnos[1];
    Alumno& daniel = alumnos[3];
    adrian.add_friend(&daniel);

    for (size_t i = 0; i < alumnos.size(); i++)
    {
        cout << "\t" << alumnos[i].get_nombre() << " dir: " << &alumnos[i] << endl;
    }
    
    for (Alumno a : alumnos)
        cout << "\t\t" << a.get_nombre(), a.show_friends();
}

int main()
{
    operator_over();
    class_in_class();
    return 0;
}