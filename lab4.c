#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* make_arr(int n) {
    int *a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Error\n");
        exit(1);
    }
    return a;
}

void fill_arr(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000; 
    }
}

void copy_arr(int *src, int *dst, int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

void sort_bubble(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void sort_insert(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void merge(int *a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++; k++;
    }

    free(L);
    free(R);
}

void sort_merge(int *a, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        sort_merge(a, left, mid);
        sort_merge(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main() {
    srand(time(NULL));

    int sizes[] = {10, 1000, 10000, 100000};
    int num = sizeof(sizes) / sizeof(sizes[0]);

    for (int s = 0; s < num; s++) {
        int n = sizes[s];
        
        int *src = make_arr(n);
        int *a1  = make_arr(n);
        int *a2  = make_arr(n);
        int *a3  = make_arr(n);

        fill_arr(src, n);

        clock_t start, end;
        double t1, t2, t3;

        copy_arr(src, a1, n);
        start = clock();
        sort_bubble(a1, n);
        end = clock();
        t1 = (double)(end - start) / CLOCKS_PER_SEC;

        copy_arr(src, a2, n);
        start = clock();
        sort_insert(a2, n);
        end = clock();
        t2 = (double)(end - start) / CLOCKS_PER_SEC;

        copy_arr(src, a3, n);
        start = clock();
        sort_merge(a3, 0, n - 1);
        end = clock();
        t3 = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d %f %f %f\n", n, t1, t2, t3);

        free(src);
        free(a1);
        free(a2);
        free(a3);
    }

    return 0;
}
