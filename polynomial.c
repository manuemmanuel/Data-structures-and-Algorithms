#include <stdio.h>
void main() {
    struct polynomial {
    int coefficient;
    int exponent;
    };
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    struct polynomial a[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%d", &a[i].coefficient);
        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &a[i].exponent);
    }
    printf("Polynomial: ");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i].coefficient);
        if (a[i].exponent != 0) {
            printf("x^%d", a[i].exponent);
        }
        if (i < n - 1) {
            if (a[i + 1].coefficient >= 0) {
                printf(" + ");
            }
        }
    }
}
