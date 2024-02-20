#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar los datos del usuario
struct Usuario {
    char nombre[50];
};

// Función para ingresar el nombre del usuario
void ingresarNombre(struct Usuario *usuario) {
    printf("Ingrese su nombre: ");
    scanf("%s", usuario->nombre);
}

// Función para realizar la suma de dos números enteros
void realizarSuma() {
    int num1, num2;
    printf("\nIngrese el primer numero entero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero entero: ");
    scanf("%d", &num2);

    int suma = num1 + num2;
    printf("La suma de %d y %d es: %d\n", num1, num2, suma);

    // Guardar la suma en el archivo de salida
    FILE *archivo = fopen("salida.txt", "a");
    if (archivo != NULL) {
        fprintf(archivo, "Suma: %d\n", suma);
        fclose(archivo);
    } else {
        printf("Error al guardar la suma.\n");
    }
}

// Función para mostrar el historial de datos
void mostrarHistorial() {
    printf("\n--- Historial de Datos ---\n");

    FILE *archivo = fopen("salida.txt", "r");
    if (archivo != NULL) {
        char linea[100];
        while (fgets(linea, sizeof(linea), archivo)) {
            printf("%s", linea);
        }
        fclose(archivo);
    } else {
        printf("No hay historial de datos.\n");
    }
}

// Función para borrar el historial de datos
void borrarHistorial() {
    if (remove("salida.txt") == 0) {
        printf("\nHistorial de datos borrado exitosamente.\n");
    } else {
        printf("\nError al borrar el historial de datos.\n");
    }
}

int main() {
    int opcion;
    struct Usuario usuario;

    printf("¡Bienvenido al programa de suma de numeros enteros!\n");

    // Ingresar el nombre del usuario al inicio del programa
    ingresarNombre(&usuario);

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar numeros y realizar suma\n");
        printf("2. Ver historial de datos\n");
        printf("3. Borrar historial de datos\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                realizarSuma();
                break;
            case 2:
                mostrarHistorial();
                break;
            case 3:
                borrarHistorial();
                break;
            case 4:
                printf("\n¡Gracias por usar el programa, %s! ¡Hasta luego!\n", usuario.nombre);
                break;
            default:
                printf("\nOpcion no valida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
