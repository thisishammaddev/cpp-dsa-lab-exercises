#include <iostream>
using namespace std;

// make a class to implement Circular Doubly LL
class node
{
public:
    int data;
    node *nxtPtr;
    node *prevPtr;

    // constructor to initialize the first node
    node(int d)
    {
        this->data = d;
        this->nxtPtr = NULL;
        this->prevPtr = NULL;
    }
};

// INSERTION OPERATIONS
// At beginning
void insertAtHead(node *&head, int val)
{
    // base case: no node still
    node *nodeToInsert = new node(val);
    if (head == NULL)
    {
        // 1st node ka prev or nxt ptrs both will point at the node itself
        nodeToInsert->nxtPtr = nodeToInsert;
        nodeToInsert->prevPtr = nodeToInsert;
        head = nodeToInsert;
        return;
    }
    // 1 or more node have been made
    // take the last node from head
    node *last = head->prevPtr;   // last node mill gaya
    last->nxtPtr = nodeToInsert;  // last node ka nxt newnode hoga
    nodeToInsert->prevPtr = last; // newNode ka prev last node hoga
    head->prevPtr = nodeToInsert;
    nodeToInsert->nxtPtr = head;
    head = nodeToInsert;
}
// Insert at tail
void insertAtTail(node *&head, int val)
{
    // base case: no node still
    node *nodeToInsert = new node(val);
    if (head == NULL)
    {
        // 1st node ka prev or nxt ptrs both will point at the node itself
        nodeToInsert->nxtPtr = nodeToInsert;
        nodeToInsert->prevPtr = nodeToInsert;
        head = nodeToInsert;
        return;
    }
    // 1 or more node have been made
    // last node
    node *last = head->prevPtr; // lastNode
    nodeToInsert->nxtPtr = head;
    head->prevPtr = nodeToInsert;
    last->nxtPtr = nodeToInsert;
    nodeToInsert->prevPtr = last;
}
// Insert At Rnadom
void insertAtRandomPos(node *&head, int pos, int val)
{
    node *nodeToInsert = new node(val);
    if (!head)
    {
        if (pos > 1)
        {
            return;
        }

        nodeToInsert->nxtPtr = nodeToInsert;
        nodeToInsert->prevPtr = nodeToInsert;
        head = nodeToInsert;
        return;
    }

    // base case: pos = 1
    // insert at head
    if (pos == 1)
    {
        insertAtHead(head, val);
        return;
    }

    // 2 or more nodes
    node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1 && temp->nxtPtr != head)
    {
        temp = temp->nxtPtr;
        cnt++;
    }

    // if pos is greater than the size
    node *nextNode = temp->nxtPtr;

    nodeToInsert->nxtPtr = nextNode;
    nodeToInsert->prevPtr = temp;
    temp->nxtPtr = nodeToInsert;
    nextNode->prevPtr = nodeToInsert;
    if (nextNode == head)
    {
        head->prevPtr = nodeToInsert;
    }
}
// DELETION
// FROM HEAD
void delFromHead(node *&head)
{

    // base case
    if (head == NULL)
    {
        cout << "Empty List!" << endl;
        return;
    }
    node *temp = head;
    node *last = head->prevPtr;
    last->nxtPtr = head->nxtPtr;
    head->nxtPtr->prevPtr = last;
    head = last->nxtPtr;
    delete temp;
}
// tail
void delFromTail(node *&head)
{

    // base case
    if (head == NULL)
    {
        cout << "Empty List!" << endl;
        return;
    }

    node *last = head->prevPtr; // last node
    head->prevPtr = last->prevPtr;
    last->prevPtr->nxtPtr = head;
    last = last->prevPtr;
    delete last;
}

// From Specific position
void delFromSpecificPos(node *&head, int pos)
{
    // base case
    if (head == NULL)
    {
        cout << "Empty List!" << endl;
        return;
    }

    // if 1 node
    if (pos == 1)
    {
        delFromHead(head);
        return;
    }

    node *temp = head;
    int cnt = 1;
    while (cnt < pos && temp->nxtPtr != head)
    {
        temp = temp->nxtPtr;
        cnt++;
    }

    if (cnt < pos)
    {
        return; // Invalid position
    }
    // position reached
    temp->prevPtr->nxtPtr = temp->nxtPtr;
    if (temp->nxtPtr == head)
    {
        head->prevPtr = temp->prevPtr;
    }

    temp->nxtPtr->prevPtr = temp->prevPtr;
    delete temp;
}

// print kerna hai ab
void printCDLL(node *&head)
{
    if (head == NULL)
    {
        cout << "Empty!" << endl;
        return;
    }
    node *temp = head;
    do
    {
        cout << temp->data;
        temp = temp->nxtPtr;
        if (temp != head)
        {
            cout << " <-> ";
        }
    } while (temp != head);
    cout << " <-> " << "(back to head)" << endl;
}

int main()
{
    node *head = NULL;
    cout << "Insertion At Head:" << endl;
    insertAtHead(head, 10);
    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    printCDLL(head);
    cout << "Insertion At Tail:" << endl;
    insertAtTail(head, 11);
    insertAtTail(head, 12);
    insertAtTail(head, 13);
    printCDLL(head);
    cout << "Insertion At Random Position:" << endl;
    insertAtRandomPos(head, 5, 15);
    printCDLL(head);
    insertAtRandomPos(head, 1, 6);
    printCDLL(head);
    insertAtRandomPos(head, 10, 14);
    printCDLL(head);

    // deletion
    cout << "Deletion from head: " << endl;
    delFromHead(head);
    printCDLL(head);
    cout << "Deletion from Tail: " << endl;
    delFromTail(head);
    printCDLL(head);
    cout << "Deletion from Specific Position: " << endl;
    delFromSpecificPos(head, 5);
    printCDLL(head);
    delFromSpecificPos(head, 1);
    printCDLL(head);

    return 0;
}