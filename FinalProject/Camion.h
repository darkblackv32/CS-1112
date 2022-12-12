//
// Created by Mirsali Ruiz on 23/11/2022.
//

#ifndef PC3_CPP_CAMION_H
#define PC3_CPP_CAMION_H
#include "Vehiculo.h"
#include <string>
#include<stdlib.h>
using namespace std;

class Camion:public Vehiculo{
int ejes;
double sobrecarga;
public:
    Camion(const string &placa, const string &anio, int ejes, double sobrecarga) : Vehiculo(placa, anio), ejes(ejes),
                                                                                   sobrecarga(sobrecarga) {}

    int getEjes() const {
        return ejes;
    }

    void setEjes(int ejes) {
        Camion::ejes = ejes;
    }

    double getSobrecarga() const {
        return sobrecarga;
    }

    void setSobrecarga(double sobrecarga) {
        Camion::sobrecarga = sobrecarga;
    }

    double impuesto() override {
        return sobrecarga*100.0;
    }

    string infraccion() override {
        auto n=rand()%(100);
        if(n<30)
            return "Infraccion U09, no respetar la velocidad maxima de la via o circular por carril distinto al autorizado para el transporte de carga (230 Soles)\n";
        else
            return "El vehiculo no cuenta no ninguna infraccion\n";

    }


    void archivar() override {
        string nameArchivo;
        cout<<"\t>>> Guardar Archivo de la Moto <<<\n";
        cout<<"\tNombre del archivo(sin espacios)\n";
        cout<<"\tIngrese Nombre:";
        cin>>nameArchivo;
        fstream archivo;
        archivo.open("../"+nameArchivo+".csv",ios::out);
        archivo<<"\t"<<nameArchivo<<endl;
        archivo<<"Placa : "<<getPlaca()<<endl;
        archivo<<"Anio de registro : "<<this->getAnio()<<endl;
        archivo<<"Cantidad de ejes : "<<this->getEjes()<<endl;
        archivo<<"Sobrecarga : "<<this->getSobrecarga()<<" toneladas"<<endl;
        archivo<<"Impuesto anual SAT : "<<this->impuesto()<<" soles"<<endl;
        archivo<<this->infraccion()<<endl;

        archivo.close();
        cout<<"\n\t===========================\n";
        cout<<"\tArchivo "<<nameArchivo<<" Guardado\n";
        cout<<"\t===========================\n\n";
    }

    void imprimirDatos() override {
        cout<<"\n\tTipo : Camion"<<endl;
        cout<<"\tPlaca : "<<this->getPlaca()<<endl;
        cout<<"\tAnio de registro : "<<this->getAnio()<<endl;
        cout<<"\tCantidad de ejes : "<<this->getEjes()<<endl;
        cout<<"\tSobrecarga : "<<this->getSobrecarga()<<" toneladas\n";
        cout<<"\tImpuesto : "<<this->impuesto()<<endl;

    }



    virtual ~Camion() {

    }
};


#endif //PC3_CPP_CAMION_H
