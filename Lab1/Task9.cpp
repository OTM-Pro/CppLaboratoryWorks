#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int n, sum = 1;
    cout << "N: ";
    cin >> n;

    cout << 1;
    for (int i = 1; i < n; i++)
    {
        cout << " + " << i * 2 + 1;
        sum += i * 2 + 1;
    }
    cout << " = " << sum;

    return 0;
}
