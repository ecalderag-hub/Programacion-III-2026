#include <iostream>
#include <cstring>
using namespace std;

// STRUCTS DE NODOS

struct NodoSimple {
    int dato;
    NodoSimple* siguiente;
};

struct NodoPila {
    int dato;
    NodoPila* siguiente;
};

struct NodoCola {
    int dato;
    NodoCola* siguiente;
};

struct NodoDoble {
    int valor;
    char tipo[30];
    int orden;
    NodoDoble* anterior;
    NodoDoble* siguiente;
};

struct NodoBST {
    int dato;
    NodoBST* izquierdo;
    NodoBST* derecho;
};


// VARIABLES GLOBALES

NodoPila* tope = NULL;

NodoCola* frente = NULL;
NodoCola* finalCola = NULL;

NodoSimple* listaNegativos = NULL;

NodoDoble* historialInicio = NULL;
NodoDoble* historialFinal = NULL;

NodoBST* raizBST = NULL;

NodoSimple* listaAuxPila = NULL;
NodoSimple* listaAuxCola = NULL;

int contadorPares = 0;
int contadorImpares = 0;
int contadorNegativos = 0;
int contadorCeros = 0;
int totalValidos = 0;
int ordenIngreso = 0;

int mayorValor = 0;
int menorValor = 0;
bool hayValoresValidos = false;


// FUNCIONES DE PILA

void insertarPila(int valor) {
    NodoPila* nuevo = new NodoPila();
    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;
}

bool sacarPila(int &valor) {
    if (tope == NULL) {
        return false;
    }

    NodoPila* temp = tope;
    valor = temp->dato;
    tope = tope->siguiente;
    delete temp;

    return true;
}

void mostrarPila() {
    if (tope == NULL) {
        cout << "\nLa pila esta vacia.\n";
        return;
    }

    NodoPila* actual = tope;

    cout << "\nContenido de la PILA:\n";
    while (actual != NULL) {
        cout << actual->dato << endl;
        actual = actual->siguiente;
    }
}


// FUNCIONES DE COLA

void insertarCola(int valor) {
    NodoCola* nuevo = new NodoCola();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (frente == NULL) {
        frente = nuevo;
        finalCola = nuevo;
    } else {
        finalCola->siguiente = nuevo;
        finalCola = nuevo;
    }
}

bool sacarCola(int &valor) {
    if (frente == NULL) {
        return false;
    }

    NodoCola* temp = frente;
    valor = temp->dato;
    frente = frente->siguiente;

    if (frente == NULL) {
        finalCola = NULL;
    }

    delete temp;
    return true;
}

void mostrarCola() {
    if (frente == NULL) {
        cout << "\nLa cola esta vacia.\n";
        return;
    }

    NodoCola* actual = frente;

    cout << "\nContenido de la COLA:\n";
    while (actual != NULL) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }

    cout << endl;
}


// LISTA SIMPLE

void insertarListaSimple(NodoSimple* &inicio, int valor) {
    NodoSimple* nuevo = new NodoSimple();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (inicio == NULL) {
        inicio = nuevo;
    } else {
        NodoSimple* actual = inicio;

        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevo;
    }
}

void mostrarListaSimple(NodoSimple* inicio, const char nombre[]) {
    if (inicio == NULL) {
        cout << "\n" << nombre << " esta vacia.\n";
        return;
    }

    NodoSimple* actual = inicio;

    cout << "\n" << nombre << ":\n";
    while (actual != NULL) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }

    cout << endl;
}

int eliminarNegativosMenoresA10() {
    int eliminados = 0;

    while (listaNegativos != NULL && listaNegativos->dato > -10 && listaNegativos->dato < 0) {
        NodoSimple* temp = listaNegativos;
        listaNegativos = listaNegativos->siguiente;
        delete temp;
        eliminados++;
    }

    NodoSimple* actual = listaNegativos;

    while (actual != NULL && actual->siguiente != NULL) {
        if (actual->siguiente->dato > -10 && actual->siguiente->dato < 0) {
            NodoSimple* temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            delete temp;
            eliminados++;
        } else {
            actual = actual->siguiente;
        }
    }

    return eliminados;
}


// LISTA DOBLEMENTE ENLAZADA

void insertarHistorial(int valor, const char tipo[]) {
    NodoDoble* nuevo = new NodoDoble();

    nuevo->valor = valor;
    strcpy(nuevo->tipo, tipo);
    nuevo->orden = ordenIngreso;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    if (historialInicio == NULL) {
        historialInicio = nuevo;
        historialFinal = nuevo;
    } else {
        historialFinal->siguiente = nuevo;
        nuevo->anterior = historialFinal;
        historialFinal = nuevo;
    }
}

void mostrarHistorial() {
    if (historialInicio == NULL) {
        cout << "\nEl historial esta vacio.\n";
        return;
    }

    NodoDoble* actual = historialInicio;

    cout << "\nHISTORIAL DE VALORES VALIDOS:\n";
    cout << "Orden\tValor\tEstructura\n";

    while (actual != NULL) {
        cout << actual->orden << "\t" << actual->valor << "\t" << actual->tipo << endl;
        actual = actual->siguiente;
    }
}


