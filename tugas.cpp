#include <stdio.h>
#include <math.h>
#include <float.h>

// =====================================================
//   METODE BISEKSI - Pencari Akar Persamaan
//   f(x) = x^3 - 4 = 0
//   Batas bawah a = 1, Batas atas b = 2
//   Berjalan hingga error < machine epsilon (DBL_EPSILON)
// =====================================================

double f(double x) {
    return x * x * x - 4;
}

int main() {
    double a = 1.0;
    double b = 2.0;
    double c, error;
    int iteration = 0;

    // Cek apakah a dan b valid (f(a) dan f(b) harus berbeda tanda)
    if (f(a) * f(b) > 0) {
        printf("ERROR: f(a) dan f(b) harus berbeda tanda!\n");
        return 1;
    }

    printf("Metode Biseksi: f(x) = x^3 - 4 = 0\n");
    printf("Batas bawah a = %.1f, Batas atas b = %.1f\n", a, b);
    printf("Toleransi: Machine Epsilon (DBL_EPSILON = %.2e)\n\n", DBL_EPSILON);
    printf("%-6s %-18s %-18s %-18s %-18s %-18s %-18s\n",
           "Iter", "a", "b", "c = (a+b)/2", "f(a)", "f(c)", "Error");
    printf("--------------------------------------------------------------"
           "--------------------------------------------------------------\n");

    do {
        // Hitung titik tengah
        c = (a + b) / 2.0;
        error = fabs(b - a) / 2.0;

        iteration++;

        printf("%-6d %-18.15f %-18.15f %-18.15f %-18.15f %-18.15f %-18.2e\n",
               iteration, a, b, c, f(a), f(c), error);

        // Tentukan interval baru
        if (f(a) * f(c) < 0) {
            b = c;   // Akar ada di [a, c]
        } else if (f(c) * f(b) < 0) {
            a = c;   // Akar ada di [c, b]
        } else {
            // f(c) == 0, akar tepat ditemukan
            break;
        }

    } while (error > DBL_EPSILON);

    printf("\n============================================================\n");
    printf("HASIL AKHIR\n");
    printf("============================================================\n");
    printf("Akar ditemukan pada    : x = %.15f\n", c);
    printf("Nilai f(x)             : f(%.15f) = %.2e\n", c, f(c));
    printf("Total iterasi          : %d\n", iteration);
    printf("Error akhir            : %.2e\n", error);
    printf("============================================================\n");

    return 0;
}