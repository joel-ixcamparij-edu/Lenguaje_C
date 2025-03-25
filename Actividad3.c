#include <stdio.h>

// Tasas de conversión (actualizables según el mercado)
#define GTQ_TO_USD 0.13
#define GTQ_TO_EUR 0.12
#define USD_TO_GTQ 7.80
#define USD_TO_EUR 0.92
#define EUR_TO_GTQ 8.50
#define EUR_TO_USD 1.09

void convertirMoneda(int opcion, double cantidad) {
    double resultado = 0;

    switch(opcion) {
        case 1:
            resultado = cantidad * GTQ_TO_USD;
            printf("%.2f Quetzales = %.2f Dólares\n", cantidad, resultado);
            break;
        case 2:
            resultado = cantidad * GTQ_TO_EUR;
            printf("%.2f Quetzales = %.2f Euros\n", cantidad, resultado);
            break;
        case 3:
            resultado = cantidad * USD_TO_GTQ;
            printf("%.2f Dólares = %.2f Quetzales\n", cantidad, resultado);
            break;
        case 4:
            resultado = cantidad * USD_TO_EUR;
            printf("%.2f Dólares = %.2f Euros\n", cantidad, resultado);
            break;
        case 5:
            resultado = cantidad * EUR_TO_GTQ;
            printf("%.2f Euros = %.2f Quetzales\n", cantidad, resultado);
            break;
        case 6:
            resultado = cantidad * EUR_TO_USD;
            printf("%.2f Euros = %.2f Dólares\n", cantidad, resultado);
            break;
        default:
            printf("Opción no válida.\n");
    }
}

int main() {
    int opcion;
    double cantidad;

    do {
        // Mostrar menú
        printf("\n=== Conversor de Monedas ===\n");
        printf("1. Quetzales a Dólares\n");
        printf("2. Quetzales a Euros\n");
        printf("3. Dólares a Quetzales\n");
        printf("4. Dólares a Euros\n");
        printf("5. Euros a Quetzales\n");
        printf("6. Euros a Dólares\n");
        printf("7. Salir\n");
        printf("Seleccione una opción: ");

        if (scanf("%d", &opcion) != 1) { // Verifica entrada inválida
            printf("Entrada inválida. Intente de nuevo.\n");
            while(getchar() != '\n'); // Limpiar buffer de entrada
            continue;
        }

        if (opcion >= 1 && opcion <= 6) {
            printf("Ingrese la cantidad: ");
            if (scanf("%lf", &cantidad) != 1) {
                printf("Cantidad inválida. Intente de nuevo.\n");
                while(getchar() != '\n'); // Limpiar buffer
                continue;
            }
            convertirMoneda(opcion, cantidad);
        } else if (opcion != 7) {
            printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 7);

    printf("Gracias por usar el conversor de monedas.\n");
    return 0;
}
