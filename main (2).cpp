
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Calculates the series using a recurrence relation.
double s(const double x, const double eps) {
    double term = x * x / 2.0;
    double sum = 0.0;
    double n = 0.0;

    while (term >= eps || term <= -eps) {
        sum += term;
        term *= x * (n + 2.0) * (2.0 * n + 1.0)
                / ((n + 3.0) * (2.0 * n + 3.0));
        ++n;
    }

    return sum + term;
}

// Reads exactly one finite real number.
bool readNumber(double& value) {
    string line;
    if (!getline(cin, line)) {
        return false;
    }

    istringstream input(line);
    if (!(input >> value)) {
        return false;
    }

    input >> ws;
    return input.eof() && isfinite(value);
}

int main() {
    cout << "The author of this program is Mykola Lukianiuk.\n";
    cout << "This program calculates a power series "
            "with given precision. Variant 170.\n";

    double x = 0.0;
    double eps = 0.0;

    cout << "Enter x (from 0 to 0.9): ";
    if (!readNumber(x)) {
        cout << "\n***** error\nInvalid input for x.\n";
    } else if (x < 0.0 || x > 0.9) {
        cout << "\n***** error\nx is outside the domain.\n";
    } else {
        cout << "Enter positive eps: ";
        if (!readNumber(eps)) {
            cout << "\n***** error\nInvalid input for eps.\n";
        } else if (eps <= 0.0) {
            cout << "\n***** error\neps must be positive.\n";
        } else {
            cout << "\n***** do calculations ...";
            const double result = s(x, eps);
            cout << " done\n";

            cout << scientific << uppercase << setprecision(7);
            cout << "for x = " << x << '\n';
            cout << setprecision(9);
            cout << "for eps = " << eps << '\n';
            cout << fixed << setprecision(8);
            cout << "result = " << result << '\n';
        }
    }

    return 0;
}
