#include <bits/stdc++.h>
using namespace std;

class Persona{
private:
    string nombre;
public:
    Persona(string _n): nombre{_n}{}

    void show(){ cout << "Nombre: " << nombre << endl;}
};

// HERENCIA (general -> especifico)
class Animal {  
// Base class
protected:
    string nombre_cientifico;
    int edad;
    set<string> alimentos;      // a a b c -> a b c
public:    
    Animal() = default;
    Animal(string nn, int ee): nombre_cientifico{nn}, edad{ee}{}
    // Animal(int ee, string nn, set<string> alimentos){}
    auto get_edad() { return this->edad; }
    void add_alimento(string _nuevo_alimento)
    {
        this->alimentos.insert(_nuevo_alimento);
    }
    virtual void print() = 0;       // declaracion POLIMORFISMO
};

class Perro : public Animal {
// Derived class
private:
    Persona* duenno;        // ASOCIACION
    string nombre;
public:
    Perro(string _n, int _e, Persona* _d, string _nom) : Animal(_n, _e), duenno{_d}
    {
        nombre = _nom;
    }

    void hb(){ this->edad++; }

    void print()
    {   // defines
        cout << "NC: " << this->nombre_cientifico << " | ";
        duenno->show();
    }
};

class Ave : public Animal {
private:    
    int tamano_alas;
    string habitat;
public:
    Ave(string h, string nombre_cient, int _e): habitat{h}, Animal(nombre_cient, _e){}

    void print() override
    {   // defines
        cout << "H: " << this->habitat << " | " << this->nombre_cientifico << " | ";
        cout << "[";
        for (auto al : this->alimentos)
            cout << al << ", ";
        cout << "]\n";
    }
};

// void print(Perro* p){}
// void print(Ave* a){}

int main()
{
    Persona angelo("Angelo");
    Perro* bobby = new Perro("Canis lupus familiaris", 2, &angelo, "bobby");
    
    cout << bobby->get_edad() << endl;
    bobby->hb();
    cout << bobby->get_edad() << endl;
    cout << "\tDesde cada clase\n";
    (*bobby).print();

    Ave* piolin = new Ave("casa con Silvestre", "Aves", 1);
    piolin->add_alimento("semillas de girasol");
    piolin->add_alimento("maicito");
    piolin->add_alimento("agua");
    piolin->add_alimento("semillas de girasol");
    
    piolin->print();

    cout << "\tDesde un vector de objetos\n";
    vector<Animal*> fav = {bobby, piolin};
    for (Animal* f : fav)
        f->print();
    return 0;
}
/*
Perro* p;       // nombre_cientifico duenno
Ave* a;         // habitat nombre_cientifico [alimentos]
*/
