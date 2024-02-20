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

// Función para determinar si un número es primo
int esPrimo(int numero) {
    if (numero <= 1) {
        return 0; // No es primo
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0; // No es primo
        }
    }
    return 1; // Es primo
}

// Función para determinar si un número es primo y guardar el resultado en el archivo de salida
void determinarPrimo() {
    int numero;
    printf("\nIngrese un numero: ");
    scanf("%d", &numero);

    // Determinar si el número es primo
    int primo = esPrimo(numero);
    if (primo) {
        printf("El numero %d es primo.\n", numero);
    } else {
        printf("El numero %d no es primo.\n", numero);
    }

    // Guardar la clasificación en el archivo de salida
    FILE *archivo = fopen("salida.txt", "a");
    if (archivo != NULL) {
        if (primo) {
            fprintf(archivo, "Numero %d: Primo\n", numero);
        } else {
            fprintf(archivo, "Numero %d: No Primo\n", numero);
        }
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

    printf("¡Bienvenido al programa de determinacion de numeros primos!\n");

    // Ingresar el nombre del usuario al inicio del programa
    ingresarNombre(&usuario);

    do {
        printf("\nMenu:\n");
        printf("1. Determinar si un numero es primo\n");
        printf("2. Ver historial de datos\n");
        printf("3. Borrar historial de datos\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                determinarPrimo();
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