// ARBOL BST

NodoBST* crearNodoBST(int valor) {
    NodoBST* nuevo = new NodoBST();
    nuevo->dato = valor;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    return nuevo;
}

NodoBST* insertarBST(NodoBST* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodoBST(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierdo = insertarBST(raiz->izquierdo, valor);
    } else {
        raiz->derecho = insertarBST(raiz->derecho, valor);
    }

    return raiz;
}

void inOrden(NodoBST* raiz) {
    if (raiz != NULL) {
        inOrden(raiz->izquierdo);
        cout << raiz->dato << " ";
        inOrden(raiz->derecho);
    }
}

void preOrden(NodoBST* raiz) {
    if (raiz != NULL) {
        cout << raiz->dato << " ";
        preOrden(raiz->izquierdo);
        preOrden(raiz->derecho);
    }
}

void postOrden(NodoBST* raiz) {
    if (raiz != NULL) {
        postOrden(raiz->izquierdo);
        postOrden(raiz->derecho);
        cout << raiz->dato << " ";
    }
}

bool buscarBST(NodoBST* raiz, int valor) {
    if (raiz == NULL) {
        return false;
    }

    if (valor == raiz->dato) {
        return true;
    }

    if (valor < raiz->dato) {
        return buscarBST(raiz->izquierdo, valor);
    } else {
        return buscarBST(raiz->derecho, valor);
    }
}

void liberarBST(NodoBST* &raiz) {
    if (raiz != NULL) {
        liberarBST(raiz->izquierdo);
        liberarBST(raiz->derecho);
        delete raiz;
        raiz = NULL;
    }
}

void construirBSTDesdeHistorial() {
    liberarBST(raizBST);

    NodoDoble* actual = historialInicio;

    while (actual != NULL) {
        if (actual->valor > 0) {
            raizBST = insertarBST(raizBST, actual->valor);
        }

        actual = actual->siguiente;
    }

    if (raizBST == NULL) {
        cout << "\nNo hay numeros positivos para construir el BST.\n";
        return;
    }

    cout << "\nARBOL BST CONSTRUIDO CORRECTAMENTE.\n";

    cout << "\nRecorrido InOrden: ";
    inOrden(raizBST);

    cout << "\nRecorrido PreOrden: ";
    preOrden(raizBST);

    cout << "\nRecorrido PostOrden: ";
    postOrden(raizBST);

    cout << endl;
}


// ESTADISTICAS

void actualizarMayorMenor(int valor) {
    if (hayValoresValidos == false) {
        mayorValor = valor;
        menorValor = valor;
        hayValoresValidos = true;
    } else {
        if (valor > mayorValor) {
            mayorValor = valor;
        }

        if (valor < menorValor) {
            menorValor = valor;
        }
    }
}

void mostrarEstadisticas() {
    cout << "\nESTADISTICAS DEL SISTEMA\n";
    cout << "Pares positivos: " << contadorPares << endl;
    cout << "Impares positivos: " << contadorImpares << endl;
    cout << "Negativos: " << contadorNegativos << endl;
    cout << "Ceros rechazados: " << contadorCeros << endl;
    cout << "Total de valores validos: " << totalValidos << endl;

    if (hayValoresValidos == true) {
        cout << "Mayor valor ingresado: " << mayorValor << endl;
        cout << "Menor valor ingresado: " << menorValor << endl;
    } else {
        cout << "No hay valores validos ingresados.\n";
    }
}


// INGRESO Y CLASIFICACION


void ingresarNumeros() {
    int n;
    int valor;

    cout << "\n Numeros a ingresar: ";
    cin >> n;

    while (n <= 0) {
        cout << "Error. N debe ser mayor que 0: ";
        cin >> n;
    }

    for (int i = 1; i <= n; i++) {
        cout << "Ingrese el numero " << i << ": ";
        cin >> valor;

        if (valor == 0) {
            contadorCeros++;
            cout << "El cero no se almacena. Intento invalido registrado.\n";
        } else {
            ordenIngreso++;
            totalValidos++;
            actualizarMayorMenor(valor);

            if (valor > 0 && valor % 2 == 0) {
                insertarCola(valor);
                insertarHistorial(valor, "COLA");
                contadorPares++;
                cout << "Numero par positivo enviado a COLA.\n";
            } else if (valor > 0 && valor % 2 != 0) {
                insertarPila(valor);
                insertarHistorial(valor, "PILA");
                contadorImpares++;
                cout << "Numero impar positivo enviado a PILA.\n";
            } else if (valor < 0) {
                insertarListaSimple(listaNegativos, valor);
                insertarHistorial(valor, "LISTA SIMPLE");
                contadorNegativos++;
                cout << "Numero negativo enviado a LISTA SIMPLE.\n";
            }
        }
    }
}


// REORGANIZACION


void liberarListaSimple(NodoSimple* &inicio) {
    while (inicio != NULL) {
        NodoSimple* temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
    }
}

