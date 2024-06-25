#include <stdio.h>

int main() {
    int n, f1 = 0, f2 = 1, res, i;
    char serie[1000];

    printf("Ingrese la posicion de la serie: ");
    scanf("%d", &n);

    switch (n) {
        case 1:
            strcpy(serie, "0");
            res = 0;
            break;
        case 2:
            strcpy(serie, "0,1");
            res = 1;
            break;
        default:
            strcpy(serie, "0,1,");
            for (i = 2; i < n; i++) {
                res = f1 + f2;
                sprintf(serie + strlen(serie), "%d,", res);
                f1 = f2;
                f2 = res;
            }
            break;
    }

    printf("El Fibonacci en la posicion %d es: %d\n", n, res);
    printf("La serie es: %s\n", serie);

    return 0;
}
