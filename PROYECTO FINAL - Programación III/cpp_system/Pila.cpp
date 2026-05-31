#include "Pila.h"

Pila::Pila() {

    tope = NULL;
}

void Pila::push(string accion) {

    Nodo* nuevo = new Nodo();

    nuevo->accion = accion;

    nuevo->siguiente = tope;

    tope = nuevo;

    cout << "Accion agregada al historial.\n";
}

void Pila::pop() {

    if (tope == NULL) {

        cout << "La pila esta vacia.\n";

        return;
    }

    Nodo* temp = tope;

    cout << "Ultima accion eliminada: "
         << temp->accion
         << endl;

    tope = tope->siguiente;

    delete temp;
}

void Pila::peek() {

    if (tope == NULL) {

        cout << "La pila esta vacia.\n";
    }

    else {

        cout << "Ultima accion: "
             << tope->accion
             << endl;
    }
}

void Pila::mostrar() {

    if (tope == NULL) {

        cout << "Historial vacio.\n";

        return;
    }

    Nodo* actual = tope;

    cout << "\n===== HISTORIAL =====\n";

    while (actual != NULL) {

        cout << actual->accion
             << endl;

        actual = actual->siguiente;
    }
}