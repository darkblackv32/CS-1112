// HERENCIA (general -> especifico)
class Animal {  
// Base class
private:
    string nombre_cientifico;
    int edad;
    set<string> alimentos;
public:
    
};

class Perro {
// Derived class
private:
    string duenno;
    Animal* features;
public:
    void print()
    {
        cout << features->nombre_cientifico << " " << this->duenno << "\n";
    }
    void hb()
    {
        features->set_edad(features->get_edad()+1);
    }
};

class Ave {
private:    
int tamano_alas;
    string habitat;
    Animal* features;
public:
    void print() 
    {
        cout << this->habitat << " " << features->nombre_cientifico << " ";
        for (auto f : features->alimentos)
            cout << f << " ";
        cout << endl;
    }
};

auto suma(double s1, double s2) { return s1 + s2; }
auto suma(int s1, double s2){ return double(s1) + s2; }

int main(){
// Comportamiento distinto para un mismo metodo -> polimorfismo
// Funciones/metodos que tengan un mismo nombre y que se comporten
// Sobrecarga de funciones
    Perro* p;       // nombre_cientifico duenno
    Ave* a;         // habitat nombre_cientifico [alimentos]
    
    p.print();
    a.print();
}
