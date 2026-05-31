#include "Grafo.h"

Grafo::Grafo() {

    for (int i = 0; i < MAX; i++) {

        for (int j = 0; j < MAX; j++) {

            matriz[i][j] = 0;
        }
    }
}

void Grafo::conectar(
    int id1,
    int id2
) {

    if (id1 == id2) {

        cout << "No puede conectarse "
             << "consigo mismo\n";

        return;
    }

    if (matriz[id1][id2] == 1) {

        cout << "Conexion duplicada\n";

        return;
    }

    matriz[id1][id2] = 1;

    matriz[id2][id1] = 1;

    cout << "Conexion creada\n";
}

void Grafo::mostrarConexiones(
    int id
) {

    cout
    << "\nConexiones de "
    << id
    << ":\n";

    bool tiene = false;

    for (int i = 0; i < MAX; i++) {

        if (matriz[id][i] == 1) {

            cout << i << endl;

            tiene = true;
        }
    }

    if (!tiene) {

        cout << "Sin conexiones\n";
    }
}

bool Grafo::estanConectados(
    int id1,
    int id2
) {

    return matriz[id1][id2] == 1;
}

void Grafo::BFS(int inicio) {

    bool visitado[MAX] = {false};

    int cola[MAX];

    int frente = 0;

    int final = 0;

    visitado[inicio] = true;

    cola[final++] = inicio;

    cout << "\nBFS: ";

    while (frente < final) {

        int actual = cola[frente++];

        cout << actual << " ";

        for (int i = 0; i < MAX; i++) {

            if (matriz[actual][i] == 1
                && !visitado[i]) {

                visitado[i] = true;

                cola[final++] = i;
            }
        }
    }

    cout << endl;
}

void Grafo::DFSRecursivo(
    int nodo,
    bool visitado[]
) {

    visitado[nodo] = true;

    cout << nodo << " ";

    for (int i = 0; i < MAX; i++) {

        if (matriz[nodo][i] == 1
            && !visitado[i]) {

            DFSRecursivo(i, visitado);
        }
    }
}

void Grafo::DFS(int inicio) {

    bool visitado[MAX] = {false};

    cout << "\nDFS: ";

    DFSRecursivo(
        inicio,
        visitado
    );

    cout << endl;
}

void Grafo::eliminarConexiones(
    int id
) {

    for (int i = 0; i < MAX; i++) {

        matriz[id][i] = 0;

        matriz[i][id] = 0;
    }

    cout
    << "Conexiones eliminadas\n";
}