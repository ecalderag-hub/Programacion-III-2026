#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>

using namespace std;

class Grafo {

private:

    static const int MAX = 100;

    int matriz[MAX][MAX];

public:

    Grafo();

    void conectar(int id1, int id2);

    void mostrarConexiones(int id);

    bool estanConectados(int id1, int id2);

    void BFS(int inicio);

    void DFS(int inicio);

    void DFSRecursivo(
        int nodo,
        bool visitado[]
    );
    void eliminarConexiones(int id);
};

#endif