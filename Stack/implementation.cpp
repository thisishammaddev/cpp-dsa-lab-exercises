#include <iostream>
#include <stack>
using namespace std;

class Stack
{

public:
    int *arr;
    int size;
    int topElem;

    // constructor to initialize the stack
    Stack(int s)
    {
        this->size = s;
        arr = new int[size];
        topElem = -1;
    }

    // De-structor
    ~Stack()
    {
        delete[] arr;
    }

    // isEmpty() => to check whether stack is empty
    bool isEmpty()
    {
        // agar top elem -1 hai mtlb koi elem nahi hai
        if (topElem == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // isFull() => to check the whether stack full
    bool isFull()
    {

        if (topElem == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // push operation to push elems in stack
    void push(int elem)
    {
        // 1 - check kerle k stack full hai??
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
        }
        // 2 - agar empty hai to input kerde
        else
        {
            topElem++;
            arr[topElem] = elem;
        }
    }

    // POP() => operation returns the elem which pop from stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflows" << endl;
        }
        else
        {
            topElem--;
        }
    }

    // peek() => mean top elem dikhana hai
    int peek()
    {
        // agar top elem -1 =>
        // top wala elem >= 0 uska mtlb hai k elem hai khali nahi hai
        if (topElem >= 0)
        {
            return arr[topElem];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    // display
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            // taking a flag var to track the remaining elems
            int top = topElem;
            while (top != -1)
            {
                cout << arr[top] << " ";
                top--;
            };
            cout << endl;
        }
    }
};

int main()
{

    int size, choice, element;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack st(size);

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
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
