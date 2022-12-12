//
// Created by Mirsali Ruiz on 23/11/2022.
//

#ifndef PC3_CPP_MENU_H
#define PC3_CPP_MENU_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Menu {
private:
    vector<string>* opciones;

public:
    Menu() {
        opciones = new vector<string>();
    }

    vector<string> *getOpciones() const {
        return opciones;
    }

    void registrarOpcion(string opcion){
        opciones->push_back(opcion);
    }
    void mostrarOpciones(){
        for(const auto opcion : *opciones)
            cout << opcion <<endl;
    }

    int seleccionarOpcion(){
        int opcion = 0;
        do {
            cout << "\nOpcion: ";
            cin >> opcion;

        }while (opcion<0 || opcion > opciones->size());
        return opcion;
    }


};


#endif //PC3_CPP_MENU_H
