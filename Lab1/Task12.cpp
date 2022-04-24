#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    float A, B, C, d;
    cout << "A: ";
    cin >> A;
    cout << "B: ";
    cin >> B;
    cout << "C: ";
    cin >> C;

    d = B * B - 4 * A * C;
    if (d < 0) cout << "x not in R";
    else if (d == 0) cout << "x = " << -B / (2 * A);
    else cout << "x1 = " << ((-B + pow(d, 0.5f)) / (2 * A)) << ", x2 = " << ((-B - pow(d, 0.5f)) / (2 * A));

    return 0;
}
