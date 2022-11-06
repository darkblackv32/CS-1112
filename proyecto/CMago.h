#include <bits/stdc++.h>
#include "CAlimento.h"

using namespace std;


class Mago
{
private:
    int totest;
    string est_an;
    string name;
public:
    Mago() = default;
    ~Mago(){};
    void setValues(){
        int x;
        cout<<"Ingresa la cantidad de puntos de Gandalf: ";
        cin>>x;
        this->totest = x;}
        

    void evaEst(){
        int x = totest;
        if(x > 15){
            this->est_an = "ReFeliz";
        }
        else if(x > 1 and x < 15){
            this->est_an = "Feliz";
        }
        else if(x > -5 and x < 0){
            this->est_an = "Triste";
        }
        else if(x < -5){
            this->est_an = "Enojado";
        }
        cout<<"Su estado de animo actual es: "<<est_an<<endl;
    }

    void comer(Alimento* obj){
        int y = obj->getCantidad();
        int x = obj->getPuntos()*y;
        totest = totest + x;
    }
    int getpTotal(){return totest;}
    string getEst(){return est_an;}
};










