#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double xp, xk, x, dx, eps, a=0, R=0, S=0;
    int n=0;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;
    cout << fixed;
    cout << "--------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << " |"
        << setw(10) << "arcctg(x)" << " |"
        << setw(7) << "S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "--------------------------------------------" << endl;
    x = xp;
    while (x <= xk)
    {
        n = 0;
        if(x<0)S = M_PI / -2;
        else S = M_PI / 2;
        do {
            R = pow(-1, n + 1) * pow(x, 2 * n + 1) / (2 * n + 1);
            S += R;
            n++;
        } while (abs(R) >= eps);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << atan(1 / x) << " |"
            << setw(10) << setprecision(5) << S << " |"
            << setw(5) << n << " |"
            << endl;
        x += dx;
        //if (x == -0) { x++; x--; }
    }
    cout << "--------------------------------------------" << endl;
    return 0;
}