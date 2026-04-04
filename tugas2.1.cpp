#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x * x - 3;
}

int main() {
    double a = 1.0, b = 2.0, c;
    double tol = 0.05;
    int iterasi = 1;

    // Cek apakah interval valid
    if (f(a) * f(b) >= 0) {
        cout << "Interval tidak valid. f(a) dan f(b) harus beda tanda.\n";
        return 1;
    }

    cout << fixed << setprecision(6);
    cout << "Metode False Position\n";
    cout << "Mencari akar f(x) = x^2 - 3\n\n";

    cout << "-----------------------------------------------------------------------------------------------------------------\n";
    cout << "Iterasi\t a\t\t f(a)\t\t b\t\t f(b)\t\t c\t\t f(c)\t\t |f(c)|\t\t Status\n";
    cout << "-----------------------------------------------------------------------------------------------------------------\n";

    do {
        // Rumus False Position
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        // Tampilkan iterasi
        cout << iterasi << "\t "
             << a << "\t "
             << f(a) << "\t "
             << b << "\t "
             << f(b) << "\t "
             << c << "\t "
             << f(c) << "\t "
             << fabs(f(c)) << "\t ";

        // Cek apakah sudah memenuhi toleransi
        if (fabs(f(c)) < tol)
            cout << "Stop";
        else
            cout << "Lanjut";

        cout << endl;

        // Menentukan interval baru
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        iterasi++;

    } while (fabs(f(c)) >= tol);

    cout << "\nAkar hampiran = " << c << endl;
    cout << "f(c) = " << f(c) << endl;
    cout << "|f(c)| = " << fabs(f(c)) << " < " << tol << " (memenuhi toleransi)\n";

    return 0;
}