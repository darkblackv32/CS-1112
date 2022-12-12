#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

void aleatorio(float *a1, float *a2, float *a3, float *a4, float *a5, float *a6, float *a7, float *a8);
void mercedes(float i,long int recorrido, long int sucesiones);//funcion que modifica los parametros de cada piloto
void redbull(float i,long int recorrido, long int sucesiones);
void ferrari(float i,long int recorrido, long int sucesiones);
void mclaren(float i,long int recorrido, long int sucesiones);
void renault(float i,long int recorrido, long int sucesiones);
void haas(float i,long int recorrido, long int sucesiones);
void williams(float i,long int recorrido, long int sucesiones);
void toyota(float i,long int recorrido, long int sucesiones);

int main(){
    srand(time(NULL));
    float i_mercedes,i_redbull,i_ferrari,i_mclaren,i_renault,i_haas,i_williams,i_toyota;
    float *p_mercedes,*p_redbull,*p_ferrari,*p_mclaren,*p_renault,*p_haas,*p_williams,*p_toyota;
    long int r_mercedes = 0,r_redbull = 0,r_ferrari = 0,r_mclaren = 0,r_renault = 0,r_haas = 0,r_williams = 0,r_toyota = 0;
    long int s_mercedes = 0,s_redbull = 0,s_ferrari = 0,s_mclaren = 0,s_renault = 0,s_haas = 0,s_williams = 0,s_toyota = 0;
    bool b_mercedes,b_redbull,b_ferrari,b_mclaren,b_renault,b_haas,b_williams,b_toyota;
    bool *d_mercedes,*d_redbull,*d_ferrari,*d_mclaren,*d_renault,*d_haas,*d_williams,*d_toyota;
    int c_mercedes = 0,c_redbull = 0,c_ferrari = 0,c_mclaren = 0,c_renault = 0,c_haas = 0,c_williams = 0,c_toyota = 0;

    p_mercedes = &i_mercedes;
    p_redbull = &i_redbull;
    p_ferrari = &i_ferrari;
    p_mclaren = &i_mclaren;
    p_renault = &i_renault;
    p_haas = &i_haas;
    p_williams = &i_williams;
    p_toyota = &i_toyota;

    d_mercedes = &b_mercedes;
    d_redbull = &b_redbull;
    d_ferrari = &b_ferrari;
    d_mclaren = &b_mclaren;
    d_renault = &b_renault;
    d_haas = &b_haas;
    d_williams = &b_williams;
    d_toyota = &b_toyota;

    aleatorio(p_mercedes,p_redbull,p_ferrari,p_mclaren,p_renault,p_haas,p_williams,p_toyota);

    return 0;
}

void aleatorio(float *a1, float *a2, float *a3, float *a4, float *a5, float *a6, float *a7, float *a8){
    *a1 = ((rand( ) % 1001 ) / 1000.0f );
    *a2 = ((rand( ) % 1001 ) / 1000.0f );   
    *a3 = (( rand( ) % 1001 ) / 1000.0f );
    *a4 = (( rand( ) % 1001 ) / 1000.0f );
    *a5 = ((rand( ) % 1001 ) / 1000.0f );
    *a6 = ((rand( ) % 1001 ) / 1000.0f );
    *a7 = ((rand( ) % 1001 ) / 1000.0f );
    *a8 = ((rand( ) % 1001 ) / 1000.0f );
}

void mercedes(float i,long int recorrido, long int sucesiones){
    if(i > 0.8){
        recorrido += 83;
    }
    else if(i >= 0.6 and i <= 0.8){
        recorrido += 50;
    }
    else if(i >= 0.4 and i <= 0.6){
        recorrido += 30;
    }
    else if(i >= 0.2 and i <= 0.4){
        //se puede poner un booleano que se activa con pasos 3 pasos seria aumentar 2 variables más
    }
    else if(i <= 0.2){
        recorrido -= 10;
    }
    sucesiones++;
}