#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // PUNTERO: variable que apunta a otra variable, guardando la direccion de memoria de la variable a la que apunta.
    // VALOR: lo que guarda la variable
    //   &: ampersand operator -> devuelve la direccion de memoria de la variable
    //  &&: and en condicionales
    //  &: operaciones logicas
    int a = 5;
    int* b = &a;
    int** c = &b;
    int*** d = &c;

    cout << " a:   " << a << endl;      // VALOR: 5
    cout << "&a:   " << &a << endl;     // direccion de memoria de a (ampersand operator)
    cout << " b:   " << b << endl;      // VALOR: direccion de memoria de a
    cout << "&b:   " << &b << endl;     // direccion de memoria del puntero b
    cout << " c:   " << c << endl;      // c guarda la direccion de memoria de b

    cout << "*b:   " << *b << endl;     // VALOR DE a: 5
    cout << "&*b:  " << &*b << endl;    // direccion de memoria de a
    
    cout << "*c:   " << *c << endl;       // valor de b: direccion de a
    cout << "**c:  "<< **c << endl;      // valor de a: 5
    cout << "&**c: "<< &**c << endl;    // direccion de a
    

    cout << boolalpha;      // true false
    /*
        b = int*        puntero a entero
        &b = int**      puntero a puntero a entero
    */
    // cout << (b == &b) << endl;      // false
    cout << (*b == a) << endl;      // true
    cout << (&a == &*b) << endl;    // true
}

/*
direccion       |   variable    |   valor
------------------------------------------
0x7ffe7cca3ed4          a               5
0x7ffe7cca3ed8          b           0x7ffe7cca3ed4
0x7ffe7cca3edb          c           0x7ffe7cca3ed8
------------------------------------------

*direccion = valor de la direccion

b = 0x7ffe7cca3ed4
*b = *(0x7ffe7cca3ed4) = a = 5

c = 0x7ffe7cca3ed8
*c = *(0x7ffe7cca3ed8) b = 0x7ffe7cca3ed8       (la direccion de a)
*/