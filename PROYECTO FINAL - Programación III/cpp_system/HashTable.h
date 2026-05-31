#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Student.h"

#include <string>

using namespace std;

class HashTable {

private:

    struct Nodo {

        Student estudiante;

        Nodo* siguiente;
    };

    static const int SIZE = 10;

    Nodo* tabla[SIZE];

    int totalElementos;

    int totalColisiones;

    int funcionHash(int id);

public:

    HashTable();

    bool insertar(Student estudiante);

    Student* buscar(int id);

    bool eliminar(int id);

    void cargarCSV(string archivo);

    void mostrarTabla();

    float calcularFactorCarga();

    void mostrarEstadisticas();

};

#endif