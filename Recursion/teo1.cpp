#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int min_vec(vector<int> v, unsigned int desde, unsigned int hasta){ 
    if (desde == hasta-1){
        // Caso base 1: 1 elemento
        return v[desde];
    }
    else{ // Dos o mas elementos
        // Divide
        unsigned int medio = (desde+hasta)/2;
        // Conquer
        int a = min_vec(v, desde, medio);
        int b = min_vec(v, medio, hasta);
        // Combine
        if(a>b){
            return b;
        }
        else{
            return a;
        }
    }
}

int buscar(vector<int> v, int a, unsigned int desde, unsigned int hasta){
    if(v[0] > a){
        return -1;
    }
    else if(v[desde] == a){
        return desde;
    }
    else if(a > v[v.size()-1]){
        return -2;
    }
    else{
        unsigned int medio = (desde+hasta)/2;
        if(v[medio] <= a){
            return buscar(v, a, medio, hasta);
        }
        else{
            return buscar(v, a, desde, medio);
        }
    }
}


int main(){
    vector<int> v = {0,1,2,3};
    int a = 1;
    unsigned int desde = 0;
    unsigned int hasta = 4;
    cout << "resultado buscar:" << buscar(v, a, desde, hasta) << endl;
}