#include "ListaProyectos.h"

ListaProyectos::ListaProyectos() {

    cabeza = NULL;
}

void ListaProyectos::agregarProyecto(
    Proyecto proyecto
) {

    NodoProyecto* actual = cabeza;

    while (actual != NULL) {

        if (actual->proyecto.project_id
            == proyecto.project_id) {

            cout
            << "Proyecto duplicado\n";

            return;
        }

        actual = actual->siguiente;
    }

    NodoProyecto* nuevo =
    new NodoProyecto();

    nuevo->proyecto = proyecto;

    nuevo->siguiente = cabeza;

    cabeza = nuevo;

    cout
    << "Proyecto agregado\n";
}

void ListaProyectos::mostrarProyectos() {

    if (cabeza == NULL) {

        cout
        << "No hay proyectos\n";

        return;
    }

    NodoProyecto* actual = cabeza;

    cout
    << "\n===== PROYECTOS =====\n";

    while (actual != NULL) {

        cout
        << "ID: "
        << actual->proyecto.project_id
        << endl;

        cout
        << "Titulo: "
        << actual->proyecto.title
        << endl;

        cout
        << "Descripcion: "
        << actual->proyecto.description
        << endl;

        cout
        << "Anio: "
        << actual->proyecto.completion_year
        << endl;

        cout
        << "-------------------\n";

        actual = actual->siguiente;
    }
}

void ListaProyectos::buscarProyecto(
    int project_id
) {

    NodoProyecto* actual = cabeza;

    while (actual != NULL) {

        if (actual->proyecto.project_id
            == project_id) {

            cout
            << "\nProyecto encontrado\n";

            cout
            << "Titulo: "
            << actual->proyecto.title
            << endl;

            return;
        }

        actual = actual->siguiente;
    }

    cout
    << "Proyecto no encontrado\n";
}

void ListaProyectos::eliminarProyecto(
    int project_id
) {

    NodoProyecto* actual = cabeza;

    NodoProyecto* anterior = NULL;

    while (actual != NULL) {

        if (actual->proyecto.project_id
            == project_id) {

            if (anterior == NULL) {

                cabeza =
                actual->siguiente;
            }

            else {

                anterior->siguiente =
                actual->siguiente;
            }

            delete actual;

            cout
            << "Proyecto eliminado\n";

            return;
        }

        anterior = actual;

        actual = actual->siguiente;
    }

    cout
    << "Proyecto no encontrado\n";
}