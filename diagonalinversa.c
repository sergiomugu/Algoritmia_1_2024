#include <stdio.h>

int main() {
    int n; // Tamaño de la matriz (n debe ser par y mayor que 2)
    printf("Ingrese el tamaño de la matriz (n): ");
    scanf("%d", &n);

    if (n <= 2 || n % 2 != 0) {
        printf("n debe ser un número par y mayor que 2.\n");
        return 1;
    }

    int K[n][n]; // Definir la matriz K (n*n)

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &K[i][j]);
        }
    }

    int suma = 0; // Variable para acumular la suma

    // Calcular la suma de los elementos en la diagonal inversa (i + j = n - 1)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j == n - 1) {
                suma += K[i][j];
            }
        }
    }

    // Imprimir el resultado
    printf("La suma de los elementos en la diagonal inversa es: %d\n", suma);

    return 0;
}
