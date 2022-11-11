#include <iostream>

using namespace std;

// Nodo de un arbol binario
struct nodo {
   int elem;
   nodo *izq, *der;
};

// Descompone N en un arbol de divisores
nodo* descomponer(int N) {
  // Pre: N>1
  nodo * ret = new nodo({N, nullptr, nullptr});

  for(int i = 2; i < N; i++){
    if(N % i == 0){
      ret->izq = descomponer(i);
      ret->der = descomponer(N/i);
      return ret;
    }
  }
  return ret;
  //// COMPLETAR ////
}

void mostrar_inorder(nodo* n) {
    if (n == nullptr) return;

    mostrar_inorder(n->izq);
    std::cout << n->elem << " ";
    mostrar_inorder(n->der);
}

void destruir(nodo* n) {
    if (n == nullptr) return;
    destruir(n->izq);
    destruir(n->der);
    delete n;
}

  int main() {
      nodo* raiz = descomponer(2310);
      cout << "inorder: ";
      mostrar_inorder(raiz);
      destruir(raiz);
  }

