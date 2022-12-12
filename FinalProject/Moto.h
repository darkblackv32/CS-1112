//
// Created by Mirsali Ruiz on 23/11/2022.
//

#ifndef PC3_CPP_MOTO_H
#define PC3_CPP_MOTO_H
#include "Vehiculo.h"
#include <string>
#include <fstream>
#include<stdlib.h>

using namespace std;

class Moto: public Vehiculo{
double cubicaje;
public:
    Moto(const string &placa, const string &anio, double cubicaje) : Vehiculo(placa, anio), cubicaje(cubicaje) {}


    double getCubicaje() const {
        return cubicaje;
    }

    void setCubicaje(double cubicaje) {
        Moto::cubicaje = cubicaje;
    }

    double impuesto()override{
        return ((cubicaje+99)*20)/100.0;
    }

    string infraccion() override {
        auto n=rand()%(100);
        if(n<=30)
            return "Infraccion V03, prestar el servicio con vehiculos que no se encuentren habilitados (230 Soles)\n";
        else
            return "El vehiculo no cuenta con ninguna infraccion\n";

    }

    void archivar()override{
        string nameArchivo;
        cout<<"\t>>> Guardar Archivo de la Moto <<<\n";
        cout<<"\tNombre del archivo(sin espacios)\n";
        cout<<"\tIngrese Nombre:";
        cin>>nameArchivo;
        fstream archivo;
        archivo.open("../"+nameArchivo+".csv",ios::out);
        archivo<<"\t"<<nameArchivo<<endl;
        archivo<<"Placa : "<<this->getPlaca()<<endl;
        archivo<<"Anio de registro : "<<this->getAnio()<<endl;
        archivo<<"Cubicaje : "<<this->getCubicaje()<<" metros cubicos"<<endl;
        archivo<<"Impuesto anual SAT : "<<this->impuesto()<<" soles"<<endl;
        archivo<<this->infraccion()<<endl;

        archivo.close();
        cout<<"\n\t===========================\n";
        cout<<"\tArchivo "<<nameArchivo<<" Guardado\n";
        cout<<"\t===========================\n\n";
    }

    void imprimirDatos() override {
        cout<<"\n\tTipo : Moto"<<endl;
        cout<<"\tPlaca : "<<this->getPlaca()<<endl;
        cout<<"\tAnio de registro : "<<this->getAnio()<<endl;
        cout<<"\tCubicaje : "<<this->getCubicaje()<<" metros cubicos\n";
        cout<<"\tImpuesto : "<<this->impuesto()<<endl;

    }




    virtual ~Moto() {

    }
};


#endif //PC3_CPP_MOTO_H
