import java.util.HashMap;
import java.util.TreeMap;
import java.io.FileWriter;
import java.io.IOException;

public class Benchmark {

    public static void main(String[] args) {

        try {

            HashMap<Integer, String> hashMap =
                    new HashMap<>();

            TreeMap<Integer, String> treeMap =
                    new TreeMap<>();

            FileWriter archivo =
                    new FileWriter("java_results.csv");

            archivo.write(
                    "language,operation,structure,records,time_ms\n"
            );

            // ==========================
            // HASHMAP INSERT
            // ==========================

            long inicioHash =
                    System.nanoTime();

            for (int i = 0; i < 10000; i++) {

                hashMap.put(
                        i,
                        "Estudiante"
                );
            }

            long finHash =
                    System.nanoTime();

            double tiempoHash =

                    (finHash - inicioHash)
                    / 1000000.0;

            archivo.write(
                    "Java,insert,HashMap,10000,"
                    + tiempoHash + "\n"
            );

            // ==========================
            // HASHMAP SEARCH
            // ==========================

            long inicioBusquedaHash =
                    System.nanoTime();

            for (int i = 0; i < 10000; i++) {

                hashMap.get(i);
            }

            long finBusquedaHash =
                    System.nanoTime();

            double tiempoBusquedaHash =

                    (finBusquedaHash
                    - inicioBusquedaHash)
                    / 1000000.0;

            archivo.write(
                    "Java,search,HashMap,10000,"
                    + tiempoBusquedaHash + "\n"
            );

            // ==========================
            // TREEMAP INSERT
            // ==========================

            long inicioTree =
                    System.nanoTime();

            for (int i = 0; i < 10000; i++) {

                treeMap.put(
                        i,
                        "Estudiante"
                );
            }

            long finTree =
                    System.nanoTime();

            double tiempoTree =

                    (finTree - inicioTree)
                    / 1000000.0;

            archivo.write(
                    "Java,insert,TreeMap,10000,"
                    + tiempoTree + "\n"
            );

            archivo.close();

            System.out.println(
                    "Benchmark Java generado correctamente."
            );

        } catch (IOException e) {

            System.out.println(
                    "Error: "
                    + e.getMessage()
            );
        }
    }
}