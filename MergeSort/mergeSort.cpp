#include <iostream>
using namespace std;

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// main logic
void mergeArrays(int *arr, int start, int end)
{

    // 1- calculate the array mid
    int mid = (start + end) / 2;

    // Left Array lenght???
    // if mid  = 3; 3-0+1  = 4 elems will be in sub-left array
    int leftArrLen = mid - start + 1;
    // Left Array lenght???
    // 6 - 3 = 3 elems will be in the right-sub array
    int rightArrLen = end - mid;

    // make two dynamic arrays to copy the left and right arrays
    int *leftArr = new int[leftArrLen];
    int *rightArr = new int[rightArrLen];

    // copy elems from left array to first
    int mainIdxArrayStart = start;
    for (int i = 0; i < leftArrLen; i++)
    {
        leftArr[i] = arr[mainIdxArrayStart++];
    }

    // for right array mid will be updated
    mainIdxArrayStart = mid + 1;
    // same for right array
    for (int i = 0; i < rightArrLen; i++)
    {
        rightArr[i] = arr[mainIdxArrayStart++];
    }

    // make two ptrs to point left and right 0th values
    int idx1Val = 0;
    int idx2Val = 0;
    mainIdxArrayStart = start;
    while (idx1Val < leftArrLen && idx2Val < rightArrLen)
    {
        // now compare both arrays elems
        if (leftArr[idx1Val] < rightArr[idx2Val])
        {
            arr[mainIdxArrayStart++] = leftArr[idx1Val++];
        }
        else
        {
            arr[mainIdxArrayStart++] = rightArr[idx2Val++];
        }
    }

    // to insure both arrays sized again check separatly
    while (idx1Val < leftArrLen)
    {
        arr[mainIdxArrayStart++] = leftArr[idx1Val++];
    }
    while (idx2Val < rightArrLen)
    {
        arr[mainIdxArrayStart++] = rightArr[idx2Val++];
    }

    // now release dynamic arrays
    delete[] leftArr;
    delete[] rightArr;
}

// merge Sort Algorithm
void mergeSortAlgo(int *arr, int str, int end)
{

    // base case
    if (str >= end)
    {
        return;
    }
    int mid = (str + end) / 2;
    // left Part sort recursively
    mergeSortAlgo(arr, str, mid);

    // Right Part sort recursively
    mergeSortAlgo(arr, mid + 1, end);

    // main Logiccal function
    mergeArrays(arr, str, end);
}

int main()
{

    int Arr[10] = {5, 4, 10, 2, 30, 45, 34, 14, 18, 9};
    int size = 10;
    cout << "Original Array => ";
    printArr(Arr, size);
    cout << endl;

    mergeSortAlgo(Arr, 0, size - 1);
    cout << "Merged Sorted Array => ";
    printArr(Arr, size);

    return 0;
}