//
// Created by Mirsali Ruiz on 23/11/2022.
//

#ifndef PC3_CPP_SISTEMA_H
#define PC3_CPP_SISTEMA_H
#include "Vehiculo.h"
#include "Auto.h"
#include "Moto.h"
#include "Camion.h"
#include "Menu.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Sistema {
vector<Vehiculo*>* vehiculos;
Menu* menuPrincipal;
Menu* menuSecundario;
public:
    Sistema() {
        vehiculos= new vector<Vehiculo*>;
        menuPrincipal=new Menu;
        menuSecundario=new Menu;
    }

    void ejecutar1() {
        registrarPorTipo("Vehiculos.csv");
        menuPrincipal->registrarOpcion("\t[1] Operar con 1 automovil");
        menuPrincipal->registrarOpcion("\t[2] Imprimir todos los vehiculos");
        menuPrincipal->registrarOpcion("\t[3] Archivar todos los vehiculos");
        menuPrincipal->registrarOpcion("\t[0] Finalizar Programa");
        menuSecundario->registrarOpcion("\t[1] Archivar");
        menuSecundario->registrarOpcion("\t[2] Imprimir");
        menuSecundario->registrarOpcion("\t[3] Calcular e imprimir");
        menuSecundario->registrarOpcion("\t[4] Infraccion");
        menuSecundario->registrarOpcion("\t[0] volver al Menu Principal");
        int opcion=0;
        string placa;
        do {
            cout<<"\t================================================\n";
            cout<<"\t>>>>>>>>>>>>>>>> Menu Principal <<<<<<<<<<<<<<<<\n";
            cout<<"\t=================================================\n";
            menuPrincipal->mostrarOpciones();
            cout<<"\t================================================\n";
            opcion=menuPrincipal->seleccionarOpcion();
            switch (opcion) {
                case 1:
                    cout<<"Ingrese la Placa:";cin>>placa;
                    if(buscar(placa)== nullptr){
                        cout<<"\n\tPlaca no encontrada...verifique\n\n";
                    } else{
                        ejecutar2(placa);
                    }
                    break;
                case 2:
                    cout<<"=========================================================\n";
                    imprimirTodo();
                    cout<<"=========================================================\n\n";
                    break;
                case 3:
                    archivarTodo();
                    break;
            }
        } while (opcion!=0);
        char r=2;
        cout<<"\n\tPROGRAMA FINALIZADO..."<<r<<endl;
    }




    void ejecutar2(string placa) {
        int opcion = 0;
        do{
            cout<<"\n\t================================================\n";
            cout<<"\t>>>>>>>>>>>>>>>> Menu Secundario <<<<<<<<<<<<<<<<\n";
            cout<<"\t================================================\n";
            menuSecundario->mostrarOpciones();
            cout<<"\t================================================\n";
            opcion=menuSecundario->seleccionarOpcion();
            switch (opcion) {
                case 1:
                    Archivar(placa);
                    break;
                case 2:
                    cout<<"\t====================================";
                    imprimir(placa);
                    cout<<"\t====================================\n\n";
                    break;
                case 3:
                    cout<<"\t====================================";
                    calcularImprimir(placa);
                    cout<<"\t====================================\n\n";
                    break;
                case 4:
                    cout<<"\t====================================\n";
                    vistaInfraccion(placa);
                    cout<<"\t====================================\n\n";
                    break;
            }
        } while (opcion!=0);

    }
    void imprimirTodo(){
        for (auto vehiculo:*vehiculos){
            vehiculo->imprimirDatos();
            cout<<"\t"<<vehiculo->infraccion()<<endl;
        }
    }

    void archivarTodo(){
        for (auto vehiculo:*vehiculos){
            vehiculo->archivar();
        }
    }

    Vehiculo* buscar(string placa){
        for (auto vehiculo: *vehiculos) {
            if (vehiculo->getPlaca()== placa)
                return vehiculo;
        }
        return nullptr;
    }

    void Archivar(string placa) {
        if(buscar(placa)== nullptr)
            cout<<"Placa no encontrada...verifique\n";
        else
            buscar(placa)->archivar();
    }

    void imprimir(string placa){
        if(buscar(placa)== nullptr)
            cout<<"Placa no encontrada...verifique\n";
        else
            buscar(placa)->imprimirDatos();
    }

    void calcularImprimir(string placa){
        imprimir(placa);
        cout<<"\tImpuesto anual SAT :"<<buscar(placa)->impuesto()<<endl;
    }

    void vistaInfraccion(string placa){
        cout<<buscar(placa)->infraccion()<<endl;
    }

    void registrarPorTipo(string archivo) {
        fstream entrada;
        entrada.open("../"+archivo,ios::in);

        string placa,anio,linea,palabra="";
        double cubicaje,potencia,sobrecarga;
        int contaminacion,ejes;

        while (getline(entrada,linea)) {
            int coma=1;
            string tipo="";
            for (auto letra: linea) {
                if (letra == ',') {
                    if(tipo=="Moto") {
                        int n_coma=1;
                        for (auto Letra: linea) {
                            if (Letra == ',') {
                            switch (n_coma) {
                                case 2:
                                    placa = palabra;
                                    break;
                                case 3:
                                    anio = palabra;
                                    break;
                                case 4:
                                    cubicaje = stof(palabra);
                                    break;
                            }
                            palabra = "";
                            n_coma++;
                        } else{
                            palabra+=Letra;}
                        }
                        auto moto_nuevo = new Moto(placa, anio, cubicaje);
                        vehiculos->push_back(moto_nuevo);
                        break;
                    }

                    else if(tipo=="Auto") {
                        int n_coma=1;
                        for (auto Letra: linea) {
                            if (Letra == ',') {
                                switch (n_coma) {
                                    case 2:
                                        placa = palabra;
                                        break;
                                    case 3:
                                        anio = palabra;
                                        break;
                                    case 4:
                                        cubicaje = stof(palabra);
                                        break;
                                    case 5:
                                        potencia = stof(palabra);
                                        break;
                                    case 6:
                                        contaminacion = stof(palabra);
                                        break;
                                }
                                palabra = "";
                                n_coma++;
                            } else{
                                palabra+=Letra;}
                        }

                        auto auto_nuevo = new Auto(placa, anio, cubicaje,potencia,contaminacion);
                        vehiculos->push_back(auto_nuevo);
                        tipo="";
                        break;
                    }


                    else if (tipo=="Camion") {
                        int n_coma = 1;
                        for (auto Letra: linea) {
                            if (Letra == ',') {
                                switch (n_coma){
                                    case 2:
                                        placa = palabra;
                                        break;
                                    case 3:
                                        anio = palabra;
                                        break;
                                    case 4:
                                        ejes = stoi(palabra);
                                        break;
                                    case 5:
                                        sobrecarga = stof(palabra);
                                        break;
                                }
                                palabra = "";
                                n_coma++;
                            } else {
                                palabra += Letra;
                            }
                        }

                        auto camion_nuevo = new Camion(placa, anio,ejes,sobrecarga);
                        vehiculos->push_back(camion_nuevo);
                        tipo="";
                        break;
                    }

                }
                else {
                        tipo += letra;
                    }
            }
        }
        entrada.close();
        cout<<"\n\t===========================\n";
        cout<<"\tArchivo cargado al sistema\n";
        cout<<"\t===========================\n\n";

    }


};


#endif //PC3_CPP_SISTEMA_H
