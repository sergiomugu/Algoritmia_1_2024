#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    int matriz[MAX][MAX];
    
    // Leer dimensiones de la matriz
    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &n);
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &m);
    
    // Leer los elementos de la matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Ingrese el elemento en la posición [%d, %d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    // Recorrer la matriz para encontrar la posición que cumpla la condición
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int suma_vecinos = 0;
            // Sumar vecino superior si existe
            if (i - 1 >= 0) {
                suma_vecinos += matriz[i - 1][j];
            }
            // Sumar vecino inferior si existe
            if (i + 1 < n) {
                suma_vecinos += matriz[i + 1][j];
            }
            // Sumar vecino izquierdo si existe
            if (j - 1 >= 0) {
                suma_vecinos += matriz[i][j - 1];
            }
            // Sumar vecino derecho si existe
            if (j + 1 < m) {
                suma_vecinos += matriz[i][j + 1];
            }
            // Verificar si el valor en la posición es igual a la suma de sus vecinos
            if (matriz[i][j] == suma_vecinos) {
                printf("La posición [%d, %d] cumple la condición con valor %d\n", i, j, matriz[i][j]);
                //return 0; este va si quiero quedarme con el primer valor encontado que cumpla la condicion
            }
        }
    }
    
    // Si no se encontró ninguna posición
    printf("No se encontró ninguna posición que cumpla la condición\n");
    
    return 0;
}
