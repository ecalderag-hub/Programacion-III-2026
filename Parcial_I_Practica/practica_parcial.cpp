#include <iostream>
using namespace std;
// Definición de la estructura Nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main(){

//PRIMER NODO
Nodo* primero = new Nodo;
cout << "Ingrese el valor del primer nodo: ";
cin >> primero->dato;

primero->siguiente = nullptr;

//SEGUNDO NODO
Nodo* segundo = new Nodo;
cout << "Ingrese el valor del segundo nodo: ";
cin >> segundo->dato;

segundo->siguiente = nullptr;
primero->siguiente = segundo;

//TERCER NODO
Nodo* tercero = new Nodo;
cout << "Ingrese el valor del tercer nodo: ";
cin >> tercero->dato;

tercero->siguiente = nullptr;
segundo->siguiente = tercero;

cout << "--------------------------" << endl;

// Mostrar nombre del estudiante
cout << "Nombre: ERICKA DANIELA CALDERA GOMEZ" << endl << endl;

// Mostrar los valores usando punteros
cout << "\nValores almacenados en los nodos:" << endl;
//imprimir
Nodo* actual = primero;
while (actual != nullptr) {
    cout << actual->dato << endl;
    
    actual = actual->siguiente;
}

//Liberar memoria
actual = primero;
while (actual != nullptr) {
    Nodo* temp = actual;
    actual = actual->siguiente;
    delete temp;
}
primero = nullptr;

return 0;
}
