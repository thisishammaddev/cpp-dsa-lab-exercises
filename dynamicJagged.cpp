#include <iostream>
using namespace std;

int main()
{

    int row;
    cout << "Enter the number of rows of array: ";
    cin >> row;

    // array to store cols corresponding to the row
    int *noOfCols = new int[row];
    // jagged array
    int **jaggedArr = new int *[row];

    // take the no. of cols dynamically
    for (int i = 0; i < row; i++)
    {
        cout << "Enter the no. of cols in row " << i << ": ";
        cin >> noOfCols[i];
        jaggedArr[i] = new int[noOfCols[i]];
    }

    // taking the i/p
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < noOfCols[i]; j++)
        {
            cout << "Row " << i << ":- Enter the value " << i * noOfCols[i] + j << ": ";
            cin >> jaggedArr[i][j];
        }
    }

    // print the jagged array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < noOfCols[i]; j++)
        {
            cout << jaggedArr[i][j] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}