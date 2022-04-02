#include <iostream>
using namespace std;

void output(int (*matrix)[3]);
void triangleMatrix(int (*matrix)[3]);
void numberOfRows(int (*matrix)[3]);

int main(){
    int matrix[3][3] = {{2, 1, -2}, {-1, 0, 3}, {-3, 4, 1}};
    
    output(matrix);
    triangleMatrix(matrix);
    numberOfRows(matrix);
    
    return 0;
}

void output(int (*matrix)[3])
{
    cout << "-------------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) cout << matrix[i][j] << '\t';
        cout << endl;
    }
    return;
}

void triangleMatrix(int (*matrix)[3])
{
    for (int i = 0; i < 3; i++)
    {
        int x = matrix[i][0];
        matrix[i][0] = matrix[i][1];
        matrix[i][1] = x;
    }
    output(matrix);
    
    for (int j = 0; j < 3; j++) matrix[2][j] -= matrix[0][j] * 4;
    output(matrix);
    
    for (int j = 0; j < 3; j++) matrix[2][j] -= matrix[1][j] * 11;
    output(matrix);
}

void numberOfRows(int (*matrix)[3])
{
    int x, a = 0;
    cout << endl << "X = ";
    cin >> x;
    
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++) sum += matrix[i][j];
        if (sum / 3 < x) a++;
    }
    cout << "Number of rows: " << a << endl;
}
