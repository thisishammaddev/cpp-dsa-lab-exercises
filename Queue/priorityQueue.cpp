#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> pq;

    // push in priority queue and stack
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    cout << "Max Heap Priority Queue" << endl;
    cout << "Size of queue: " << pq.size() << endl;
    cout << "Top element of priority queue: " << pq.top() << endl;

    while (!pq.empty())
    {
        int topElem = pq.top();
        cout << "Priority Queue elems: " << topElem << endl;
        pq.pop();

        if (pq.empty())
        {
            cout << "Queue is now empty" << endl;
        }
    }

    // min Heap
    cout << "Min Heap Priority Queue" << endl;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(6);
    minHeap.push(7);
    minHeap.push(8);
    minHeap.push(9);
    minHeap.push(10);
    cout << "Size of queue: " << minHeap.size() << endl;
    cout << "Top element of priority queue: " << minHeap.top() << endl;

    while (!minHeap.empty())
    {
        int topElem = minHeap.top();
        cout << "Priority Queue elems: " << topElem << endl;
        minHeap.pop();

        if (minHeap.empty())
        {
            cout << "Queue is now empty" << endl;
        }
    }

    return 0;
}