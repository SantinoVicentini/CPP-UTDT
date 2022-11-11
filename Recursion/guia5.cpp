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

// c)
int contar_coincidencias(const vector<int> & v, unsigned int desde = 0){
    int cont = 0;
    if(desde == v[desde]){
        cont ++;
    }
    else if(desde >= v.size()){
        return 0;
    }
    return cont + contar_coincidencias(v, desde + 1);
}

// d) ?
vector<int> solo_positivos(const vector<int> & v, unsigned int desde = 0){
    vector<int> vr;
    if(v[desde] > 0){
        vr.push_back(v[desde]);
    }
    else if(desde >= v.size()){
        return vr;
    }
    return solo_positivos(v, desde + 1);
}

// e)  ?
void multiplicar_todos(vector<int> & v, int n, unsigned int desde = 0){
    v[desde] = v[desde] * n;
    return multiplicar_todos(v, n, desde + 1);
}

// ejercicio 3
// a)
int cantidad_de_ocurrencias(string s, const vector<string> & v, unsigned int desde, unsigned int hasta){
    int con = 0;
    if(hasta <= desde){
        // caso base 1 rango vacio
        return 0;
    }
    else if(desde == hasta-1){
        // caso base 2 1 elemento
        if(s == v[desde]){
            con++;
        }
    }
    else{ // 2 o mas elementos
        unsigned int medio = (desde + hasta)/2;
        // conquer resuelvo 2 subproblemas recursivamente
        int a = cantidad_de_ocurrencias(s, v, desde, medio);
        int b = cantidad_de_ocurrencias(s, v, medio, hasta);    
        // combine
        return con + a + b;
    }
}

// b)

// ejercicio 4)
// a)
int potencia(int n, int m){
    if(m == 0){
        // caso base 1 elevado a la 0 = 1
        return 1;
    }
    else if(m == 1){
        // caso base 2 elevado a la 1 = n
        return n;
    }
    else if(m == 2){
        return n*n;
    }
    else{ //m mas de 2 
        unsigned int mitad = m - 2;
        // conquer 
        int a = potencia(n, mitad);
        // combine
        return n*n*a;
    }
}

// b)
int vector_montania(vector<int> m, unsigned int desde, unsigned int hasta){
   if(desde == hasta -1){
        return m[desde];
   }
   else{
        unsigned int medio = (desde+hasta)/2;
        int a = vector_montania(m, desde, medio);
        int b = vector_montania(m, medio, hasta);
        if(m[hasta] > a && m[hasta] > b){
            return m[hasta];
        }
        else if( a < b){
            return b;
        }
        else{
            return a;
        }

   }
}

//ejercicio 9
// a)
void selection_sort(vector<int> & v){
    int min;
    for(int i=0; i<v.size(); i++){
        min = i;
        for(int j= i+1; j<v.size(); j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        swap(v[i], v[min]);
    }
}

void insertion_sort(vector<int> & v){
    int pos;
    for(int i=0; i<v.size(); i++){
        pos = i;
        while((pos>0) && v[pos] < v[pos-1]){
            swap(v[pos], v[pos-1]);
            pos--;
        }
    }
}

// ejercicio 10

vector<int> merge(const vector<int> & v1, const vector<int> & v2){
    int i = 0;
    int j = 0;
    vector<int> res;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            res.push_back(v1[i]);
            i++;
        }
        else{
            res.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size()){
        res.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        res.push_back(v2[j]);
        j++;
    }
    return res;
}

int merge2(const vector<int> & v1, const vector<int> & v2){
    int res = 0;
    int k = v1.size()-1;
    int x = v2.size()-1;
    for(int i=0; i<v1.size(); i++){
        for(int j=0; j<v2.size(); j++){
            if(v1[i] > v2[j]){
                res++;
            }
        }
    }
    while((k>0) && v1[k] < v1[k-1]){
        res++;
        k--;
    }
    while((x>0) && v2[x] < v2[x-1]){
        res++;
        x--;
    }
    return res;
}

vector<int> mergesort(const vector<int> & v, int i, int j){
    if(j-i == 0){
        return {};
    }
    if (j-i == 1){
        return {v[i]};
    }
    int med = (i+j)/2;
    vector<int> izq = mergesort(v, i, med);
    vector<int> der = mergesort(v, med, j);

    return merge(izq, der);
}

int mergesort2(const vector<int> & v, int i, int j){
    if(j-i == 0){
        return 0;
    }
    if (j-i == 1){
        return 0;
    }
    int med = (i+j)/2;
    vector<int> izq = mergesort(v, i, med);
    vector<int> der = mergesort(v, med, j);

    return merge2(izq, der);
}




int main(){
    int a = 8;
    int b = 67;
    int n = 2;
    int m = 10;
    vector<int> ms = {12,10,8,5,3,1};
    vector<int> inver = {12,10,8,5,3,1};
    vector<int> ms2 = {1,3,12};
    vector<int> ms3 = {5,8,10};
    vector<int> h = {59,7,388,41,2,280,50,123};
    vector<int> hp = {5,3,6,1,7,9};
    vector<int> hpv = {5,3,6,2,7,9,1};
    vector<int> v = {1,1,1,0,1};
    vector<int> p = {0,1,2,1};
    vector<int> vr = solo_positivos(p);
    vector<string> d = {"hola", "cha", "hola", "hola", "hola", "hola"};
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
    // c)
    cout << "cantidad de coincidencias: " << contar_coincidencias(v) << endl;
    // d)
    cout << "vector positivo : " << endl;
    for(int i=0; i<vr.size(); i++){
        cout << "posicion " << i << " valor: " << vr[i] << endl;
    }
    // e)
    //ejercicio 3
    // a)
    cout << "cantidad de ocurrencias d&c: " << cantidad_de_ocurrencias(s, d, 0, 6) << endl;
    // b)
    // ejercicio 4
    // a)
    cout << "resultado de elevar n por m: " << potencia(n, m) << endl;
    // b)
    cout << "vector montania (pico): " << vector_montania(p, 0, 4) << endl;


    insertion_sort(h);
    cout<<"insertion Sorted Array :" << endl;
    for(int z = 0; z<h.size(); z++){
        cout<< h.at(z) << "; "<< endl;
    }

    selection_sort(hp);
    cout<<"selection Sorted Array :" << endl;
    for(int z = 0; z<hp.size(); z++){
        cout<< hp.at(z) << "; "<< endl;
    }

    mergesort(ms, 0, 6);
    cout<<"merge Sorted Array :" << endl;
    for(int z = 0; z<ms.size(); z++){
        cout<< ms.at(z) << "; "<< endl;
    }
    //ejercicio 10
    //b
    cout << "inversiones " << merge2(ms2, ms3) << endl;
    cout << "inversiones " << mergesort2(inver, 0, 6) << endl;
    


}