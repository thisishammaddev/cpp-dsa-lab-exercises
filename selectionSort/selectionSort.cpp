#include <iostream>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// selection sort
void selectionSortAlgo(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        // take the ith idx as minElem and compare with remaings
        int minIdx = i;
        int j = i + 1;
        for (; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
}

int main()
{
    int arr[10] = {5, 4, 10, 2, 30, 45, 34, 14, 18, 9};

    cout << "Original Array: ";
    printArr(arr, 10);
    cout << endl
         << "Selection Sorted Array: ";
    selectionSortAlgo(arr, 10);
    printArr(arr, 10);
    return 0;
}