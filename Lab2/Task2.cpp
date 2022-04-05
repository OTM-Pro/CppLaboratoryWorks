/*Задание:
В одномерном массиве, состоящем из n вещественных элементов:
1) вычислить сумму элементов массива с нечетными номерами;
2) вычислить сумму элементов массива, расположенных между первым и последним отрицательными элементами;
3) сжать массив, удалив из него все элементы, модуль которых не превышает 1, освободившиеся в конце массива элементы заполнить нулями.
Пример массива: {5.2, -6.3, 0.2, 0.5, -0.6, 4., 3., 0.9, 7.}*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float arr[9] = {5.2, -6.3, 0.2, 0.5, -0.6, 4., 3., 0.9, 7.};
    float sum = 0;
    int firstIndex = -1, lastIndex, j = 0;
    
    for (int i = 0; i < 9; i++)
    {
        int x = abs(arr[i]);
        if (abs(arr[i] - x) > 0)
        {
            x = arr[i] * 10;
            if (x % 2 != 0) sum += arr[i];
        }
        else if (x % 2 != 0) sum += arr[i];
    }
    cout << "First sum: " << sum << endl;
    
    sum = 0;
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] < 0)
        {
            if (firstIndex == -1) firstIndex = i;
            lastIndex = i;
        }
    }
    for (int i = firstIndex + 1; i < lastIndex; i++) sum += arr[i];
    cout << "Second sum: " << sum << endl;
    
    for (int i = 0; i < 9; i++) if (abs(arr[i]) <= 1) arr[i] = 0;
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == 0)
        {
            int save = -1;
            for (int j = i + 1; j < 9; j++) if (arr[j] != 0) save = j;
            if (save != -1)
            {
                float x = arr[i];
                arr[i] = arr[save];
                arr[save] = x;
            }
        }
    }
    cout << "New array: ";
    for (int i = 0; i < 9; i++) cout << arr[i] << ' ';
    
    return 0;
}
