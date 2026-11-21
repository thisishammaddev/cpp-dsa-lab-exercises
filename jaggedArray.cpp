#include <iostream>
using namespace std;

int main()
{

    // Jagged Array
    int *jaggedArray[4];

    jaggedArray[0] = new int[2]{1, 2};
    jaggedArray[1] = new int[3]{3, 4, 5};
    jaggedArray[2] = new int[4]{6, 7, 8, 9};
    jaggedArray[3] = new int[5]{10, 11, 12, 13, 14};

    cout << "Printing the jagged array: " << endl;
    // print jagged array
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < i + 2; j++)
        {
            cout << jaggedArray[i][j] << " ";
        }
        cout << endl;
    }

    // de-allocate memory
    for (int i = 0; i < 4; i++)
    {
        delete[] jaggedArray[i];
    }

    return 0;
}