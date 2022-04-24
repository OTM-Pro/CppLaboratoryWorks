#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int n, i = 1, sum = 1;
    cout << "N: ";
    cin >> n;

    cout << 1;
    do
    {
        cout << " + " << i * 2 + 1;
        sum += i * 2 + 1;
        i++;
    }
    while (i < n);
    cout << " = " << sum;

    return 0;
}