void reconstruirBSTDesdeAuxiliares() {
    liberarBST(raizBST);

    NodoSimple* actual = listaAuxPila;

    while (actual != NULL) {
        raizBST = insertarBST(raizBST, actual->dato);
        actual = actual->siguiente;
    }

    actual = listaAuxCola;

    while (actual != NULL) {
        raizBST = insertarBST(raizBST, actual->dato);
        actual = actual->siguiente;
    }
}

void reorganizarEstructuras() {
    int valor;

    liberarListaSimple(listaAuxPila);
    liberarListaSimple(listaAuxCola);

    while (sacarPila(valor)) {
        insertarListaSimple(listaAuxPila, valor);
    }

    while (sacarCola(valor)) {
        insertarListaSimple(listaAuxCola, valor);
    }

    cout << "\nLa pila fue vaciada hacia una lista auxiliar.\n";
    cout << "La cola fue vaciada hacia otra lista auxiliar.\n";

    mostrarListaSimple(listaAuxPila, "LISTA AUXILIAR DE PILA");
    mostrarListaSimple(listaAuxCola, "LISTA AUXILIAR DE COLA");

    reconstruirBSTDesdeAuxiliares();

    if (raizBST == NULL) {
        cout << "\nNo se pudo reconstruir el BST porque no hay datos positivos.\n";
    } else {
        cout << "\nBST reconstruido con los datos reorganizados.\n";

        cout << "\nInOrden: ";
        inOrden(raizBST);

        cout << "\nPreOrden: ";
        preOrden(raizBST);

        cout << "\nPostOrden: ";
        postOrden(raizBST);

        cout << endl;
    }
}


// LIBERACION DE MEMORIA


void liberarPila() {
    int valor;
    while (sacarPila(valor)) {
    }
}

void liberarCola() {
    int valor;
    while (sacarCola(valor)) {
    }
}

void liberarHistorial() {
    while (historialInicio != NULL) {
        NodoDoble* temp = historialInicio;
        historialInicio = historialInicio->siguiente;
        delete temp;
    }

    historialFinal = NULL;
}

void liberarTodaLaMemoria() {
    liberarPila();
    liberarCola();
    liberarListaSimple(listaNegativos);
    liberarListaSimple(listaAuxPila);
    liberarListaSimple(listaAuxCola);
    liberarHistorial();
    liberarBST(raizBST);
}


// BUSCAR EN BST


void buscarValorEnBST() {
    if (raizBST == NULL) {
        cout << "\nEl BST esta vacio. Primero debe construirlo.\n";
        return;
    }

    int valor;

    cout << "\nIngrese el valor que desea buscar en el BST: ";
    cin >> valor;

    if (buscarBST(raizBST, valor)) {
        cout << "El valor " << valor << " SI existe en el BST.\n";
    } else {
        cout << "El valor " << valor << " NO existe en el BST.\n";
    }
}


// MENU


void mostrarMenu() {
    cout << "\n=====================================\n";
    cout << " Nombre: ERICKA DANIELA CALDERA GOMEZ\n";
    cout << "=====================================\n";
    cout << " ----------------MENU-----------------\n";
    cout << "1. Ingresar N numeros\n";
    cout << "2. Mostrar pila\n";
    cout << "3. Mostrar cola\n";
    cout << "4. Mostrar lista de negativos\n";
    cout << "5. Mostrar historial lista doble\n";
    cout << "6. Construir y mostrar BST\n";
    cout << "7. Eliminar negativos con magnitud menor que 10\n";
    cout << "8. Buscar un valor en el BST\n";
    cout << "9. Mostrar estadisticas\n";
    cout << "10. Reorganizar estructuras\n";
    cout << "11. Salir\n";
    cout << "Seleccione una opcion: ";
}


// MAIN


int main() {
    int opcion;
    bool salir = false;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarNumeros();
                break;

            case 2:
                mostrarPila();
                break;

            case 3:
                mostrarCola();
                break;

            case 4:
                mostrarListaSimple(listaNegativos, "LISTA DE NEGATIVOS");
                break;

            case 5:
                mostrarHistorial();
                break;

            case 6:
                construirBSTDesdeHistorial();
                break;

            case 7: {
                cout << "\nLista original de negativos:";
                mostrarListaSimple(listaNegativos, "LISTA DE NEGATIVOS");

                int eliminados = eliminarNegativosMenoresA10();

                cout << "\nLista resultante:";
                mostrarListaSimple(listaNegativos, "LISTA DE NEGATIVOS");

                cout << "\nCantidad de nodos eliminados: " << eliminados << endl;
                break;
            }

            case 8:
                buscarValorEnBST();
                break;

            case 9:
                mostrarEstadisticas();
                break;

            case 10:
                reorganizarEstructuras();
                break;

            case 11:
                cout << "\nLiberando memoria dinamica...\n";
                liberarTodaLaMemoria();
                cout << "Memoria liberada correctamente.\n";
                cout << "Programa finalizado.\n";
                salir = true;
                break;

            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                break;
        }

    } while (salir == false);

    return 0;
}
