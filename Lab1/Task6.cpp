#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int km, m, mi, ft;
    cout << "Km: ";
    cin >> km;
    cout << "M: ";
    cin >> m;

    m += km * 1000;
    ft = m * 3.28f;
    mi = ft / 5280;
    ft -= mi * 5280;

    cout << mi << " mi " << ft << " ft ";

    return 0;
}
