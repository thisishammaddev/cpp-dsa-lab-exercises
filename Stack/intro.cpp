#include <iostream>
using namespace std;

// Stack implementation
class Stack
{

    // members
public:
    int *arr;
    int size;
    int top;

    // constructor to initialize the stack
    Stack(int s)
    {
        this->size = s;
        arr = new int[size];
        top = -1;
    }
    // De-structor
    ~Stack()
    {
        delete[] arr;
    }

    // Push() => Insert elems
    void push(int elem)
    {
        // check for even a single space available
        // size - top > 1 single space = 5 - (-1) > 1 = 5 + 1 =6>1
        // top = 1; 5 -1 > 1, 4 > 1..... 1>1 false
        if (size - top > 1)
        {
            top++;
            arr[top] = elem;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    // POP() => elem bahir nikalo
    void pop()
    {
        // check agar single elem b para hai to pop ker
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    // peak() => top elem dikhao
    int peek()
    {

        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    // isFull() => check karo stack overflow
    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // isEmpty() => empty hai??
    bool isEmpty()
    {

        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // display()
    void display()
    {
        if (top == -1)
        {
            cout << "Stack Empty" << endl;
        }
        else
        {
            cout << "Stack Elements: " << endl;
            int tempTop = top;
            while (tempTop != -1)
            {
                cout << arr[tempTop] << " ";
                tempTop--;
            };
            cout << endl;
        }
    }
};

int main()
{

    int size, choice, element;
    cout << "Enter the stack size: ";
    cin >> size;

    Stack st(size);

    // aik dafa to puchna hi hai
    do
    {
        // Menu for user choice
        cout << endl
             << "***** Stack Operations Menu *****" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Push operation
            cout << "Enter element to push: ";
            cin >> element;
            st.push(element);
            break;

        case 2:
            // Pop operation
            st.pop();
            break;

        case 3:
            // Peek operation
            cout << "Top element is: " << st.peek() << endl;
            break;

        case 4:
            // Display stack elements
            cout << "Stack elements: ";
            st.display();
            break;

        case 5:
            // Exit
            cout << "Exiting the Stack..." << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}