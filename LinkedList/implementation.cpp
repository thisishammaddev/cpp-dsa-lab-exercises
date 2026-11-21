#include <iostream>
using namespace std;

// class to create a Node
class Node
{
public:
    int data;
    // Pointer of Node(User-Define DT) to store next Node Address
    Node *nxtAdd;

    // Constructor to intit values
    Node(int d)
    {
        this->data = d;
        this->nxtAdd = NULL;
    }
};

// Insert At Head
void insertAtHead(Node *&head, int val)
{

    // Base case
    if (head == NULL)
    {
        // mean koi node nahi bna
        insertAtHead(head, val);
        return;
    }

    // if One or more node has been created
    Node *newNode = new Node(val);
    newNode->nxtAdd = head;
    head = newNode;
}
// Insert At Tail
void insertAtTail(Node *&tail, int val)
{

    // Base case
    if (tail == NULL)
    {
        // mean koi node nahi bna
        tail = new Node(val);
        return;
    }

    // if One or more node has been created
    Node *newNode = new Node(val);

    Node *temp = tail;
    while (temp->nxtAdd != NULL)
    {
        // traver kerta ja
        temp = temp->nxtAdd;
    }
    // loop se bahir last node mill gaya hoga
    temp->nxtAdd = newNode;
    tail = newNode;
}

// insert At Random Position
void insertAtRandPosition(Node *&head, Node *&tail, int pos, int val)
{

    // base case
    if (pos == 1)
    {
        insertAtHead(head, val);
        return;
    }

    // make a temp Node
    Node *temp = head;
    int cnt = 1;
    // pos = 3, node-> 1, 2 agay 3 add kerna hai
    // cnt == pos-1
    while (cnt < pos - 1)
    {
        temp = temp->nxtAdd;
        cnt++;
    }

    // if last position
    if (temp->nxtAdd == NULL)
    {
        insertAtTail(tail, val);
        return;
    }

    // desired Postion reached

    Node *nodeToInsert = new Node(val);
    nodeToInsert->nxtAdd = temp->nxtAdd;
    temp->nxtAdd = nodeToInsert;
}

// DELETE FUNCTION
Node *delFromHead(Node *&head)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head;
    // point head to next
    head = head->nxtAdd;
    delete temp;

    return head;
}

Node *delFromTail(Node *&head)
{

    // base case
    if (head == NULL)
    {
        return NULL;
    }
    // if one Node Del it
    if (head->nxtAdd == NULL)
    {
        // mean 1 node hai
        delete head;
        return NULL;
    }

    // two pointer lele
    // Floyd Cycle Detectio algo
    // Hare and Taretoise algo
    Node *prev = NULL;
    Node *curr = head;

    while (curr->nxtAdd != NULL)
    {
        prev = curr;
        curr = curr->nxtAdd;
    }

    delete curr;
    prev->nxtAdd = NULL;

    return prev;
}

// Del random Pos
Node *deleteRandNode(Node *&head, int position)
{
    // base case for empty
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return NULL;
    }

    // Deleting the first node (head node)
    if (position == 1)
    {
        Node *temp = head;
        head = head->nxtAdd;
        temp->nxtAdd = NULL;
        delete temp;
        return head;
    }
    else
    {
        // Deleting from middle or end
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position && curr != NULL)
        {
            prev = curr;
            curr = curr->nxtAdd;
            cnt++;
        }

        // If the position is greater than the length of the list
        if (curr == NULL)
        {
            cout << "Position out of bounds!" << endl;
            return head;
        }

        prev->nxtAdd = curr->nxtAdd;
        curr->nxtAdd = NULL;
        delete curr;

        return head;
    }
}

// Node present hai k nahi
// search
bool isPresent(Node *&head, int val)
{

    if (head == NULL)
    {
        return false;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->nxtAdd;
    }
    return false;
}

// Size of LL
int sizeOfLL(Node *head)
{

    // base case
    int cnt = 0;
    if (head == NULL)
    {
        return cnt;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->nxtAdd;
    }

    return cnt;
}

// Concatenation == Merge LL
// Recursive Approach
Node *concatTwoLinkedList(Node *linkedListOne, Node *linkedListTwo)
{

    // base case
    if (linkedListOne == NULL)
    {
        return linkedListTwo;
    }
    if (linkedListTwo == NULL)
    {
        return linkedListOne;
    }

    // aik case me solve ker leta hun baki recursive
    // recursive relation
    Node *result = NULL;

    // first sort the data
    if (linkedListOne->data <= linkedListTwo->data)
    {
        result = linkedListOne;
        result->nxtAdd = concatTwoLinkedList(linkedListOne->nxtAdd, linkedListTwo);
    }
    else
    {
        result = linkedListTwo;
        result->nxtAdd = concatTwoLinkedList(linkedListOne, linkedListTwo->nxtAdd);
    }
    return result;
}

// Print the LL
void print(Node *&head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->nxtAdd;
    }
    cout << "X" << endl;
}

int main()
{

    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    Node *mergedList = NULL;

    int choice, val, pos;
    bool running = true;

    while (running)
    {
        cout << endl
             << "*******Singly Linked List Implementation*******" << endl;
        cout << "1. Insert at Head (List 1): " << endl;
        cout << "2. Insert at Tail (List 1): " << endl;
        cout << "3. Insert at Random Position (List 1): " << endl;
        cout << "4. Delete from Head (List 1): " << endl;
        cout << "5. Delete from Tail (List 1): " << endl;
        cout << "6. Delete from Random Position (List 1): " << endl;
        cout << "7. Concatenate List 1 and List 2: " << endl;
        cout << "8. Print List 1: " << endl;
        cout << "9. Print Merged List: " << endl;
        cout << "10. Size of LinkedList: " << endl;
        cout << "11. Existing... " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> val;
            if (head1 == NULL)
            {
                head1 = new Node(val);
                tail1 = head1;
            }
            else
            {
                insertAtHead(head1, val);
            }
            break;

        case 2:
            cout << "Enter value to insert at tail: ";
            cin >> val;
            if (head1 == NULL)
            {
                head1 = new Node(val);
                tail1 = head1;
            }
            else
            {
                insertAtTail(tail1, val);
            }
            break;

        case 3:
            cout << "Enter position and value to insert: ";
            cin >> pos >> val;
            if (head1 == NULL)
            {
                head1 = new Node(val);
                tail1 = head1;
            }
            else
            {
                insertAtRandPosition(head1, tail1, pos, val);
            }
            break;

        case 4:
            head1 = delFromHead(head1);
            break;

        case 5:
            delFromTail(head1);
            break;

        case 6:
            cout << "Enter position to delete: ";
            cin >> pos;
            deleteRandNode(head1, pos);
            break;

        case 7:
            cout << "Enter values for List 2 (end with -1): ";
            while (true)
            {
                cin >> val;
                if (val == -1)
                    break;
                if (head2 == NULL)
                {
                    head2 = new Node(val);
                    tail2 = head2;
                }
                else
                {
                    insertAtTail(tail2, val);
                }
            }
            mergedList = concatTwoLinkedList(head1, head2);
            cout << "Merged Linked List!" << endl;
            break;

        case 8:
            cout << "List 1: ";
            print(head1);
            break;

        case 9:
            cout << "Merged List: ";
            print(mergedList);
            break;

        case 10: // Size of List 1
            cout << "Size of List 1: " << sizeOfLL(head1) << endl;
            break;

        case 11:
            running = false;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    return 0;
}