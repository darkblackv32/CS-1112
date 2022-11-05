#include <bits/stdc++.h>
using namespace std;

struct Persona {};

// int operator+(Persona p1, Persona p2)
// {
//     return -1;
// }

// GENERALIZAR
template<typename T, typename V>        // template<params...>
auto suma(T a, V b){ return a + b;}

// ESPECIALIZAR
int suma(Persona a, Persona b){ return 100; }

// ALIAS TEMPLATE
template<typename T>
using it = typename vector<T>::iterator;

template<class T> 
using ptr = T*;

template<class A, class B>
using pr = pair<A, B>;

// typedef int Entero;
// using Entero = int;
// #define Entero int

void alias_template()
{
    pr<char, int> p1;
    p1 = make_pair('c', 5);
    cout << p1.first << " " << p1.second << endl;

    // the name 'ptr<T>' is now an alias for pointer to T
    ptr<int> x;     // == int* x;
    x = new int(5);
    cout << *x << endl;

    vector<int> vec { 1, 2, 3, 4, 5 };
    it<int> beg = vec.begin();
}

void call_template()
{
    auto s1 = suma(1.5, 1);    // suma<double, int>(double, int)
    cout << typeid(s1).name() << " -> " << s1 << endl;
    auto s2 = suma(2, 2);      // suma(int, int)
    cout << typeid(s2).name() << " -> " << s2 << endl;
    auto s3 = suma(2.5, 2.5);  // suma(double, double)
    cout << typeid(s3).name() << " -> " << s3 << endl;
    auto s4 = suma(1LL, 2.5);  // suma(long long int, double)
    cout << typeid(s4).name() << " -> " << s4 << endl;
    auto s5 = suma(Persona(), Persona());
    cout << typeid(s5).name() << " -> " << s5 << endl;
}

// * CHALLENGE
/*
Implementar una funcion template que realice un bubble sort.
Argumentos de la funcion:
    1 parametro template tipo
    2 argumento de funcion: iteradores de vector
Resultado:
*/
template<typename T>
void bubble_sort(it<T> beg, it<T> end)
{
    while (beg != end)
        cout << *beg++ << " ";
}

int main()
{
    cout << ('a' < 'b') << endl;

    vector<double> vecd {51, 25, 3, 50};
    bubble_sort<double>(vecd.begin(), vecd.end());

    // vector<Persona> people;
    // bubble_sort<Persona>(people.begin(), people.end());
}
