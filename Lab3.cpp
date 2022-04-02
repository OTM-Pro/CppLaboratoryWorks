#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const int N = 13;
    int arr[N] = {5, -1, 0, 3, -3, 0, -2, 3, 2, -4, 0, 1, 2};
    int firstIndex = -1, secondIndex = -1, max = 0, maxIndex, pro = 1;
    
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
        {
            if (arr[firstIndex] == 0 and secondIndex == -1) secondIndex = i;
            if (firstIndex == -1) firstIndex = i;
        }
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }
    }
    cout << "1) Index: " << maxIndex << endl;
    
    for (int i = firstIndex + 1; i < secondIndex; i++) pro *= arr[i];
    cout << "2) Product: " << pro << endl << "Positions:\t";
    
    for (int i = 0; i < N; i++) cout << "\t" << i + 1 << ' ';
    cout << endl << "Old array:\t";
    for (int i = 0; i < N; i++) cout << "\t" << arr[i] << ' ';
    for (int i = 1; i <= N / 2; i++)
    {
        int x = arr[i];
        arr[i] = arr[i * 2];
        arr[i * 2] = x;
    }
    //cout << endl << "New positions:  1 	3 	5 	7 	9 	11 	13 	8 	2 	10 	6 	12 	4";
    cout << endl << "New array:\t";
    for (int i = 0; i < N; i++) cout << '\t' << arr[i] << ' ';
    
    return 0;
}
