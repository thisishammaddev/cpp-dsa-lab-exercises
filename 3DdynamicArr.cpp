#include <iostream>
using namespace std;

void print3Darr(int ***arr, int numOfArr, int row, int col)
{

    cout << "Printing the 3d array: " << endl;

    for (int i = 0; i < numOfArr; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{

    int row, col, numOfArrays;
    cout << "Enter the number of arrays want to create => ";
    cin >> numOfArrays;
    cout << "Enter the row size => ";
    cin >> row;
    cout << "Enter the col size => ";
    cin >> col;
    int ***arr3D = new int **[numOfArrays];

    for (int i = 0; i < row; i++)
    {
        arr3D[i] = new int *[row];
        for (int j = 0; j < col; j++)
        {
            arr3D[i][j] = new int[col];
        }
    }

    for (int i = 0; i < numOfArrays; i++)
    {
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                cout << "Enter the array's " << i + 1 << " and row's " << j + 1 << " and col's " << k + 1 << " value => ";
                cin >> arr3D[i][j][k];
            }
        }
    }

    print3Darr(arr3D, numOfArrays, row, col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            delete[] arr3D[i][j];
        }
        delete[] arr3D[i];
    }
    delete[] arr3D;

    cout << "Memory De-allocated Successfully!" << endl;

    return 0;
}