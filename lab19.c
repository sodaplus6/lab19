#include <stdio.h>
#include <math.h>

int main() {
    float x, a, z, z1, z2, z3;
    float xn = 1.0, xk = 3.0, hx = 1.3;
    float an = 2.0, ak = 4.0, ha = 1.3;

    for (x = xn; x <= xk; x += hx) {
        for (a = an; a <= ak; a += ha) {

            z1 = sqrt((a - x) / x);
            z2 = log((a * a) / x);
            z3 = atan((x * cbrt(a)) / (a + 2.5));

            z = z1;
            if (z2 < z) z = z2;
            if (z3 < z) z = z3;

            printf("x=%f a=%f z=%f\n", x, a, z);
        }
    }

    return 0;
}
