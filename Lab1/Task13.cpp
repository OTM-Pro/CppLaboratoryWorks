#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    float x, ln = 0;
    cout << "X: ";
    cin >> x;

    for (int n = 1; n <= 100; n++)
    {
        ln += pow(-1, n - 1) * (pow(x - 1, n) / n);
    }
    cout << "Ln(x) = " << ln;

    return 0;
}
