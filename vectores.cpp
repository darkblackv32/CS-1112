#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iterator>
#include <algorithm>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int min_value = -1e3, max_value = 1e3;

// UTILITIES
int random (int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

struct s1 {

};

class c1 {

};

void intro()
{
    // VECTORES vs ARRAYS
    auto sz = 5;
    int* arr = new int[sz];
    
    for (size_t i = 0; i < 5; i++)
    {   // 0 1 2 3 4 5
        if (i >= sz)
        {
            // redimensionar    
            int* aux_arr = new int[sz+1];       // creas un nuevo array
            for (size_t i = 0; i < sz; i++)     // copias los elementos del antiguo al nuevo
                aux_arr[i] = arr[i];
            // limpiamos memoria            
            delete[] arr;
            arr = nullptr;
            // reasignamos las variables
            arr = aux_arr;
            sz++;
        }
        arr[i] = i;
    }

    for (size_t i = 0; i < sz; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    // VECTOR: contenedor templatizado
    vector<int> v1;
    vector<double> v2;
    vector<s1> v3;
    vector<c1> v4;

    auto current_capacity = v1.capacity();
    cout << "first capacity: " << current_capacity << endl;
    for (int i = 1; i <= 1000; i++)
    {
        if (current_capacity != v1.capacity())
        {
            current_capacity = v1.capacity();
            cout << v1.size() << " " << current_capacity << endl;
        }
        v1.push_back(i);
    }

    cout << "current capacity: " << current_capacity << endl;
    for (int i = 1; i <= 1000; i++)
    {
        if (current_capacity != v1.capacity())
        {
            current_capacity = v1.capacity();
            cout << v1.size() << " " << current_capacity << endl;
        }
        v1.pop_back();
    }
    cout << "last capacity: " << current_capacity << endl;
}

template<typename T>
void print_vector(vector<T> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

void constructors_iterators()
{
    // CONSTRUCTORES: manera de declarar cierto tipo

    vector<int> vec {10, 20, 30, 40, 50};
    print_vector(vec);
    
    vector<int>::iterator beg = vec.begin();
    auto en = vec.end();

    cout << *beg << endl;           // 10
    cout << *(beg+1) << endl;       // 2

    cout << "Imprimiendo mediante iteradores\n";
    // 1ra FORMA
    int i = 0;
    while (beg + i != en)
    {
        cout << *(beg + i) << " ";
        i++;
    }   cout << endl;
    
    // 2da FORMA
    for (size_t i = 0; i < vec.size(); i++)
        cout << *(vec.begin() + i) << " ";
    cout << endl;

    // 3ra FORMA
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << endl;

    // 4ta FORMA
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<bool> bools(5);
    cout << "vector de booleanos -> ";
    print_vector(bools);

    vec = vector<int>(5, 1);        // size , default_value
    cout << "vector de enteros   -> ";
    print_vector(vec);

    // RETO: construir una matriz N*M con vectores
    cout << "MATRIZ\n";
    int N = 5, M = 3;
    auto matriz = vector<vector<int>>(N, vector<int>(M, random(min_value, max_value)));
    
    // indexing
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cout << matriz[i][j] << " ";
        }   cout << endl;
    }
}

void range_iterators()
{
    vector<int> vec {10, 20, 30, 40, 50};
    for (int element : vec)
        cout << element << " ";
    cout << endl;

    // SIN REFERENCIA
    for (int element : vec)
    {
        element++;
        cout << element << " ";
    }
    cout << endl;

    for (auto element : vec)
        cout << element << " ";
    cout << endl;

    // CON REFERENCIA
    for (int& element : vec)
    {
        element+=2;
        cout << element << " ";
    }
    cout << endl;

    for (auto& element : vec)
        cout << ++element << " ";
    cout << endl;

    cout << "MATRIZ\n";
    auto matrix = vector<vector<int>>(5, vector<int>(4, 0));
    // vector<T>(size, default)
    // vector<T>(5, default)
    // vector<vector<int>>(5, default)
    // vector<vector<int>>(5, vector<int>(4, 0))
    for (vector<int> row : matrix)
    {
        for (int column : row)
            cout << column << " ";
        cout << endl;
    }   cout << endl;
}

int main()
{
    range_iterators();
    return 0;
}

/*
    PROBLEMAS DE ARRAYS
    - redimensionamiento
        - estatico: no se puede redimensionar
        - dinamico: pero lo tienes que hacer manualmente

    STL: Standard Template Library
    - algoritmos
    - contenedores
    - adaptadores

https://www.w3schools.com/cpp/cpp_pointers_dereference.asp
*/