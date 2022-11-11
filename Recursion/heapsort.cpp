#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

// Auxiliares de heap
int padre(int pos) {
  return (pos-1)/2;
}
int hijo_izq(int pos) {
  return 2*pos+1;
}
int hijo_der(int pos) {
  return 2*pos+2;
}

// Auxiliar de bajar: determina el máximo entre tres nodos (pos=padre y sus dos hijos)
int max_hijo(const vector<int>& heap, int pos) {
 int ret = pos;   // default: raiz
 if (hijo_izq(pos) < heap.size() && 
       heap[ret] < heap[hijo_izq(pos)])
         ret = hijo_izq(pos); // elijo izquierdo
 if (hijo_der(pos) < heap.size() && 
       heap[ret] < heap[hijo_der(pos)])
         ret = hijo_der(pos); // elijo derecho
 return ret;
}

/* BAJAR
  Hace descender por el heap al elemento en la ubicación pos
 
  Debe determinar, en cada paso, si el padre es menor que alguno de sus dos hijos,
  y en ese caso intercambiarse con el más grande de los dos hijos, y continuar el descenso.
  En caso de ser mayor que sus hijos, termina el proceso.
*/
void bajar(vector<int>& heap, int pos) {
   int pos_bajar = max_hijo(heap, pos);
   if (pos_bajar != pos) {
     std::swap(heap[pos], heap[pos_bajar]);
     bajar(heap, pos_bajar);
 } 
}

// Convierte vector en heap
void heapify(vector<int>& v) {
    for (int i = padre(v.size()-1); i >= 0; --i)
       bajar(v,i);
}

/* SUBIR
  Hace ascender por el heap al elemento en la ubicación pos

  Debe determinar si el elemento de la ubicación pos es mayor que su padre,
  y en ese caso intercambiarlos y continuar el ascenso.
  En caso contrario, debe detener el proceso.
  Complejidad: O(log n)
*/
void subir(vector<int>& heap, int pos) {
   // ... //
   int pos_subir = max_hijo(heap, pos);
   if(pos_subir < pos){
    swap(heap[pos], heap[pos_subir]);
    subir(heap, pos_subir);
   }
}

// Inserta en un heap, reestableciendo el maximo
void insertar_heap(int n, vector<int> & _heap) {
    _heap.push_back(n);
    subir(_heap,_heap.size()-1);
}

// Quita el máximo y rearma el heap 
void eliminar_maximo(vector<int> & _heap) {
    _heap[0] = _heap[_heap.size()-1];
    _heap.pop_back();
    bajar(_heap,0);
}

// debe usar un heap para ordenar el vector v en O(n log n)
// idea: 
// - meter todos los elementos en un heap  
// - sacar de a uno los maximos y ubicarlos en el vector donde corresponda
void heapsort(vector<int> & v) {
   // ... //
}

int main() {
    vector<int> v = {44, 1 ,55 ,2, 1234, 7, 543, 4321,11};
    heapsort(v);
    for (int i: v) cout << i << " ";
    assert(v == vector<int>({1, 2, 7, 11 , 44 ,55 , 543, 1234, 4321}));
    return 0;
}