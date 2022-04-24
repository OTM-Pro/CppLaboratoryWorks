#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
    {
        f = f * i;
    }
    return abs(f);
}

int main()
{
    float x, sin = 0;
    cout << "X: ";
    cin >> x;

    for (int n = 0; n <= 10; n++)
    {
        sin += (pow(-1, n) * pow(x, 2 * n + 1)) / fact(2 * n + 1);
    }
    cout << "Sin(x) = " << sin;

    return 0;
}
