#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cout << "N: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << 4 * i + 3 << ' ';
    }

    return 0;
}
