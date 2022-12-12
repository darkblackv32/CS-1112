#ifndef PC3_CPP_VEHICULO_H
#define PC3_CPP_VEHICULO_H
#include <iostream>
using namespace std;
class Vehiculo {
protected:
string placa;
string anio;
public:
    Vehiculo(const string &placa, const string &anio) : placa(placa), anio(anio) {}

    const string &getPlaca() const {
        return placa;
    }

    void setPlaca(const string &placa) {
        Vehiculo::placa = placa;
    }

    const string &getAnio() const {
        return anio;
    }

    void setAnio(const string &anio) {
        Vehiculo::anio = anio;
    }

    virtual  double impuesto()=0;

    virtual void archivar()=0;

    virtual void imprimirDatos()=0;

    virtual string infraccion()=0;

    virtual ~Vehiculo() {

    }

};


#endif //PC3_CPP_VEHICULO_H
