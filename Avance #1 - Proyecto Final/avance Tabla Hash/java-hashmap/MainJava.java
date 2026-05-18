/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.main.java;
import java.util.HashMap;
import java.util.Scanner;
import java.io.*;

/**
 *
 * @author Daniela Caldera
 */
public class MainJava {

    public static void main(String[] args)  { 
    System.out.println("Nombre: ERICKA DANIELA CALDERA GOMEZ");
    System.out.println("Carne: 9941 - 24 - 8190");
        
        Scanner entrada = new Scanner(System.in);

        HashMap<Integer, Estudiante> estudiantes =
                new HashMap<>();

        int opcion;

        do {

            System.out.println("\n====== MENU ======");

            System.out.println("1. Cargar CSV");
            System.out.println("2. Buscar estudiante");
            System.out.println("3. Eliminar estudiante");
            System.out.println("4. Mostrar estudiantes");
            System.out.println("5. Estadisticas");
            System.out.println("6. Salir");

            System.out.print("Seleccione: ");

            opcion = entrada.nextInt();

            if(opcion==1){

                try{

                    BufferedReader br =
                            new BufferedReader(
                                    new FileReader(
                                            "estudiantes.csv"
                                    )
                            );

                    String linea;

                    br.readLine();

                    while((linea=br.readLine())!=null){

                        String datos[]=
                                linea.split(",");

                        int id=
                                Integer.parseInt(
                                        datos[0]);

                        // validar duplicados
                        if(estudiantes.containsKey(id)){

                            System.out.println(
                                    "ID duplicado: "
                                            +id
                            );

                            continue;
                        }

                        Estudiante e=
                                new Estudiante(

                                        id,
                                        datos[1],
                                        datos[2],
                                        Integer.parseInt(datos[3]),
                                        Double.parseDouble(datos[4]),
                                        Integer.parseInt(datos[5])

                                );

                        estudiantes.put(id,e);

                    }

                    br.close();

                    System.out.println(
                            "\nCSV cargado correctamente"
                    );

                }

                catch(Exception e){

                    System.out.println(e);

                }

            }

            else if(opcion==2){

                int id;

                System.out.print(
                        "Ingrese ID: "
                );

                id=
                        entrada.nextInt();

                if(estudiantes.containsKey(id)){

                    System.out.println(
                            "\n=== ENCONTRADO ==="
                    );

                    System.out.println(
                            estudiantes.get(id)
                    );

                }

                else{

                    System.out.println(
                            "No existe estudiante."
                    );
                }

            }

            else if(opcion==3){

                int id;

                System.out.print(
                        "Ingrese ID a eliminar: "
                );

                id=
                        entrada.nextInt();

                if(estudiantes.containsKey(id)){

                    estudiantes.remove(id);

                    System.out.println(
                            "Eliminado correctamente"
                    );

                }

                else{

                    System.out.println(
                            "No existe"
                    );

                }

            }

            else if(opcion==4){

                System.out.println(
                        "\n=== ESTUDIANTES ==="
                );

                for(Integer key:
                        estudiantes.keySet()){

                    System.out.println(
                            "----------------"
                    );

                    System.out.println(
                            estudiantes.get(key)
                    );

                }

            }

            else if(opcion==5){

                System.out.println(
                        "\n=== ESTADISTICAS ==="
                );

                System.out.println(
                        "Total estudiantes: "
                                +
                                estudiantes.size()
                );

                System.out.println(
                        "Estructura usada: HashMap"
                );

            }

        }

        while(opcion!=6);

    }

}
