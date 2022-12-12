#include <iostream>
using namespace std;



void generarAleatorio(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8);
void Avanzar(float x, int pasos);

int main( ) {
    float a1, a2, a3, a4, a5, a6, a7, a8;
   
    int auto1 = 200, auto2, auto3, auto4, auto5, auto6, auto7, auto8; 

   

    generarAleatorio(a1, a2, a3, a4, a5, a6, a7, a8);
    
    Avanzar(a1, auto1);

    generarAleatorio(a1, a2, a3, a4, a5, a6, a7, a8);
    
    Avanzar(a1, auto1);

    
    
    
    
  return 0;
}

void Avanzar(float x, int pasos){
    if(x > 0.8){
        pasos += 83;
    }
    else if(x >= 0.6 and x <= 0.8){
        pasos += 50;
    }
    else if(x >= 0.4 and x <= 0.6){
        pasos += 30;
    }
    else if(x >= 0.2 and x <= 0.4){
        pasos -= 2;
    }
    else if(x <= 0.2){
        pasos -= 10;
    }
    cout<<"Pasos: "<<pasos<<endl;
}

void generarAleatorio(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8){
    
    srand( time( NULL ) );

    a1 = ((rand( ) % 1001 ) / 1000.0f );
    a2 = ((rand( ) % 1001 ) / 1000.0f );   
    a3 = (( rand( ) % 1001 ) / 1000.0f );
    a4 = (( rand( ) % 1001 ) / 1000.0f );
    a5 = ((rand( ) % 1001 ) / 1000.0f );
    a6 = ((rand( ) % 1001 ) / 1000.0f );
    a7 = ((rand( ) % 1001 ) / 1000.0f );
    a8 = ((rand( ) % 1001 ) / 1000.0f );

    cout<<"Velocidad a1: "<<a1<<endl;
    // cout<<"Velocidad a2: "<<a2<<endl;
    // cout<<"Velocidad a3: "<<a3<<endl;
    // cout<<"Velocidad a4: "<<a4<<endl;
    // cout<<"Velocidad a5: "<<a5<<endl;
    // cout<<"Velocidad a6: "<<a6<<endl;
    // cout<<"Velocidad a7: "<<a7<<endl;
    // cout<<"Velocidad a8: "<<a8<<endl;
}
