#ifndef LISTAPROYECTOS_H
#define LISTAPROYECTOS_H

#include <iostream>
#include <string>

using namespace std;

struct Proyecto {

    int project_id;

    string title;

    string description;

    int completion_year;
};

struct NodoProyecto {

    Proyecto proyecto;

    NodoProyecto* siguiente;
};

class ListaProyectos {

private:

    NodoProyecto* cabeza;

public:

    ListaProyectos();

    void agregarProyecto(
        Proyecto proyecto
    );

    void mostrarProyectos();

    void buscarProyecto(
        int project_id
    );

    void eliminarProyecto(
        int project_id
    );
};

#endif