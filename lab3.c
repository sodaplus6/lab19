#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, m;
    printf("N и M: ");
    scanf("%d %d", &n, &m);

    // мат
    float **a = (float**)malloc(n * sizeof(float*));
    for (int i = 0; i < n; i++) a[i] = (float*)malloc(m * sizeof(float));

    printf("Введите матрицу:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) scanf("%f", &a[i][j]); // %f для float

    // Макс в столб
    float max = -1e9;
    int mi = 0, mj = 1; 
    for (int j = 1; j < m; j += 2)
        for (int i = 0; i < n; i++)
            if (a[i][j] > max) { max = a[i][j]; mi = i; mj = j; }
    printf("1. Max: %.2f\n", max);

    // Произв для 4 столбца
    float p = 1.0;
    if (m >= 4) {
        for (int i = 0; i < n; i++)
            if (a[i][3] != 0) p *= (1 + cos(1 - 1 / a[i][3]));
    }
    p += 8.3;
    printf("2. P: %.4f\n", p);

    // Зам
    a[mi][mj] = p;
    
    printf("3. Итог:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%7.2f ", a[i][j]);
        printf("\n");
    }

    for (int i = 0; i < n; i++) free(a[i]);
    free(a);
    return 0;
}
