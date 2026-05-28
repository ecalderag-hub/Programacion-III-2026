#include <iostream>

#include "Student.h"

#include "AVL.h"
#include "HashTable.h"
#include "Pila.h"
#include "Grafo.h"
#include "ListaProyectos.h"

using namespace std;

int main() {

    //NOMBRE DEL ESTUDIANTE
    cout << "Nombre: ERICKA DANIELA CALDERA GOMEZ\n";
    cout << "Carne: 9941 - 24 - 8190\n";

    HashTable hash;

    AVL arbol;

    Grafo grafo;

    Pila historial;

    ListaProyectos proyectos;

    int opcion;

    do {

        cout << "\n========== RED SOCIAL ACADEMICA ==========\n";

        cout << "1. Cargar estudiantes desde CSV\n";
        cout << "2. Registrar estudiante manualmente\n";
        cout << "3. Buscar estudiante por ID\n";
        cout << "4. Eliminar estudiante\n";
        cout << "5. Agregar proyecto\n";
        cout << "6. Mostrar proyectos\n";
        cout << "7. Conectar estudiantes\n";
        cout << "8. Verificar conexiones\n";
        cout << "9. Mostrar conexiones\n";
        cout << "10. BFS\n";
        cout << "11. DFS\n";
        cout << "12. Mostrar ranking\n";
        cout << "13. Mostrar estadisticas\n";
        cout << "14. Mostrar historial\n";
        cout << "15. Salir\n";

        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1: {

            hash.cargarCSV("estudiantes.csv");


            break;
        }

        case 2: {

            Student estudiante;

            cout << "ID: ";
            cin >> estudiante.student_id;

            cin.ignore();

            cout << "Nombre: ";
            getline(cin, estudiante.full_name);

            cout << "Carrera: ";
            getline(cin, estudiante.career);

            cout << "Semestre: ";
            cin >> estudiante.semester;

            cout << "GPA: ";
            cin >> estudiante.gpa;

            cout << "Skill Score: ";
            cin >> estudiante.skill_score;

            if (hash.buscar(estudiante.student_id)
                != nullptr) {

                cout << "ID duplicado\n";
            }

            else {

                hash.insertar(estudiante);

                arbol.insertarEstudiante(
                    estudiante
                );

                historial.push(
                    "Se agrego estudiante"
                );

                cout << "Estudiante agregado\n";
            }

            break;
        }

        case 3: {

            int id;

            cout << "Ingrese ID: ";
            cin >> id;

            Student* encontrado =
            hash.buscar(id);

            if (encontrado != nullptr) {

                cout << "\nNombre: "
                     << encontrado->full_name
                     << endl;

                cout << "Carrera: "
                     << encontrado->career
                     << endl;

                cout << "GPA: "
                     << encontrado->gpa
                     << endl;
            }

            else {

                cout << "No encontrado\n";
            }

            break;
        }

        case 4: {

            int id;

            cout << "Ingrese ID: ";
            cin >> id;

            hash.eliminar(id);

            grafo.eliminarConexiones(id);

            historial.push(
                "Se elimino estudiante"
            );

            cout << "Eliminacion realizada\n";

            break;
        }

        case 5: {

            Proyecto proyecto;

            cout << "ID Proyecto: ";
            cin >> proyecto.project_id;

            cin.ignore();

            cout << "Titulo: ";
            getline(cin, proyecto.title);

            cout << "Descripcion: ";
            getline(cin, proyecto.description);

            cout << "Anio: ";
            cin >> proyecto.completion_year;

            proyectos.agregarProyecto(
                proyecto
            );

            historial.push(
                "Se agrego proyecto"
            );

            break;
        }

        case 6: {

            proyectos.mostrarProyectos();

            break;
        }

        case 7: {

            int id1, id2;

            cout << "ID 1: ";
            cin >> id1;

            cout << "ID 2: ";
            cin >> id2;

            grafo.conectar(id1, id2);

            historial.push(
                "Se conectaron estudiantes"
            );

            break;
        }

        case 8: {

            int id1, id2;

            cout << "ID 1: ";
            cin >> id1;

            cout << "ID 2: ";
            cin >> id2;

            if (grafo.estanConectados(
                id1,
                id2
            )) {

                cout << "Si estan conectados\n";
            }

            else {

                cout << "No estan conectados\n";
            }

            break;
        }

        case 9: {

            int id;

            cout << "Ingrese ID: ";
            cin >> id;

            grafo.mostrarConexiones(id);

            break;
        }

        case 10: {

            int id;

            cout << "Nodo inicio BFS: ";
            cin >> id;

            grafo.BFS(id);

            break;
        }

        case 11: {

            int id;

            cout << "Nodo inicio DFS: ";
            cin >> id;

            grafo.DFS(id);

            break;
        }

        case 12: {

            arbol.mostrarRanking();

            break;
        }

        case 13: {

            hash.mostrarEstadisticas();

            arbol.mostrarEstadisticas();

            break;
        }

        case 14: {

            historial.mostrar();

            break;
        }

        case 15: {

            cout << "Saliendo...\n";

            break;
        }

        default:

            cout << "Opcion invalida\n";
        }

    } while (opcion != 15);

    return 0;
}