- Nombre completo:Ericka Daniela Caldera Gomez
- Carné: 9941 - 24 - 8190
- Descripción del programa
Este programa en C++ implementa e integra múltiples estructuras de datos vistas en clase, permitiendo el ingreso dinámico de números enteros, su clasificación automática y su posterior procesamiento.

El sistema clasifica los datos ingresados según reglas específicas, almacena un historial de operaciones y permite la construcción de un árbol binario de búsqueda (BST) bajo demanda del usuario.

- Estructuras utilizadas
El programa hace uso de las siguientes estructuras:

🔹 Punteros
🔹 Memoria dinámica (new y delete)
🔹 Structs
🔹 Nodos
🔹 Lista simplemente enlazada → almacenamiento de números negativos
🔹 Pila (LIFO) → números impares positivos
🔹 Cola (FIFO) → números pares positivos
🔹 Lista doblemente enlazada → historial de operaciones
🔹 Árbol Binario de Búsqueda (BST) → números positivos

- Explicación de la lógica
Clasificación de datos:
Cada número ingresado se procesa de la siguiente forma:

Si es par y positivo → se inserta en una cola
Si es impar y positivo → se inserta en una pila
Si es negativo → se inserta en una lista simple
Si es cero → se rechaza y se contabiliza

Historial (Lista doble):
Todos los valores válidos se almacenan en una lista doblemente enlazada con:

Valor ingresado:
Tipo de estructura asignada
Orden de ingreso

Árbol BST:
El árbol se construye únicamente cuando el usuario lo solicita desde el menú.

Solo se incluyen números positivos
Se generan los recorridos:
InOrden
PreOrden
PostOrden

Procesamiento de negativos:
Se muestra la lista original
Se eliminan los valores cuya magnitud es menor a 10
Se muestra la lista resultante
Se indica la cantidad de nodos eliminados

Reorganización de estructuras:
La pila se vacía en una lista auxiliar
La cola se vacía en otra lista auxiliar
Se muestran ambas listas
Se reconstruye el árbol BST con esos datos

Estadísticas del sistema:

El programa calcula:

Cantidad de números pares positivos
Cantidad de números impares positivos
Cantidad de números negativos
Cantidad de ceros rechazados
Total de valores válidos
Valor máximo ingresado
Valor mínimo ingresado

Menú del sistema:

El programa incluye las siguientes opciones:

Ingresar N números
Mostrar pila
Mostrar cola
Mostrar lista de negativos
Mostrar historial
Construir y mostrar BST
Eliminar negativos
Buscar en BST
Mostrar estadísticas
Reorganizar estructuras
Salir

- Instrucciones de ejecución
Instrucciones de ejecución
Abrir el programa en un compilador C++ (CodeBlocks, DevC++, VS Code, etc.)
Compilar el archivo
Ejecutar el programa
Utilizar el menú interactivo para probar las funcionalidades
