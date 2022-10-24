#include <bits/stdc++.h>
using namespace std;

class Obj2;

class Obj {
public:
    Obj2* obj1;
    vector<Obj2*> obj2s;
private:

};

class huesos;
class vasos;
class cartilagos;
class musculos;

class extremidad 
{
public:
    vector<huesos*> h;
    vector<cartilagos*> c;
    vector<vasos*> v;
    vector<musculos*> m;
};

class cerebro {
public:
    int IQ;
};

class cuentas_bancarias {
public:
    string organizacion;
};

class persona {
public:
    // vector/arreglo de punteros
    // estas estructuras representan la conexion con otras clases
    // se usa punteros(8 bytes en memoria cte)
// COMPOSICION - "es parte de" (significado)
    cerebro* c;
    extremidad ext[4];
// AGREGACION - "tiene un" | 1 a n
    vector<cuentas_bancarias*> cb;
// ASOCIACION - "usa un" | 1 a 1
    persona* mejor_amigo;
private:
};

/**
 * class Universidad;
 * class Alumnos;
 * 
 * composicion
 * 
 * class cerebro
 * class extremidad
 * class humano
 * 
 * programa normal RAM
 * ROM
 * 
 * Animal -> Canino -> Perro
*/