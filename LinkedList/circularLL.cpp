#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *nxtNodeAdd;

    node(int d)
    {
        this->data = d;
        this->nxtNodeAdd = NULL;
    }
};

// print
void printCLL(node *&tail)
{

    // base case
    if (tail == NULL)
    {
        cout << "Empty!" << endl;
        return;
    }

    node *temp = tail->nxtNodeAdd;
    do
    {
        cout << temp->data;
        if (temp->nxtNodeAdd != tail->nxtNodeAdd)
        {
            cout << " -> ";
        }
        temp = temp->nxtNodeAdd;
    } while (temp != tail->nxtNodeAdd);

    cout << " -> (back to head)" << endl;
}

// insert at head
void insertAtHead(node *&tail, int val)
{
    node *newNode = new node(val);
    // base case
    if (tail == NULL)
    {
        newNode->nxtNodeAdd = newNode;
        tail = newNode;
        return;
    }
    // 1 or more nodes
    newNode->nxtNodeAdd = tail->nxtNodeAdd;
    tail->nxtNodeAdd = newNode;
}
// tail
void insertAtTail(node *&tail, int val)
{

    node *newNode = new node(val);
    // base case
    if (tail == NULL)
    {
        newNode->nxtNodeAdd = newNode;
        tail = newNode;
        return;
    }
    // one or more nodes
    newNode->nxtNodeAdd = tail->nxtNodeAdd;
    tail->nxtNodeAdd = newNode;
    tail = newNode;
}
// insert at random
void insertAtRandom(node *&tail, int pos, int val)
{
    // base casse
    if (pos == 1)
    {
        insertAtHead(tail, val);
        return;
    }

    // temp = points to head
    node *temp = tail->nxtNodeAdd; // head
    node *newNode = new node(val);
    int cnt = 1;
    while (cnt < pos - 1 && temp != tail)
    {
        temp = temp->nxtNodeAdd;
        cnt++;
    }
    if (cnt < pos - 1)
    {
        cout << "Invalid position!" << endl;
        delete newNode; // Clean up the allocated memory
        return;
    }
    newNode->nxtNodeAdd = temp->nxtNodeAdd;
    temp->nxtNodeAdd = newNode;

    if (newNode->nxtNodeAdd == tail->nxtNodeAdd)
    {
        tail = newNode;
    }
}
// Deletion
// head
void delFromHead(node *&tail)
{
    // base case
    if (tail == NULL)
    {
        cout << "Empty!" << endl;
        return;
    }

    node *head = tail->nxtNodeAdd; // head node
    // 1 node
    if (head == tail)
    {
        delete head;
        tail = NULL;
        return;
    }
    // 2 or more
    tail->nxtNodeAdd = head->nxtNodeAdd;
    delete head;
}

// tail
void delFromTail(node *&tail)
{

    // base case
    if (tail == NULL)
    {
        cout << "Empty!" << endl;
        return;
    }

    node *head = tail->nxtNodeAdd; // head node
    // 1 node
    if (head == tail)
    {
        delete head;
        // two ptrs 1 must be del and other null
        tail = NULL;
        return;
    }
    node *curr = head;
    while (curr->nxtNodeAdd != tail)
    {
        curr = curr->nxtNodeAdd;
    }
    curr->nxtNodeAdd = head;
    delete tail;
    tail = curr;
}
// Delete node by value
void deleteNode(node *&tail, int value)
{
    // Empty case
    if (tail == NULL)
    {
        cout << "List is empty, please! check again" << endl;
        return;
    }

    // Non-empty
    node *prev = tail;
    node *curr = prev->nxtNodeAdd;

    // Traverse the list to find the node with the specified value
    while (curr->data != value)
    {
        prev = curr;
        curr = curr->nxtNodeAdd;

        // If we've gone full circle and the value isn't found
        if (curr == tail->nxtNodeAdd)
        {
            cout << "Value " << value << " not found in the list." << endl;
            return;
        }
    }

    prev->nxtNodeAdd = curr->nxtNodeAdd;

    // If we're deleting the only node in the list
    if (curr == prev)
    {
        tail = NULL;
    }
    // If we're deleting the tail
    else if (tail == curr)
    {
        tail = prev;
    }

    curr->nxtNodeAdd = NULL;
    delete curr;
}

int main()
{
    node *tail = NULL;

    // Insert at head
    cout << "Insert at Head" << endl;
    insertAtHead(tail, 10);
    printCLL(tail);

    insertAtHead(tail, 20);
    printCLL(tail);

    insertAtHead(tail, 30);
    printCLL(tail);

    cout << "Insert at Tail" << endl;
    insertAtTail(tail, 40);
    printCLL(tail);
    cout << "Insert at Random" << endl;
    insertAtRandom(tail, 2, 50);
    printCLL(tail);
    insertAtRandom(tail, 1, 60);
    printCLL(tail);
    insertAtRandom(tail, 5, 70);
    printCLL(tail);

    cout << "Delete from head" << endl;
    delFromHead(tail);
    printCLL(tail);
    cout << "Delete from tail" << endl;
    delFromTail(tail);
    printCLL(tail);
    cout << "Delete node with value 40" << endl;
    deleteNode(tail, 70);
    printCLL(tail);

    return 0;
}
