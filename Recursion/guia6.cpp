#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>

#include "clases6.h"

using namespace std;

Fecha::Fecha(int dia, int mes, int anio) :
    dia(dia), mes(mes), anio(anio)
    {}

void Fecha::avanzar_dia(){
    int dia = dia();
    int mes = mes();
    int anio = anio();

    if(dia == 30 && mes == 2 && mes == 4 && mes == 6 && mes == 9 && mes == 11 ){
        dia = 1;
        mes++;
    }
    else if(dia == 31 && mes == 1 && mes == 3 && mes == 5 && mes == 7 && mes == 8 && mes == 10){
        dia = 1;
        mes++;
    }
    else if(dia == 31 && mes == 12){
        dia = 1;
        mes = 1;
        anio++
    }
    else{
        dia++;
    }
}

void Fecha::avanzar_n_dias(int n){
    int dia = dia();
    int mes = mes();
    int anio = anio();

    if(dia + n > 30 && mes == 2 && mes == 4 && mes == 6 && mes == 9 && mes == 11){
        dia = n;
        mes++
    }
    else if(dia + n > 31 && mes == 1 && mes == 3 && mes == 5 && mes == 7 && mes == 8 && mes == 10){
        dia = n-3;
        mes++;
    }
    else if(dia + n > 31 && mes == 12){
        dia = n-3;
        mes = 1;
        anio ++;
    }
    else{
        dia = dia + n;
    }
}