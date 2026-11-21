#include <iostream>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Bubble Sort
void bubbleSortAlgorigthm(int arr[], int size)
{
    int tc = 0;
    // comparing with adjacend elems
    for (int i = 0; i < size; i++)
    {
        tc++;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                // store the 1st idx var in temporary var
                int tempVar = arr[j];
                arr[j] = arr[i];
                arr[i] = tempVar;
            }
            tc++;
        }
    }

    cout << endl
         << "Time complexity is: O(" << tc << ")" << endl;
}

// Optimized Bubble Sort Algo
void bubbleSortOptimizedAlgo(int arr[], int n)
{
    // base case
    // if 0 or 1 elem already sorted
    int tc = 0;
    if (n == 0 || n == 1)
    {
        // cout << endl
        //      << "Time complexity is: O(" << tc << ")" << endl;
        return;
    }

    // Recusive call for sort
    // solve one case byself and other will be sorted by recursion
    for (int i = 0; i < n - 1; i++)
    {
        tc++;
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            // arr[i] = arr[i] ^ arr[i + 1];
            // arr[i + 1] = arr[i] ^ arr[i + 1];
            // arr[i] = arr[i] ^ arr[i + 1];
        }
    }
    cout << endl
         << "Time complexity is: O(" << tc << ")" << endl;
    // recursive relation
    bubbleSortOptimizedAlgo(arr, n - 1);
}

int main()
{
    int arr[10] = {5, 4, 10, 2, 30, 45, 34, 14, 18, 9};

    cout << "Original Array: ";
    printArr(arr, 10);
    cout << endl
         << "Bubble Sorted Array: ";
    // bubbleSortAlgorigthm(arr, 10);
    bubbleSortOptimizedAlgo(arr, 10);
    printArr(arr, 10);

    return 0;
}