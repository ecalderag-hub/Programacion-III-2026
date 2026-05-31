#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <string>

using namespace std;

struct Nodo {

    string accion;

    Nodo* siguiente;
};

class Pila {

private:

    Nodo* tope;

public:

    Pila();

    void push(string accion);

    void pop();

    void peek();

    void mostrar();
};

#endif