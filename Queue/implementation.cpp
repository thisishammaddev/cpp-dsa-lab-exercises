#include <iostream>
using namespace std;

// implementation of queue
class Queue
{

public:
    int *arr;
    int size;
    // front => to pop() elem from front
    // rear => to insert elem!!
    int front;
    int rear;

    // constructor to initialize
    Queue(int s)
    {
        this->size = s;
        arr = new int[size];
        rear = 0;
        front = 0;
    }

    // Destructor to free allocated memory
    ~Queue()
    {
        delete[] arr;
    }

    // Operations

    // enqueue() => push elems
    void enqueue(int elem)
    {
        // check for space available
        if (rear == size)
        {
            cout << "QUEUE is full!" << endl;
        }

        else
        {
            arr[rear] = elem;
            rear++;
        }
    }

    // dequeue() => pop elems
    int deQueue()
    {
        // single elem b hai to qeQueue kerna hai
        // check for empty
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    // peek() => top elem
    int peek()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    // isFull() => to check whether queue is full
    bool isFull()
    {

        if (rear == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // isEmpty()
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // display() => Show all elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i < rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size, choice, element;

    cout << "Enter the size of the queue: ";
    cin >> size;
    Queue q(size);

    do
    {
        cout << endl
             << "***** Queue Operations Menu *****" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Check if Empty" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to enqueue: ";
            cin >> element;
            q.enqueue(element);
            break;

        case 2:
            cout << "Dequeued element: " << q.deQueue() << endl;
            break;

        case 3:
            cout << "Front element: " << q.peek() << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isFull())
                cout << "Queue is full!" << endl;
            else
                cout << "Queue is not full!" << endl;
            break;

        case 6:
            if (q.isEmpty())
                cout << "Queue is empty!" << endl;
            else
                cout << "Queue is not empty!" << endl;
            break;

        case 7:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}