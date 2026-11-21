#include <iostream>
using namespace std;

void printOneDArray(int *arr, int size)
{
    cout << "1D Dynamic array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int size;
    cout << "Enter the size: ";
    cin >> size;

    // 1D dynamic array
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i + 1 << " value: ";
        cin >> arr[i];
    }
    printOneDArray(arr, size);
    delete[] arr;
    return 0;
}