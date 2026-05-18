#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Estudiante {

    int id;
    string nombre;
    string carrera;
    int semestre;
    float gpa;
    int skillScore;
};

struct Nodo {

    Estudiante estudiante;
    Nodo* siguiente;
};

class HashTable {

private:

    static const int SIZE=10;

    Nodo* tabla[SIZE];

    int totalElementos;
    int totalColisiones;

    int funcionHash(int id){

        return id % SIZE;
    }

public:

    HashTable(){

        for(int i=0;i<SIZE;i++){

            tabla[i]=nullptr;
        }

        totalElementos=0;
        totalColisiones=0;
    }

    bool insertar(
        int id,
        string nombre,
        string carrera,
        int semestre,
        float gpa,
        int skillScore
    ){

        int indice=funcionHash(id);

        if(buscar(id)!=nullptr){

            cout<<"Error: ID duplicado\n";
            return false;
        }

        Nodo* nuevo=new Nodo;

        nuevo->estudiante.id=id;
        nuevo->estudiante.nombre=nombre;
        nuevo->estudiante.carrera=carrera;
        nuevo->estudiante.semestre=semestre;
        nuevo->estudiante.gpa=gpa;
        nuevo->estudiante.skillScore=skillScore;

        nuevo->siguiente=nullptr;

        if(tabla[indice]!=nullptr){

            totalColisiones++;
        }

        nuevo->siguiente=tabla[indice];

        tabla[indice]=nuevo;

        totalElementos++;

        cout<<"Insertado en bucket "
            <<indice<<endl;

        return true;
    }

    void cargarCSV(string archivo){

        ifstream file(archivo);

        if(!file){

            cout<<"Error al abrir CSV\n";
            return;
        }

        string linea;

        getline(file,linea);

        while(getline(file,linea)){

            stringstream ss(linea);

            string dato;

            int id;
            string nombre;
            string carrera;
            int semestre;
            float gpa;
            int skillScore;

            getline(ss,dato,',');
            id=stoi(dato);

            getline(ss,nombre,',');

            getline(ss,carrera,',');

            getline(ss,dato,',');
            semestre=stoi(dato);

            getline(ss,dato,',');
            gpa=stof(dato);

            getline(ss,dato,',');
            skillScore=stoi(dato);

            insertar(
                id,
                nombre,
                carrera,
                semestre,
                gpa,
                skillScore
            );
        }

        file.close();

        cout<<"\nCSV cargado correctamente\n";
    }

    Estudiante* buscar(int id){

        int indice=funcionHash(id);

        Nodo* actual=tabla[indice];

        while(actual!=nullptr){

            if(actual->estudiante.id==id){

                return &actual->estudiante;
            }

            actual=actual->siguiente;
        }

        return nullptr;
    }

    bool eliminar(int id){

        int indice=funcionHash(id);

        Nodo* actual=tabla[indice];
        Nodo* anterior=nullptr;

        while(actual!=nullptr){

            if(actual->estudiante.id==id){

                if(anterior==nullptr){

                    tabla[indice]=actual->siguiente;
                }

                else{

                    anterior->siguiente=
                    actual->siguiente;
                }

                delete actual;

                totalElementos--;

                cout<<"Estudiante eliminado\n";

                return true;
            }

            anterior=actual;

            actual=actual->siguiente;
        }

        return false;
    }

    void mostrarTabla(){

        cout<<"\n----- HASH TABLE -----\n";

        for(int i=0;i<SIZE;i++){

            cout<<"Bucket "<<i<<": ";

            Nodo* actual=tabla[i];

            if(actual==nullptr){

                cout<<"vacio";
            }

            while(actual!=nullptr){

                cout<<"("

                <<actual->estudiante.id

                <<", "

                <<actual->estudiante.nombre

                <<") -> ";

                actual=actual->siguiente;
            }

            cout<<"NULL\n";
        }
    }

    float calcularFactorCarga(){

        return (float)
                totalElementos/SIZE;
    }

    void mostrarEstadisticas(){

        cout<<"\n===== ESTADISTICAS =====\n";

        cout<<"Total estudiantes: "
            <<totalElementos<<endl;

        cout<<"Total buckets: "
            <<SIZE<<endl;

        cout<<"Total colisiones: "
            <<totalColisiones<<endl;

        cout<<"Factor carga: "
            <<calcularFactorCarga()
            <<endl;
    }

};

int main(){

    cout<<"Nombre: ERICKA DANIELA CALDERA GOMEZ\n";
    cout<<"Carne: 9941 - 24 - 8190\n";

      HashTable hash;

    int opcion;

    do{

        cout<<"\n========== MENU HASH TABLE ==========\n";

        cout<<"1. Cargar CSV\n";
        cout<<"2. Buscar estudiante\n";
        cout<<"3. Eliminar estudiante\n";
        cout<<"4. Mostrar tabla hash\n";
        cout<<"5. Mostrar estadisticas\n";
        cout<<"6. Salir\n";

        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        if(opcion==1){

            hash.cargarCSV(
                    "estudiantes.csv"
            );
        }

        else if(opcion==2){

            int id;

            cout<<"Ingrese ID a buscar: ";
            cin>>id;

            Estudiante* encontrado=
                    hash.buscar(id);

            if(encontrado!=nullptr){

                cout<<"\n=== ESTUDIANTE ENCONTRADO ===\n";

                cout<<"ID: "
                    <<encontrado->id
                    <<endl;

                cout<<"Nombre: "
                    <<encontrado->nombre
                    <<endl;

                cout<<"Carrera: "
                    <<encontrado->carrera
                    <<endl;

                cout<<"Semestre: "
                    <<encontrado->semestre
                    <<endl;

                cout<<"GPA: "
                    <<encontrado->gpa
                    <<endl;

                cout<<"Skill Score: "
                    <<encontrado->skillScore
                    <<endl;
            }

            else{

                cout<<"No encontrado\n";
            }

        }

        else if(opcion==3){

            int id;

            cout<<"Ingrese ID a eliminar: ";
            cin>>id;

            hash.eliminar(id);
        }

        else if(opcion==4){

            hash.mostrarTabla();
        }

        else if(opcion==5){

            hash.mostrarEstadisticas();
        }

        else if(opcion==6){

            cout<<"\nPrograma finalizado\n";
        }

        else{

            cout<<"\nOpcion invalida\n";
        }

    }

    while(opcion!=6);

    return 0;
}