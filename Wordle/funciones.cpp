#include "funciones.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> cargar_listado(const string & nombre_archivo){

    

    vector<string> rv;
    string filename = nombre_archivo;
    ifstream infile (nombre_archivo);
    string line;

    if(infile.good() == false){
        exit(1);
    }

  

    while(!infile.eof()){
        getline(infile, line);
        if(line.size() > 0){
            rv.push_back(line);
        }
    
    }
    infile.close();
    return rv;
}

bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){

    
    
    if(intento.size() == palabra_secreta.size()){
        for(int i = 0; i < listado.size(); i++){
            if(listado[i] == intento){
                return true;
            }
        }
    }

    return false;
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){

    

    vector<EstadoLetra> rv;
    for(int i=0; i<intento.size(); i++){
        EstadoLetra estado = EstadoLetra::NoPresente;
        for(int j=0; j<intento.size(); j++){
            if(intento[i] == palabra_secreta[j]){
                estado = EstadoLetra::LugarIncorrecto;
            }
        }
        if(intento[i] == palabra_secreta[i]){
            estado = EstadoLetra::LugarCorrecto;
        }
        rv.push_back(estado);
    }
    return rv;
}

string respuesta_en_string(const vector<EstadoLetra> & respuesta){
    string rv;
    for(int i=0; i<respuesta.size(); i++){
        switch (respuesta[i])
        {
        case EstadoLetra::LugarCorrecto :
            rv.append("+");
            break;
        
        case EstadoLetra::LugarIncorrecto :
            rv.append("-");
            break;
        
        case EstadoLetra::NoPresente :
            rv.append("X");
            break;
        }
    }

    return rv;
}