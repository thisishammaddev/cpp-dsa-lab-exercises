#include <iostream>
using namespace std;

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Partition Algorithm
int partitionAlgo(int *arr, int start, int end)
{

    // conclude a pivot point
    int pivot = arr[start];

    int cnt = 0;
    // put the pivot to its right place
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }
    // right place found for pivot idx
    int pivotIdx = start + cnt;
    // now swaping the pivot elems to its right position
    swap(arr[pivotIdx], arr[start]);

    // now make a partition
    // leftPart < pivot < rightPart

    int idx1 = start;
    int idx2 = end;
    while (idx1 < pivotIdx && idx2 > pivotIdx)
    {
        while (arr[idx1] <= pivot)
        {
            idx1++;
        }
        while (arr[idx2] > pivot)
        {
            idx2--;
        }
        // now mean left part has a greater elem than pivot so swap it
        if (idx1 < pivotIdx && idx2 > pivotIdx)
        {
            swap(arr[idx1++], arr[idx2--]);
        }
    }

    return pivotIdx;
}

// Quick Sort
void quickSortAlgo(int *arr, int start, int end)
{

    // base case
    if (start >= end)
    {
        return;
    }

    // make partition
    int partition = partitionAlgo(arr, start, end);

    // left & right recursive calss
    quickSortAlgo(arr, start, partition - 1);

    // right
    quickSortAlgo(arr, partition + 1, end);
}

int main()
{

    int Arr[10] = {5, 4, 10, 2, 30, 45, 34, 14, 18, 9};
    int size = 10;
    cout << "Original Array => ";
    printArr(Arr, size);
    cout << endl;
    quickSortAlgo(Arr, 0, size - 1);
    cout << "Quick Sorted Array => ";
    printArr(Arr, size);

    return 0;
}