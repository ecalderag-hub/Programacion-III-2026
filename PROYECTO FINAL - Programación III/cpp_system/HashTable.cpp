#include "HashTable.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

HashTable::HashTable() {

    for (int i = 0; i < SIZE; i++) {

        tabla[i] = nullptr;
    }

    totalElementos = 0;
    totalColisiones = 0;
}

int HashTable::funcionHash(int id) {

    return id % SIZE;
}

bool HashTable::insertar(Student estudiante) {

    int indice =
    funcionHash(estudiante.student_id);

    if (buscar(estudiante.student_id)
        != nullptr) {

        cout << "ID duplicado\n";

        return false;
    }

    Nodo* nuevo = new Nodo();

    nuevo->estudiante = estudiante;

    nuevo->siguiente = nullptr;

    if (tabla[indice] != nullptr) {

        totalColisiones++;
    }

    nuevo->siguiente = tabla[indice];

    tabla[indice] = nuevo;

    totalElementos++;

    return true;
}

void HashTable::cargarCSV(string archivo) {

    ifstream file(archivo);

    if (!file) {

        cout << "Error al abrir CSV\n";

        return;
    }

    string linea;

    getline(file, linea);

    while (getline(file, linea)) {

        stringstream ss(linea);

        string dato;

        Student estudiante;

        getline(ss, dato, ',');

        estudiante.student_id =
        stoi(dato);

        getline(ss,
                estudiante.full_name,
                ',');

        getline(ss,
                estudiante.career,
                ',');

        getline(ss, dato, ',');

        estudiante.semester =
        stoi(dato);

        getline(ss, dato, ',');

        estudiante.gpa =
        stof(dato);

        getline(ss, dato, ',');

        estudiante.skill_score =
        stoi(dato);

        insertar(estudiante);
    }

    file.close();

    cout << "CSV cargado correctamente\n";
}

Student* HashTable::buscar(int id) {

    int indice = funcionHash(id);

    Nodo* actual = tabla[indice];

    while (actual != nullptr) {

        if (actual->estudiante.student_id
            == id) {

            return &actual->estudiante;
        }

        actual = actual->siguiente;
    }

    return nullptr;
}

bool HashTable::eliminar(int id) {

    int indice = funcionHash(id);

    Nodo* actual = tabla[indice];

    Nodo* anterior = nullptr;

    while (actual != nullptr) {

        if (actual->estudiante.student_id
            == id) {

            if (anterior == nullptr) {

                tabla[indice] =
                actual->siguiente;
            }

            else {

                anterior->siguiente =
                actual->siguiente;
            }

            delete actual;

            totalElementos--;

            return true;
        }

        anterior = actual;

        actual = actual->siguiente;
    }

    return false;
}

void HashTable::mostrarTabla() {

    cout << "\n===== HASH TABLE =====\n";

    for (int i = 0; i < SIZE; i++) {

        cout << "Bucket "
             << i
             << ": ";

        Nodo* actual = tabla[i];

        if (actual == nullptr) {

            cout << "vacio";
        }

        while (actual != nullptr) {

            cout
            << "("
            << actual->estudiante.student_id
            << ", "
            << actual->estudiante.full_name
            << ") -> ";

            actual = actual->siguiente;
        }

        cout << "NULL\n";
    }
}

float HashTable::calcularFactorCarga() {

    return (float)
           totalElementos / SIZE;
}

void HashTable::mostrarEstadisticas() {

    cout
    << "\n===== ESTADISTICAS HASH =====\n";

    cout
    << "Total estudiantes: "
    << totalElementos
    << endl;

    cout
    << "Total colisiones: "
    << totalColisiones
    << endl;

    cout
    << "Factor carga: "
    << calcularFactorCarga()
    << endl;
}