#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    printf("Ввести размер массива n: ");
    scanf("%d", &n);

    float *a = (float*)malloc(n * sizeof(float));

    printf("Ввести элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &a[i]);
    }

    float max = -10000000;
    int mi = 1;
    for (int i = 1; i < n; i += 2) {
        if (a[i] > max) {
            max = a[i];
            mi = i;
        }
    }
    printf("Макс: %f\n", max);

    float p = 1.0;
    if (n >= 4) {
        if (a[3] != 0) {
            p *= (1 + cos(1 - 1 / a[3]));
        }
    }
    p += 8.3;
    printf("P: %f\n", p);

    printf("Результат:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", a[i]);
    }
    printf("\n");

    free(a);
    
    return 0;
}
