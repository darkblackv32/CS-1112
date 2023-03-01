#include "CFlotante.h"

CFlotante::CFlotante(){

}

CFlotante::CFlotante(int _entero, int _decimal){
    this->entero = _entero;
    this->decimal = _decimal;
}

ostream& operator<<(ostream& o, CFlotante e){
    o<<to_string(e.entero) + "." + to_string(e.decimal)<<endl;
    return o;
}

CFlotante& operator+(const CFlotante& e1, const CFlotante& e2 ){

}

CFlotante& operator-(const CFlotante& e1, const CFlotante& e2 ){
    
}

CFlotante& operator*(const CFlotante& e1, const CFlotante& e2 ){
    
}

CFlotante& operator/(const CFlotante& e1, const CFlotante& e2 ){
    
}