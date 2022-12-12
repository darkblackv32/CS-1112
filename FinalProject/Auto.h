//
// Created by Mirsali Ruiz on 23/11/2022.
//

#ifndef PC3_CPP_AUTO_H
#define PC3_CPP_AUTO_H
#include "Vehiculo.h"
#include <string>
#include <fstream>
#include <time.h>
#include<stdlib.h>

using namespace std;

class Auto: public Vehiculo{
double cubicaje;
double potencia;
int nivelContaminacion;
public:
    Auto(const string &placa, const string &anio, double cubicaje, double potencia, int nivelContaminacion) : Vehiculo(
            placa, anio), cubicaje(cubicaje), potencia(potencia), nivelContaminacion(nivelContaminacion) {}

    double getCubicaje() const {
        return cubicaje;
    }

    void setCubicaje(double cubicaje) {
        Auto::cubicaje = cubicaje;
    }

    double getPotencia() const {
        return potencia;
    }

    void setPotencia(double potencia) {
        Auto::potencia = potencia;
    }

    int getNivelContaminacion() const {
        return nivelContaminacion;
    }

    void setNivelContaminacion(int nivelContaminacion) {
        Auto::nivelContaminacion = nivelContaminacion;
    }

    virtual double impuesto()override{
        return  (cubicaje+99)/100*10*(nivelContaminacion+1);
    }

    string infraccion() override {
        auto n=rand()%(100);
        if(n<30)
            return "Infraccion L04, abrir o dejar abierta la puerta de un vehiculo estacionado,dificultando la circulacion vehicular. (184 Soles)";
        else
            return "El vehiculo no cuenta con ninguna infraccion\n";
    }

    void archivar(){
        string nameArchivo;

        cout<<"\t>>> Guardar Archivo del Auto <<<\n";
        cout<<"\tNombre del archivo(sin espacios)\n";
        cout<<"\tIngrese Nombre:";
        cin>>nameArchivo;
        fstream archivo;
        archivo.open("../"+nameArchivo+".csv",ios::out);
        archivo<<"\t"<<nameArchivo<<endl;
        archivo<<"Placa : "<<getPlaca()<<endl;
        archivo<<"Anio de registro : "<<getAnio()<<endl;
        archivo<<"Cubicaje : "<<getCubicaje()<<" metros cubicos"<<endl;
        archivo<<"Potencia : "<<getPotencia()<<" caballos de fuerza"<<endl;
        archivo<<"Nivel de contaminacion :"<<getNivelContaminacion()<<endl;
        archivo<<"Impuesto anual SAT : "<<this->impuesto()<<" soles"<<endl;
        archivo<<this->infraccion()<<endl;


        archivo.close();
        cout<<"\n\t===========================\n";
        cout<<"\tArchivo "<<nameArchivo<<" Guardado\n";
        cout<<"\t===========================\n\n";
    }

    void imprimirDatos() override {
        cout<<"\n\tTipo : Auto"<<endl;
        cout<<"\tPlaca : "<<this->getPlaca()<<endl;
        cout<<"\tAnio de registro : "<<this->getAnio()<<endl;
        cout<<"\tCubicaje : "<<this->getCubicaje()<<" metros cubicos"<<endl;
        cout<<"\tPotencia : "<<this->getPotencia()<<" caballos de fuerza"<<endl;
        cout<<"\tNivel de contaminacion : "<<getNivelContaminacion()<<endl;
        cout<<"\tImpuesto : "<<this->impuesto()<<endl;

    }



    virtual ~Auto() {

    }


};


#endif //PC3_CPP_AUTO_H
