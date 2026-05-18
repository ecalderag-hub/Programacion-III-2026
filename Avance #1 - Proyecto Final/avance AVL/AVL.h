#ifndef AVL_H
#define AVL_H

#include "Student.h"

class AVL {

private:

    struct Nodo {

        Student estudiante;

        Nodo* izquierda;
        Nodo* derecha;

        int altura;

    };

    Nodo* raiz;
    int totalNodos;

    int obtenerAltura(Nodo* nodo);

    int obtenerBalance(Nodo* nodo);

    Nodo* rotacionDerecha(Nodo* y);

    Nodo* rotacionIzquierda(Nodo* x);

    Nodo* insertar(Nodo* nodo, Student estudiante);

    void inOrden(Nodo* nodo);

    Nodo* buscar(Nodo* nodo, int skill_score);

public:

    AVL();

    void insertarEstudiante(Student estudiante);

    void mostrarRanking();

    void buscarPorScore(int skill_score);

    void mostrarEstadisticas();

};

#endif