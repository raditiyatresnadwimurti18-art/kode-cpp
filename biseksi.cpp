#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return pow(x, 3) - x - 2; // Ganti fungsi sesuai kebutuhan
}

double biseksi(double xl, double xu, double es = 0.001, int imax = 100) {
    if (f(xl) * f(xu) >= 0) {
        cout << "Error: f(xl) dan f(xu) harus berbeda tanda!" << endl;
        return -1;
    }

    double xr = 0, xr_lama = 0, ea = 0;
    cout << setw(4) << "Iter"
         << setw(12) << "xl"
         << setw(12) << "xu"
         << setw(12) << "xr"
         << setw(12) << "ea(%)" << endl;

    for (int i = 1; i <= imax; i++) {
        xr = (xl + xu) / 2.0;
        ea = (xr != 0) ? fabs((xr - xr_lama) / xr) * 100 : 0;

        cout << fixed << setprecision(5)
             << setw(4)  << i
             << setw(12) << xl
             << setw(12) << xu
             << setw(12) << xr
             << setw(12) << ea << endl;

        if (ea < es) break;

        double test = f(xl) * f(xr);
        if (test < 0)      xu = xr;
        else if (test > 0) xl = xr;
        else               break;

        xr_lama = xr;
    }

    cout << "\nAkar ditemukan: xr = " << xr << endl;
    return xr;
}

int main() {
    biseksi(1.0, 2.0);
    return 0;
}