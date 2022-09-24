#include <bits/stdc++.h>
using namespace std;

void ejemplo_1()
{
    cout << "\n";
    int N = 5;
    
    int* arr = new int[N];      // este puntero apunta a N casillas en heap
    cout << "puntero en stack: " << arr << "\n";
    cout << "direccion del primer elemento en el heap: " << " " << &arr[0] << "\n";
    for (size_t i = 1; i < N; i++)
    {
        cout << &arr[i] << " ";
    }   cout << endl;
    // yo apuntare a la direccion de memoria de un puntero
    int** ptr_ptr = &arr;
}

int main()
{
    cout << "\n";
    int filas = 5;
    int columnas = 3;
    auto ptr_ptr = new int*[filas]{nullptr};
    // auto var = 5;       // int
    // auto vard = 5.14;   // float/double

    for (size_t i = 0; i < filas; i++)
        cout << ptr_ptr[i] << " ";
    cout << endl;
    
    cout << "VISTA DE DIRECCIONES DE MEMORIA\n\n";
    for (size_t i = 0; i < filas; i++)
    {
        ptr_ptr[i] = new int[columnas];
        
        cout << "puntero en pos " << i << " -> " << ptr_ptr[i] << "\n\t";
        cout << "direccion de elementos en el nuevo array\n\t";
        for (size_t j = 0; j < columnas; j++)
            cout << &ptr_ptr[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    cout << "CONSTRUCCION DE MATRIZ EN HEAP\n";
    cout << "\n" << ptr_ptr << "\n";
    cout << "\tdireccion \tvalor\n";
    for (size_t i = 0; i < filas; i++)
    {
        cout << "\t" << &ptr_ptr[i] << " " << ptr_ptr[i] << "\n\t\t\t";
        for (size_t j = 0; j < columnas; j++)
            cout << &ptr_ptr[i][j] << " (" << ptr_ptr[i][j] << ") ";
        cout << endl;
    }
    
    cout << "CONSTRUCCION DE MATRIZ EN STACK\n\n";
    int mat[filas][columnas];       // std::memset
    for (size_t i = 0; i < filas; i++)
    {
        cout << "\t";
        for (size_t j = 0; j < columnas; j++)
        {
            mat[i][j] = 0;
            cout << mat[i][j] << " ";
        }   cout << endl;   
    }   cout << endl;
    
    
    cout << endl;
    
    
    return 0;
}

/*
STACK
    direccion   variable    valor
    ....8d      arr         ...71
    ....9f      ptr_ptr     ....8d

HEAP
    ....71  ....72  ...73  ....7A


ptr_ptr[a[_, _, _, _, ..._, ]]

ptr_ptr -> a -> [*, _, _, _, ..., _]

[[*, _, _, _, ..., _]]


int*
    a1 -> [*, _, _, _, ..._, ]
    a2 -> [*, _, _, _, ..._, ]
    a3 -> [*, _, _, _, ..._, ]

int** ptr_ptr = new int*[]
ptr_ptr -> [&a1, &a2, &a3]

*/
