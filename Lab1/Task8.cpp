#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int kmph;
    cout << "Km/h: ";
    cin >> kmph;

    cout << "M/s: " << kmph / 3.6f;

    return 0;
}
