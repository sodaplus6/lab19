#include <stdio.h>

int s(int n, int d) {
    if (d >= n) return 0;
    return (n % d == 0 ? d : 0) + s(n, d + 1);
}

int main() {
    int N, M;
    printf("N и M: ");
    scanf("%d %d", &N, &M);

    if (N <= 0 || M <= 0 || N > M) return printf("Ошибка\n"), 1;

    for (int i = N; i <= M; i++)
        if (i % 2 == 0 && s(i, 1) % 2 == 0) 
            printf("%d ", i);
            
    printf("\n");
    return 0;
}
