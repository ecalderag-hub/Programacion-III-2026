#include <iostream>
#include <fstream>
#include <chrono>

#include "HashTable.h"
#include "AVL.h"

using namespace std;
using namespace chrono;

int main() {

    HashTable hash;

    AVL arbol;

    ofstream archivo(
        "cpp_results.csv"
    );

    archivo
    << "language,operation,"
    << "structure,records,time_ms\n";

    // =========================
    // HASH INSERT
    // =========================

    auto inicioHash =
    high_resolution_clock::now();

    for (int i = 0; i < 10000; i++) {

        Student estudiante;

        estudiante.student_id = i;

        estudiante.full_name =
        "Estudiante";

        estudiante.career =
        "Ingenieria";

        estudiante.semester = 1;

        estudiante.gpa = 85;

        estudiante.skill_score = i;

        hash.insertar(estudiante);
    }

    auto finHash =
    high_resolution_clock::now();

    duration<double, milli>
    tiempoHash =
    finHash - inicioHash;

    archivo
    << "C++,insert,HashTable,"
    << "10000,"
    << tiempoHash.count()
    << endl;

    // =========================
    // HASH SEARCH
    // =========================

    auto inicioBusquedaHash =
    high_resolution_clock::now();

    for (int i = 0; i < 10000; i++) {

        hash.buscar(i);
    }

    auto finBusquedaHash =
    high_resolution_clock::now();

    duration<double, milli>
    tiempoBusquedaHash =
    finBusquedaHash
    - inicioBusquedaHash;

    archivo
    << "C++,search,HashTable,"
    << "10000,"
    << tiempoBusquedaHash.count()
    << endl;

    // =========================
    // AVL INSERT
    // =========================

    auto inicioAVL =
    high_resolution_clock::now();

    for (int i = 0; i < 10000; i++) {

        Student estudiante;

        estudiante.student_id = i;

        estudiante.full_name =
        "Estudiante";

        estudiante.career =
        "Ingenieria";

        estudiante.semester = 1;

        estudiante.gpa = 85;

        estudiante.skill_score = i;

        arbol.insertarEstudiante(
            estudiante
        );
    }

    auto finAVL =
    high_resolution_clock::now();

    duration<double, milli>
    tiempoAVL =
    finAVL - inicioAVL;

    archivo
    << "C++,insert,AVL,"
    << "10000,"
    << tiempoAVL.count()
    << endl;

    archivo.close();

    cout
    << "Benchmark generado "
    << "correctamente\n";

    return 0;
}