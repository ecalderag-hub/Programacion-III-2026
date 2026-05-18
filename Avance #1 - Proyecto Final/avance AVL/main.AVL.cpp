#include "AVL.h"
#include <iostream>
using namespace std;

int main() {
    
     //MOSTRAR NOMBRE DEL ESTUDIANTE
    cout<<endl;
    cout<< "Nombre: ERICKA DANIELA CALDERA GOMEZ"<<endl;


    AVL arbol;

    int opcion;

    do {

        cout << "\n===== MENU AVL =====\n";

        cout << "1. Insertar estudiante\n";
        cout << "2. Mostrar ranking academico\n";
        cout << "3. Buscar por skill_score\n";
        cout << "4. Mostrar estadisticas AVL\n";
        cout << "5. Salir\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1: {

            Student estudiante;

            cout << "ID: ";
            cin >> estudiante.student_id;

            cin.ignore();

            cout << "Nombre completo: ";
            getline(cin, estudiante.full_name);

            cout << "Carrera: ";
            getline(cin, estudiante.career);

            cout << "Semestre: ";
            cin >> estudiante.semester;

            cout << "GPA: ";
            cin >> estudiante.gpa;

            cout << "Skill Score: ";
            cin >> estudiante.skill_score;

            arbol.insertarEstudiante(estudiante);

            cout << "\nEstudiante insertado correctamente.\n";

            break;
        }

        case 2:

            arbol.mostrarRanking();

            break;

        case 3: {

            int score;

            cout << "Ingrese skill_score: ";
            cin >> score;

            arbol.buscarPorScore(score);

            break;
        }

        case 4:

            arbol.mostrarEstadisticas();

            break;

        case 5:

            cout << "\nSaliendo...\n";

            break;

        default:

            cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}