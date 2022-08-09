#include <iostream>
using namespace std;

float evaluar(float a, char op, float b){
    switch (op){

    case '+':
        a = a+b;
        break;
    case '-':
        a = a-b;
        break;
    case '/':
        a = a/b;
        break;
    case '*':
        a = a*b;
        break;
    }
    return a;
}

int main(){
    float a,b;
    char op;
    cout << "introduzca una expresion matematica" << endl;
    cin >> a >> op >> b ;
    cout << "la expresion tiene el valor: " << evaluar(a, op, b) << endl;

    return 0;
}







