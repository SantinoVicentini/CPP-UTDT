#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


// ejercicio 1 
// a)
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// b)
bool es_par(int n){
    if(n==0){
        return true;
    }
    else if(n==1){
        return false;
    }
    return es_par(n-2);
}

// ejercicio 2
// a)
int productoria(const vector<int> & v, unsigned int desde = 0){
    if(desde >= v.size()){
        return 1;
    }
    return v[desde] * productoria(v, desde + 1);
}

// b)
int cantidad_de_ocurrencias(string s, const vector<string> & v, unsigned int pos = 0){
    int con = 0;
    if(s == v[pos]){
        con ++;
    }
    else if(pos >= v.size()){
        return 0;
    }
    return con + cantidad_de_ocurrencias(s, v, pos + 1);
}

int main(){
    int a = 8;
    int b = 67;
    vector<int> v = {1,1,2,3,3};
    vector<string> d = {"holaa", "cha", "hola", "hola", "hola"};
    string s = "hola";
    //ejercicio 1
    // a)
    cout << "sucecion fibonacci: " << fibonacci(a) << endl;
    // b)
    cout << "el numero es par: " << es_par(b) << endl;
    //ejercicio 2
    // a)
    cout << "resultado de productoria: " << productoria(v) << endl;
    // b)
    cout << "cantidad de ocurrencias: " << cantidad_de_ocurrencias(s, d) << endl;

}