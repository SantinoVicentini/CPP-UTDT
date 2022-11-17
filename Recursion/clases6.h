#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>

using namespace std;

class Fecha{
    public:
        Fecha(int dia, int mes, int anio);
        void avanzar_dia();
        void avanzar_n_dias(int n);
        int dia() const;
        int mes() const;
        int anio() const;
        bool operator == (const Fecha & f) const;
    private:
        int dia;
        int mes;
        int anio;
};

class Usuario{
    public:
        Usuario(string nombre, int edad);
        string nombre() const;
        int edad() const;
        void agregar_amigo(string nombre);
        bool es_amigo(string nombre) const;
        bool es_popular() const;
        // Un usuario se considera popular si tiene más de 10 amigos.
    private:
        string nombre;
        int edad;
        set<string> amigos;
        bool es_popular;
};

class Multiconjunto{
    public:
        Multiconjunto();
        void agregar(int e);
        void quitar(int e);
        int contar_apariciones(int e) const;
        int cardinal() const;
        int cantidad_elementos_distintos() const;
    private:
        int cantidad_distintos;
        vector<int> elementos;
};

class Carrito{
    public:
        Carrito(int peso_maximo);
        int peso_disponible() const;
        float monto_total() const;
        void agregar_item(string nombre, int peso, float precio);
        void borrar_item(string nombre);
        bool buscar_item(string nombre) const;
        int peso_de_item(string nombre) const;
        int precio_de_item(string nombre) const;
    private:
        int peso_maximo;
        vector<string> items;
        map<string, int> pesos_items;
        map<string, float> precios_por_item;
};


