#include "funciones.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    // Palabra al azar del listado x cada ejecucion
    vector<string> list = cargar_listado("../Wordle/listado.txt");
    srand(time(NULL));
    int s = rand() % (list.size()-1) + 0;
    string sWord = list[s];
    

    // Logica del juego
    int intentos = 5;

    while(intentos > 0){
        string tWord;
        cout << "ingresa una palabra: " << endl;
        cin >> tWord ;
        vector<EstadoLetra> evIntento = evaluar_intento(tWord, sWord);
        string intento = respuesta_en_string(evIntento);
        if(intento_valido(tWord, sWord, list)){
            if(intento == "+++++"){
                cout << "Encontraste la palabra secreta, felicitaciones!" << endl;
                break;
            }
            else
                cout << intento << endl;
                intentos --; 
                cout << "Te quedan " << intentos << " intentos." << endl;
        }
        else
            cout << "Intento no valido. La palabra no tiene 5 letras o no se encuentra en el listado." << endl;
            
    }

    // Finalizacion de los intentos
    if(intentos == 0){
        cout << "Se agotaron los intentos, la palabra secreta era: " << sWord << endl;
    }
   
}
