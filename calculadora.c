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

// Función para realizar la suma de dos números
float suma(float a, float b) {
    return a + b;
}

// Función para realizar la resta de dos números
float resta(float a, float b) {
    return a - b;
}

// Función para realizar la multiplicación de dos números
float multiplicacion(float a, float b) {
    return a * b;
}

// Función para realizar la división de dos números
float division(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: No se puede dividir por cero.\n");
        return 0;
    }
}

// Función para realizar una operación matemática
float realizarOperacion(int opcion, float a, float b) {
    switch (opcion) {
        case 1:
            return suma(a, b);
        case 2:
            return resta(a, b);
        case 3:
            return multiplicacion(a, b);
        case 4:
            return division(a, b);
        default:
            printf("Opcion no valida.\n");
            return 0;
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
    float num1, num2, resultado;

    printf("¡Bienvenido a la calculadora!\n");

    // Ingresar el nombre del usuario al inicio del programa
    ingresarNombre(&usuario);

    do {
        printf("\nMenu:\n");
        printf("1. Suma\n");
        printf("2. Resta\n");
        printf("3. Multiplicacion\n");
        printf("4. Division\n");
        printf("5. Ver historial de datos\n");
        printf("6. Borrar historial de datos\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
            case 2:
            case 3:
            case 4:
                printf("\nIngrese dos numeros:\n");
                printf("Primer numero: ");
                scanf("%f", &num1);
                printf("Segundo numero: ");
                scanf("%f", &num2);
                resultado = realizarOperacion(opcion, num1, num2);
                printf("El resultado de la operacion es: %.2f\n", resultado);

                // Guardar la operación en el archivo de salida
                FILE *archivo = fopen("salida.txt", "a");
                if (archivo != NULL) {
                    fprintf(archivo, "%.2f %c %.2f = %.2f\n", num1, "+-*/"[opcion - 1], num2, resultado);
                    fclose(archivo);
                } else {
                    printf("Error al guardar la operacion.\n");
                }
                break;
            case 5:
                mostrarHistorial();
                break;
            case 6:
                borrarHistorial();
                break;
            case 7:
                printf("\n¡Gracias por usar la calculadora, %s! ¡Hasta luego!\n", usuario.nombre);
                break;
            default:
                printf("\nOpcion no valida. Por favor, seleccione una opcion valida.\n");
                break;
        }
    } while (opcion != 7);

    return 0;
}
