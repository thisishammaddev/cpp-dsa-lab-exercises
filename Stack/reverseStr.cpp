#include <iostream>
#include <stack>
using namespace std;

class Stack
{
public:
    char *arr; // Change from int* to char* to store characters
    int size;
    int topElem;

    // Constructor to initialize the stack
    Stack(int s)
    {
        this->size = s;
        arr = new char[size]; // Update to char
        topElem = -1;
    }

    // Destructor
    ~Stack()
    {
        delete[] arr;
    }

    // isEmpty() => to check whether stack is empty
    bool isEmpty()
    {
        return topElem == -1;
    }

    // isFull() => to check whether stack is full
    bool isFull()
    {
        return topElem == size - 1;
    }

    // Push operation to push elements into the stack
    void push(char elem) // Change int to char
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
        }
        else
        {
            topElem++;
            arr[topElem] = elem;
        }
    }

    // Pop operation removes the top element from the stack
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

    // Peek operation returns the top element of the stack
    char peek() // Change return type to char
    {
        if (topElem >= 0)
        {
            return arr[topElem];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return '\0';
        }
    }

    // Display the elements in the stack
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            int tempTop = topElem;
            while (tempTop != -1)
            {
                cout << arr[tempTop] << " ";
                tempTop--;
            }
            cout << endl;
        }
    }
};

int main()
{
    // Reverse the string
    string str = "Virat";

    int strLen = str.length();
    // Create a stack object

    Stack st(strLen);

    // Push every character of the string onto the stack
    for (int i = 0; i < strLen; i++)
    {
        st.push(str[i]);
    }

    // Create a new string to store the reversed string
    string revStr = "";

    while (!st.isEmpty())
    {
        // Get the top element
        revStr.push_back(st.peek());

        // Pop the top element
        st.pop();
    }
    cout << "Original String: " << str << endl;
    cout << "Reverse of string: " << revStr << endl;

    return 0;
}
