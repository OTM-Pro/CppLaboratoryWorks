/*Задание:
Описать структуру с именем STUDENT, содержащую следующие поля:
- фамилия и инициалы;
- номер группы;
- успеваемость (массив из пяти элементов).
Написать программу, выполняющую следующие действия:
1) заполнение массива, состоящего из десяти структур типа STUDENT,
записи должны быть упорядочены по возрастанию номера группы;
2) вывод на дисплей фамилий и номеров групп для всех студентов, включенных в массив,
если средний балл студента больше чем 3.0, если таких студентов нет, вывести соответствующее сообщение.*/

#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <random>
using namespace std;

struct STUDENT
{
    string FIO;
    int group;
    int perf[5];
} arr[10];

int main()
{
    mt19937 mersenne(static_cast<unsigned int>(time(0)));
    
    for (int i = 0; i < 10; i++)
    {
        arr[i].FIO = "Name";
        arr[i].group = mersenne() % 10000;
        for (int j = 0; j < 5; j++) arr[i].perf[j] = (mersenne() % 10 - 1) / 2 + 1;
    }
    cout << "Array:" << endl;
    
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i].FIO << '\t' << arr[i].group << '\t';
        for (int j = 0; j < 5; j++) cout << arr[i].perf[j] << ' ';
        cout << endl;
    }
    
    for (int i = 0; i < 9; i++) for (int j = 0; j < 10 - (i + 1); j++) if (arr[j].group > arr[j + 1].group)
    {
        STUDENT buf = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = buf;
    }
    cout << endl << "Sorted array:" << endl;
    
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i].FIO << '\t' << arr[i].group << '\t';
        for (int j = 0; j < 5; j++) cout << arr[i].perf[j] << ' ';
        cout << endl;
    }
    
    bool noStud = true;
    cout << endl << "Students:" << endl;
    for (int i = 0; i < 10; i++)
    {
        float sum = 0;
        for (int j = 0; j < 5; j++) sum += arr[i].perf[j];
        
        if (sum / 5 > 3)
        {
            noStud = false;
            cout << arr[i].FIO << '\t' << arr[i].group << '\t';
            
            for (int j = 0; j < 5; j++) cout << arr[i].perf[j] << ' ';
            cout << '\t' << sum / 5 << endl;
        }
    }
    if (noStud) cout << "No students!";
    
    return 0;
}
