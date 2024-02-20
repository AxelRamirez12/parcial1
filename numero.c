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

// Función para determinar si un número es positivo, negativo o cero
void determinarNumero() {
    float numero;
    printf("\nIngrese un numero: ");
    scanf("%f", &numero);

    // Determinar si el número es positivo, negativo o cero
    if (numero > 0) {
        printf("El numero %.2f es positivo.\n", numero);
    } else if (numero < 0) {
        printf("El numero %.2f es negativo.\n", numero);
    } else {
        printf("El numero es cero.\n");
    }

    // Guardar la clasificación en el archivo de salida
    FILE *archivo = fopen("salida.txt", "a");
    if (archivo != NULL) {
        fprintf(archivo, "Numero: %.2f\n", numero);
        fclose(archivo);
    } else {
        printf("Error al guardar la clasificacion del numero.\n");
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

    printf("¡Bienvenido al programa de clasificacion de numeros!\n");

    // Ingresar el nombre del usuario al inicio del programa
    ingresarNombre(&usuario);

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar numero y determinar clasificacion\n");
        printf("2. Ver historial de datos\n");
        printf("3. Borrar historial de datos\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                determinarNumero();
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
