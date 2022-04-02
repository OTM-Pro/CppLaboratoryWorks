#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const int X = 3;
    const int Y = 4;
    int arr[X][Y] = {{1, 2, 2, 3}, {0, 4, 4, 5}, {0, 6, 7, 8}};
    int amount = 0, max = 0;
    
    for (int i = 0; i < X; i++)
    {
        bool f = true;
        for (int j = 0; j < Y; j++) if (arr[i][j] == 0) f = false;
        if (f) amount++;
    }
    cout << "1) Amount: " << amount << endl;
    
    int n = 0;
    int *buf = new int [n];
    for (int i = 0; i < X; i++)
    {
        for (int j = 0; j < Y; j++)
        {
            bool inBuf = false, duplicateFound = false;
            for (int k = 0; k < n; k++) if (arr[i][j] == buf[k]) inBuf = true;
            
            for (int i2 = i; i2 < X; i2++)
            {
                for (int j2 = j + 1; j2 < Y; j2++)
                {
                    if (arr[i][j] == arr[i2][j2]) duplicateFound = true;
                }
            }
            
            if (!inBuf and duplicateFound)
            {
                n++;
                int *newBuf = new int [n];
                for (int k = 0; k < n - 1; k++) newBuf[k] = buf[k];
                newBuf[n - 1] = arr[i][j];
                buf = newBuf;
            }
        }
    }
    
    for (int i = 0; i < n; i++) if (buf[i] > max) max = buf[i];
    cout << "2) Max: " << max << endl;
    
    return 0;
}
