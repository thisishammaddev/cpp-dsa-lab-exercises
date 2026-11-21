#include <iostream>
#include <stack>
using namespace std;

// BST implementational Data Structure
class node
{

public:
    int data;
    node *left;
    node *right;
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// InOrder Traversal using stack = L - N - R
void inOrderTraversal(node *&root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // 1 - initialize empty stack
    stack<node *> st;
    // curr tot root
    node *current = root;

    while (!st.empty() || current != NULL)
    {
        while (current != NULL)
        {
            st.push(current);
            // left me jaate jao
            current = current->left;
        }
        // null reached top ko nikalo
        current = st.top();
        st.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

// Pre Order Traversal Using stack = N - L -R
void preOrderTraversal(node *&root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // 1 - make an empty stack
    stack<node *> st;
    // 2 - push the root node
    st.push(root);

    while (!st.empty())
    {
        node *top = st.top();
        st.pop();
        cout << top->data << " ";

        // check if left or right nodes exist or not??
        if (top->right)
        {
            st.push(top->right);
        }
        if (top->left)
        {
            st.push(top->left);
        }
    }
}

// PostOrder = L - R - N
void postOrderTraversal(node *&root)
{
    // Base case
    if (root == NULL)
    {
        return;
    }

    // Create an empty stack
    stack<node *> st;

    do
    {
        // Traverse the left subtree
        while (root != NULL)
        {
            if (root->right != NULL) // Push right child if it exists
                st.push(root->right);
            st.push(root);     // Push current node
            root = root->left; // Move to the left child
        }

        // Pop an item from the stack
        root = st.top();
        st.pop();

        // If the popped item has a right child and the right child is at the top of the stack
        if (!st.empty() && root->right == st.top())
        {
            st.pop();           // Remove the right child
            st.push(root);      // Push the root back
            root = root->right; // Set root as root's right child
        }
        else
        {
            // Print the root's data
            cout << root->data << " ";
            root = NULL; // Mark root as processed
        }

    } while (!st.empty());
}

// postOrder Using two stacks
void postOrderTwoStacks(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    // make two empty stacks
    stack<node *> st1, st2;
    // push root to stack1
    st1.push(root);
    while (!st1.empty())
    {
        // top from stack 1 and push to stack2
        node *top = st1.top();
        st1.pop();
        st2.push(top);

        if (top->left)

            st1.push(top->left);

        if (top->right)

            st1.push(top->right);
    }
    while (!st2.empty())
    {
        node *value = st2.top();
        cout << value->data << " ";
        st2.pop();
    }
}

int main()
{

    node *root = new node(43);
    root->left = new node(10);
    root->right = new node(79);
    root->left->left = new node(9);
    root->left->right = new node(12);
    root->left->right->left = new node(11);
    root->right->left = new node(54);
    root->right->right = new node(90);
    root->right->left->left = new node(50);

    cout << "Printing the PreOrder Traversals: ";
    preOrderTraversal(root);
    cout << endl
         << "Printing the InOrder Traversals: ";
    inOrderTraversal(root);
    cout << endl
         << "Printing the PostOrder Traversals: ";
    postOrderTraversal(root);
    cout << endl
         << "Printing the PostOrder Traversals Using Two Stacks: ";
    postOrderTwoStacks(root);

    return 0;
}