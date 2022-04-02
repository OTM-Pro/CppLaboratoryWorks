/*Задание:
В одномерном массиве, состоящем из n вещественных элементов:
1) вычислить количество элементов массива, меньших С;
2) вычислить сумму целых частей элементов массива, расположенных после последнего отрицательного элемента;
3) преобразовать массив таким образом, чтобы сначала располагались все элементы, отличающиеся от максимального не более чем на 20%, а потом - все остальные.
Пример массива: {5.2, -6.3, 0.2, 0.5, -0.6, 4., 3., 0.9, 7.}*/

#include <iostream>
#include <cmath>
using namespace std;

int amount(float C, float *arr);

int main()
{
    const int N = 9;
    float arr[N] = {5.2, -6.3, 0.2, 0.5, -0.6, 4., 3., 0.9, 7.};
    float C, max = 0;
    int sum = 0, lastNegativeIndex = -1;
    
    cout << "C = ";
    cin >> C;
    
    cout << "Amount: " << amount(C, arr) << endl;
    
    for (int i = 0; i < N; i++) if (arr[i] < 0) lastNegativeIndex = i;
    for (int i = lastNegativeIndex + 1; i < N; i++) sum += floor(arr[i]);
    cout << "Sum: " << sum << endl;
    
    for (int i = 0; i < N; i++) if (arr[i] > max) max = arr[i];
    for (int i = 0; i < N; i++) if (arr[i] < max * 0.8)
    {
        for (int j = i + 1; j < N; j++) if (arr[j] >= max * 0.8)
        {
            float x = arr[i];
            arr[i] = arr[j];
            arr[j] = x;
        }
    }
    cout << "New array: ";
    for (int i = 0; i < N; i++) cout << arr[i] << ' ';
    
    return 0;
}

int amount(float C, float *arr)
{
    int am = 0;
    for (int i = 0; i < 9; i++) if (arr[i] < C) am++;
    return am;
}
