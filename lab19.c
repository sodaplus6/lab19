#include <stdio.h>
#include <math.h>

int main() {
    double x, a, z;
    double xn = 1.0, xk = 3.0, hx = 1.3;
    double an = 2.0, ak = 4.0, ha = 1.3;

    printf("+        +        +                     +\n");
    printf("|   x    |   a    |         z           |\n");
    printf("+        +        +                     +\n");

    for (x = xn; x <= xk + 1e-9; x += hx) {
        for (a = an; a <= ak + 1e-9; a += ha) {

            double z1 = sqrt((a - x) / x);
            double z2 = log((a * a) / x);
            double z3 = atan((x * cbrt(a)) / (a + 2.5));

            z = z1;
            if (z2 < z) z = z2;
            if (z3 < z) z = z3;

            printf("| %6.2f | %6.2f | %19.6f |\n", x, a, z);
        }
    }

    printf("+        +        +                    +\n");
    return 0;
}
