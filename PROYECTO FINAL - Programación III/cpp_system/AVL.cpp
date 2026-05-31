#include "AVL.h"
#include <iostream>

using namespace std;

AVL::AVL() {

    raiz = nullptr;
    totalNodos = 0;

}

int AVL::obtenerAltura(Nodo* nodo) {

    if (nodo == nullptr)
        return 0;

    return nodo->altura;
}

int AVL::obtenerBalance(Nodo* nodo) {

    if (nodo == nullptr)
        return 0;

    return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
}

AVL::Nodo* AVL::rotacionDerecha(Nodo* y) {

    Nodo* x = y->izquierda;
    Nodo* T2 = x->derecha;

    x->derecha = y;
    y->izquierda = T2;

    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;

    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;

    return x;
}

AVL::Nodo* AVL::rotacionIzquierda(Nodo* x) {

    Nodo* y = x->derecha;
    Nodo* T2 = y->izquierda;

    y->izquierda = x;
    x->derecha = T2;

    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;

    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;

    return y;
}

AVL::Nodo* AVL::insertar(Nodo* nodo, Student estudiante) {

    if (nodo == nullptr) {

        Nodo* nuevo = new Nodo();

        nuevo->estudiante = estudiante;

        nuevo->izquierda = nullptr;
        nuevo->derecha = nullptr;

        nuevo->altura = 1;

        totalNodos++;

        return nuevo;
    }

    if (estudiante.skill_score < nodo->estudiante.skill_score)
        nodo->izquierda = insertar(nodo->izquierda, estudiante);

    else if (estudiante.skill_score > nodo->estudiante.skill_score)
        nodo->derecha = insertar(nodo->derecha, estudiante);

    else {

        if (estudiante.student_id < nodo->estudiante.student_id)
            nodo->izquierda = insertar(nodo->izquierda, estudiante);

        else
            nodo->derecha = insertar(nodo->derecha, estudiante);
    }

    nodo->altura = 1 + max(obtenerAltura(nodo->izquierda),
                            obtenerAltura(nodo->derecha));

    int balance = obtenerBalance(nodo);

    if (balance > 1 &&
        estudiante.skill_score < nodo->izquierda->estudiante.skill_score)

        return rotacionDerecha(nodo);

    if (balance < -1 &&
        estudiante.skill_score > nodo->derecha->estudiante.skill_score)

        return rotacionIzquierda(nodo);

    if (balance > 1 &&
        estudiante.skill_score > nodo->izquierda->estudiante.skill_score) {

        nodo->izquierda = rotacionIzquierda(nodo->izquierda);

        return rotacionDerecha(nodo);
    }

    if (balance < -1 &&
        estudiante.skill_score < nodo->derecha->estudiante.skill_score) {

        nodo->derecha = rotacionDerecha(nodo->derecha);

        return rotacionIzquierda(nodo);
    }

    return nodo;
}

void AVL::insertarEstudiante(Student estudiante) {

    raiz = insertar(raiz, estudiante);

}

void AVL::inOrden(Nodo* nodo) {

    if (nodo != nullptr) {

        inOrden(nodo->derecha);

        cout << nodo->estudiante.full_name
             << " - Score: "
             << nodo->estudiante.skill_score
             << endl;

        inOrden(nodo->izquierda);
    }
}

void AVL::mostrarRanking() {

    cout << "\n===== RANKING ACADEMICO =====\n";

    inOrden(raiz);
}

AVL::Nodo* AVL::buscar(Nodo* nodo, int skill_score) {

    if (nodo == nullptr)
        return nullptr;

    if (skill_score == nodo->estudiante.skill_score)
        return nodo;

    if (skill_score < nodo->estudiante.skill_score)
        return buscar(nodo->izquierda, skill_score);

    return buscar(nodo->derecha, skill_score);
}

void AVL::buscarPorScore(int skill_score) {

    Nodo* encontrado = buscar(raiz, skill_score);

    if (encontrado != nullptr) {

        cout << "\nEstudiante encontrado:\n";

        cout << "Nombre: "
             << encontrado->estudiante.full_name
             << endl;

        cout << "Skill Score: "
             << encontrado->estudiante.skill_score
             << endl;
    }

    else {

        cout<< "\nNo existe estudiante con ese score.\n";
    }
}

void AVL::mostrarEstadisticas() {

    cout<< "\n===== ESTADISTICAS AVL =====\n";

    cout << "Altura del arbol: "
         << obtenerAltura(raiz)
         <<endl;

    cout << "Factor de balance raiz: "
         << obtenerBalance(raiz)
         << endl;

    cout << "Cantidad de nodos: "
         << totalNodos
         << endl;
}

AVL::Nodo* AVL::eliminar(
    Nodo* nodo,
    int skill_score
) {

    if (nodo == nullptr)
        return nodo;

    if (skill_score < nodo->estudiante.skill_score) {

        nodo->izquierda =
        eliminar(
            nodo->izquierda,
            skill_score
        );
    }

    else if (skill_score > nodo->estudiante.skill_score) {

        nodo->derecha =
        eliminar(
            nodo->derecha,
            skill_score
        );
    }

    else {

        if (nodo->izquierda == nullptr) {

            Nodo* temp =
            nodo->derecha;

            delete nodo;

            return temp;
        }

        else if (nodo->derecha == nullptr) {

            Nodo* temp =
            nodo->izquierda;

            delete nodo;

            return temp;
        }
    }

    return nodo;
}

void AVL::eliminarEstudiante(
    int skill_score
) {

    raiz = eliminar(
        raiz,
        skill_score
    );

    cout
    << "Estudiante eliminado del AVL\n";
}