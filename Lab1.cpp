#include <iostream>
using namespace std;
int main()
{
    float arr[10] = {5., -1., 3., -3., -2., 3., 2., -4., 1., 2.};
    float sum = 0, max = 0, min = 999999999, pro = 1;
    int maxIndex, minIndex;
    
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] < 0) sum +=arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
    }
    if (maxIndex > minIndex) for (int i = minIndex + 1; i < maxIndex; i++) pro *= arr[i];
    else for (int i = maxIndex + 1; i < minIndex; i++) pro *= arr[i];
    cout << "1) Sum: " << sum << "\n\n2) Product: " << pro << endl << endl;
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10 - (i + 1); j++) if (arr[j] > arr[j + 1])
    {
        float x = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = x;
    }
    cout << "Sorted array: ";
    for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
    return 0;
}
