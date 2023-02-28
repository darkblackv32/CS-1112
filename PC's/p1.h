#include <bits/stdc++.h>
using namespace std;

class Usuario
{
private:
    string nombre;
    string apellido;
    string tarjeta;
    float saldo;
    
public:
    Usuario(){}
    Usuario(string nom, string ape, string tar, float sal){
        this->nombre = nom;
        this->apellido = ape;
        this->tarjeta = tar;
        this->saldo = sal;
    }
    ~Usuario(){}
    void setSaldo(int x){
        this->saldo = x;
    }
    float getSaldo(){
        cout<<"Saldo de "<<nombre<<" : ";
        return saldo;
    };
    void showSaldo(){cout<<"Su saldo es: "<<saldo;};
    void showTarjeta(){cout<<"Su tarjeta es: "<<tarjeta;};
    void setTarjeta(string x){
        this->tarjeta = x;
    }
    string getTarjeta(){
        return tarjeta;};
    
    friend ostream& operator << (ostream& os, Usuario p){
    os << "{" <<  p.nombre << ", " << p.apellido << ", " << p.tarjeta << ", " << p.saldo <<"}";
    return os;
    
    }
    
     void setOpcion(Usuario u1){
        int opt;
        cout<<"Selecciona una opcion: "<<endl;
        cout<<"1) Troncal "<<endl;
        cout<<"2) Alimentador"<<endl;
        cin>>opt;
        if(opt == 1){
            int opt2;
            cout<<"Selecciona una opcion: "<<endl;
            cout<<"1) Expreso "<<endl;
            cout<<"2) Regular"<<endl;
            cin >> opt2;
                if(opt2 == 1){
                    int nex;
                    cout<<"Ingresa el expreso: "<<endl;
                    cin>>nex;
                    
                }
                else if(opt2 == 2){
                    char nex;
                    cout<<"Ingresa tipo de servicio: "<<endl;
                    cin>>nex;
                    
                }
            }
        else if(opt == 2){
            "Usted a elegido el alimentador";
        }

    }
    

    
};

class Metropolitano 
{
private:
    friend ostream& operator << (ostream& os, Metropolitano& m);
public:
    Metropolitano
    (/* args */) {}
    ~Metropolitano
    () {}
    virtual void cobrar(Usuario u1) = 0;
    friend ostream& operator << (ostream& os, Metropolitano& m){
    
    return os;
    }
    
    
};

class Troncal : public Metropolitano
{
private:
    int horaIn;
    int horaFin;
    string estIn;
    string estFin;

public:
    Troncal(){}
    Troncal(int hi, int hf, string esI, string esF){
        this->horaIn = hi;
        this->horaFin = hf;
        this->estIn = esI;
        this->estFin = esF;
    }
    void cobrar(Usuario u1){
        if(u1.getTarjeta() == "General"){
            u1.setSaldo(u1.getSaldo() - 2.50);
        }
        else if(u1.getTarjeta() == "Escolar"){
            u1.setSaldo(u1.getSaldo() - 1.25);
        }
        else if(u1.getTarjeta() == "Universitario"){
            u1.setSaldo(u1.getSaldo() - 1.25);
        }
    }

    // void setOpcion(Usuario u1){

    // }
    

    ~Troncal(){}
    
};

class Expreso : public Troncal
{
private:
    int Exp;
public:
    Expreso();
    Expreso(int _hi, int _hf, string _esI, string _esF) : Troncal(_hi, _hf, _esI, _esF){}
    ~Expreso() {}
    void setOpEx(int x){
        this->Exp = x;
    }
};


class Regular : public Troncal
{
private:
    char opt;
public:
    Regular();
    Regular(int _hi, int _hf, string _esI, string _esF) : Troncal(_hi, _hf, _esI, _esF){}
    ~Regular() {}
    void setOpt(char x){
        this->opt = x;
    }
};



class Alimentador : public Metropolitano
{
private:
    /* data */
public:
    Alimentador() {}
    void cobrar(Usuario u1){
        if(u1.getTarjeta() == "General"){
            u1.setSaldo(u1.getSaldo() - 1);
        }
        else if(u1.getTarjeta() == "Escolar"){
            u1.setSaldo(u1.getSaldo() - 0.25);
        }
        else if(u1.getTarjeta() == "Universitario"){
            u1.setSaldo(u1.getSaldo() - 0.25);
        }
    }

    
   

    ~Alimentador() {}
};