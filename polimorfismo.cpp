#include <bits/stdc++.h>
using namespace std;

// FUNCION GENERICA -> se define en tiempo de compilacion
template<class T>
void PRINT_VEC(vector<T> &v) 
{ 
    // Los tipos polimórficos son tipos cuyas operaciones son aplicables a valores de más de un tipo.
    cout << "[ "; 
    for (auto el : v) 
        cout << el << " "; 
    cout << "]\n"; 
}
/** GENERALIZACION
 * Todo lo que esta escrito dentro de una funcion generica, tiene que tener operaciones admisibles por los tipos de datos que pasas.
*/

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

bool comp(const Alumno& a1, const Alumno& a2)
{
    return a1.edad < a2.edad;
}

template<typename T>
void print(T var, string end="\n")
{
    cout << var << end;
}

int main()
{
    // POLIMORFISMO DE TIPOS
    vector<int> v_int {1, 2, 3, -1, 7, 6};
    vector<double> v_double {1, 2.5, 0};
    vector<Alumno> v_alumnos { Alumno("J", 20), Alumno("G", 18), Alumno("A", 19)};
    PRINT_VEC(v_int);
    PRINT_VEC(v_double);
    PRINT_VEC(v_alumnos);

    // Las funciones polimórficas son funciones que tienen argumentos polimórficos
    sort(begin(v_int), end(v_int));
    PRINT_VEC(v_int);
    sort(rbegin(v_int), rend(v_int));
    PRINT_VEC(v_int);
    sort(begin(v_alumnos), end(v_alumnos), comp);
    PRINT_VEC(v_alumnos);
    sort(begin(v_alumnos), end(v_alumnos), [](Alumno& a1, Alumno& a2){
        return a1.edad > a2.edad;
    });
    PRINT_VEC(v_alumnos);
    sort(begin(v_alumnos), end(v_alumnos), [](Alumno& a1, Alumno& a2){
        return a1.nombre < a2.nombre;
    });
    PRINT_VEC(v_alumnos);
    print(Alumno("GHI", 16), "\t");
    print(5);
    // sobrecarga el >, < para tu clase el sort admite tu clase y la ordena
    return 0;
}

/**
 * POLIMORFISMO
 *  mismo nombre, diferente funcionalidad/comportamiento
 * OBJETO POLIMORFICO
 *  entidad (variable, funcion) que puede comportarse de acuerdo a la situacion
 *  
 * 
 * https://www.geeksforgeeks.org/functors-in-cpp/
*/