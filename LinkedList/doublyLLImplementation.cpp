#include <iostream>
using namespace std;

// make a class for doubly linkedList
class Node
{
public:
    int data;
    Node *prevNodeAdd;
    Node *nxtNodeAdd;

    Node(int d)
    {
        this->data = d;
        this->nxtNodeAdd = NULL;
        this->prevNodeAdd = NULL;
    }
};

// Print DLL
void printDll(Node *&head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->nxtNodeAdd != NULL)
        {
            cout << " <--> ";
        }
        temp = temp->nxtNodeAdd;
    }
    cout << " X" << endl;
}

// insert At Head
void insertAtHead(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    // base case: if no node still
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // step2: if a node exist
    newNode->nxtNodeAdd = head;
    head->prevNodeAdd = newNode;
    head = newNode;
}

// Insert at tail
void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    // base case: no node still
    if (head == NULL || tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    // step2: one or more node have been made
    tail->nxtNodeAdd = newNode;
    newNode->prevNodeAdd = tail;
    tail = newNode;
}

// Insert At postion
void insertAtRandomPos(Node *&head, Node *&tail, int pos, int val)
{

    // base case: no node
    if (pos == 1)
    {
        insertAtHead(head, tail, val);
        return;
    }

    // step2: kuch nodes exist
    int cnt = 1;
    Node *temp = head;

    while (cnt < pos - 1)
    {
        temp = temp->nxtNodeAdd;
        cnt++;
    }

    // last position reached??
    if (temp->nxtNodeAdd == NULL)
    {
        insertAtTail(head, tail, val);
        return;
    }

    // loop break node reached
    Node *newNode = new Node(val);
    newNode->nxtNodeAdd = temp->nxtNodeAdd;

    if (temp->nxtNodeAdd != NULL) // Check if the next node is not NULL
    {
        temp->nxtNodeAdd->prevNodeAdd = newNode;
    }
    temp->nxtNodeAdd = newNode;
    newNode->prevNodeAdd = temp;
}

// DELETION
// DEL from head
void delFromHead(Node *&head)
{

    // base case: Empty LL
    if (head == NULL)
    {
        cout << " Linked List is empty! " << endl;
        return;
    }

    // 1 node
    if (head->nxtNodeAdd == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    // agar 2 yn zyada node hain
    Node *temp = head;
    // head intact rakh
    head = head->nxtNodeAdd;
    // head ka prev X
    head->prevNodeAdd = NULL;
    // temp nxt X
    temp->nxtNodeAdd = NULL;
    // DEL temp
    delete temp;
}
// tail se del
void delFromTail(Node *&head, Node *&tail)
{

    // base case: Empty LL
    if (head == NULL)
    {
        cout << " Linked List is empty! " << endl;
        return;
    }

    // 1 node
    if (head->nxtNodeAdd == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    // agar 2 yn zyada nodes hain
    // two pointers approach
    Node *prev = NULL;
    Node *curr = head;
    while (curr->nxtNodeAdd != NULL)
    {
        prev = curr;
        curr = curr->nxtNodeAdd;
    }
    // until last node reached
    prev->nxtNodeAdd = NULL;
    curr->prevNodeAdd = NULL;
    delete curr;
}

void deleteFromRandomPosition(Node *&head, Node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "Empty!" << endl;
        return;
    }

    // base case 1 node
    if (pos == 1)
    {
        delFromHead(head);
        return;
    }

    int cnt = 1;
    Node *prev = NULL;
    Node *curr = head;

    while (cnt < pos && curr != NULL)
    {
        prev = curr;
        curr = curr->nxtNodeAdd;
        cnt++;
    }

    if (curr == NULL)
    {
        cout << "Position out of bounds!" << endl;
        return;
    }

    // last node
    if (curr->nxtNodeAdd == NULL)
    {
        delFromTail(head, tail);
        return;
    }

    prev->nxtNodeAdd = curr->nxtNodeAdd;
    curr->nxtNodeAdd->prevNodeAdd = prev;
    curr->nxtNodeAdd = NULL;
    curr->prevNodeAdd = NULL;
    delete curr;
}

int main()
{

    Node *node1 = new Node(20);
    // head points to node1
    Node *head = node1;
    Node *tail = node1;

    // Test insertions at head
    cout << "Insert At Head in Doubly LL: " << endl;
    insertAtHead(head, tail, 10);
    printDll(head);
    insertAtHead(head, tail, 9);
    printDll(head);
    insertAtHead(head, tail, 8);
    printDll(head);

    // Test insertions at tail
    cout << "Insert At Tail in Doubly LL: " << endl;
    insertAtTail(head, tail, 11);
    printDll(head);
    insertAtTail(head, tail, 12);
    printDll(head);
    insertAtTail(head, tail, 13);
    printDll(head);

    cout << "Insert At Random Position: " << endl;
    insertAtRandomPos(head, tail, 3, 30);
    printDll(head);
    insertAtRandomPos(head, tail, 1, 7);
    printDll(head);
    insertAtRandomPos(head, tail, 10, 14);
    printDll(head);

    // DELETION
    cout << "Deletion from head" << endl;
    delFromHead(head);
    printDll(head);
    delFromHead(head);
    printDll(head);
    cout << "Deletion from tail" << endl;
    delFromTail(head, tail);
    printDll(head);
    delFromTail(head, tail);
    printDll(head);

    cout << "Delete from random position" << endl;
    deleteFromRandomPosition(head, tail, 4);
    printDll(head);
    deleteFromRandomPosition(head, tail, 2);
    printDll(head);
    deleteFromRandomPosition(head, tail, 1);
    printDll(head);

    return 0;
}