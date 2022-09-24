#include <bits/stdc++.h>        // todas las librerias necesarias (mala practica en software)
using namespace std;

// declaring functions
void func_1(int);
int sol_func_1(int);
void func_2(int&);
void func_3(const int&);
void func_4(int*);

struct persona 
{
    int edad;       // 4
    double peso;    // 8
    int estatura;   // 4

    persona() = default;
};

void func_persona_ref(persona& p)
{
    cout << "por referencia " << sizeof(p) << endl;
}

void func_persona_ptr(persona* p)
{
    cout << "por puntero "<< sizeof(p) << endl;
}

// resolubles: 
//      exhaustivos: solucion exacta requiere mucho computo
//                   solucion aproximada
// no resolubles: ...   

int main()
{
    int a = 5;
    cout << "\tmain() " << &a << " " << a << endl;      // 5
    func_1(a);
    a += 2;
    cout << "\tmain() " << &a << " " << a << endl;      // 7

    a = sol_func_1(a);
    cout << "\tmain() " << &a << " " << a << endl;      // 12
    // int& valor = a;
    // valor += 5;
    func_2(a);
    cout << "\tmain() " << &a << " " << a << endl;      // 17
    
    func_3(a);
    
    // int* valor = &a;
    func_4(&a);
    cout << "\tmain() " << &a << " " << a << endl;      // 22
    int* ptr = &a;
    // int* valor = ptr;
    func_4(ptr);
    cout << "\tmain() " << &a << " " << a << endl;      // 27

    persona p1;
    // cout << sizeof(p1) << endl;
    func_persona_ref(p1);
    func_persona_ptr(&p1);
    return 0;
}

// describe functions
void func_1(int valor)
{   // copiando el valor de la variable
    cout << "\tfunc_1() "<< &valor << endl;
    valor += 5;
}

int sol_func_1(int valor)
{
    cout << "\tsol_func_1() "<< &valor << endl;
    valor += 5;
    return valor;
}

void func_2(int& valor)
{   // parametro por referencia
    cout << "\tfunc_2() "<< &valor << endl;
    valor += 5;
}

void func_3(const int& valor)
{   // parametro por referencia constante (solo lectura)
    cout << "\tfunc_3() "<< &valor << endl;
    // valor+=5;
}

void func_4(int* valor)
{   // parametro de tipo puntero (direccion de memoria)
    
    // tamanio de la variable que pasas clase que tiene 10 atributos de tipo int (tamanio estimado 40 bytes)
    // si yo la paso por puntero, su tamanio en bytes se mantiene como el tamanio de un puntero (8 bytes)
    // tamanio pasado es el mismo que el tamanio de la variable

    // ....8d   a     5
    // ....9f  valor  ....8d
    // *valor = a = 5
    *valor += 5;
}