#include <iostream>
using namespace std;

class CFlotante {
private:
    int entero;
    int decimal;
public:
    CFlotante();
    CFlotante(int _ent, int _decimal);
    friend ostream& operator<<(ostream& o, CFlotante e);
    friend CFlotante& operator+(const CFlotante& e1, const CFlotante& e2 );
    friend CFlotante& operator-(const CFlotante& e1, const CFlotante& e2 );
    friend CFlotante& operator*(const CFlotante& e1, const CFlotante& e2 );
    friend CFlotante& operator/(const CFlotante& e1, const CFlotante& e2 );
    
};