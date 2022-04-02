/*Задание:
*/

#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int main()
{
    mt19937 mersenne(static_cast<unsigned int>(time(0)));
    
    float *arr = new float [10];
    float sum = 0, max = 0, min = 999999999, pro = 1;
    
    cout << "Array: ";
    for (int i = 0; i < 10; i++)
    {
        arr[i] = mersenne() % 100 / 10.0f * pow(-1, mersenne() % 2);
        cout << arr[i] << ' ';
    }
    
    int maxIndex, minIndex;
    cout << "\n\n" << "1) Sum (";
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] < 0)
        {
            sum += arr[i];
            cout << arr[i] << ' ';
        }
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
    
    cout << "):  " << sum << "\n\n2) Product (";
    if (maxIndex > minIndex) for (int i = minIndex + 1; i < maxIndex; i++) 
    {
        pro *= arr[i];
        cout << arr[i] << ' ';
    }
    else for (int i = maxIndex + 1; i < minIndex; i++) 
    {
        pro *= arr[i];
        cout << arr[i] << ' ';
    }
    cout << "): " << pro << endl << endl;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10 - (i + 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                float x = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = x;
            }
        }
    }
    
    cout << "Sorted array: ";
    for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
    
    delete [] arr;
    return 0;
}
