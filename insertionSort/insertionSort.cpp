#include <iostream>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
// insertion sort
void insertSort(int arr[], int size)
{

    for (int i = 1; i < size; i++)
    {
        // keep the first index elem and compare to all
        int currElem = arr[i];
        int j = i - 1;
        while (arr[j] > currElem && j >= 0)
        {
            // shift the jth idx to 1 place forward
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = currElem;
    }
}

int main()
{

    int arr[10] = {5, 4, 10, 2, 30, 45, 34, 14, 18, 9};

    cout << "Original Array: ";
    printArr(arr, 10);
    cout << endl
         << "Insertion Sorted Array: ";
    insertSort(arr, 10);
    printArr(arr, 10);

    return 0;
}