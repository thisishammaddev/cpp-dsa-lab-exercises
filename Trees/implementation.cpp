#include <iostream>
using namespace std;

class tree
{
public:
    int data;
    tree *left;
    tree *right;
    tree(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Insertion into BST
void insertion(tree *&root, int value)
{

    // base case
    if (root == NULL)
    {
        root = new tree(value);
        // root->left = root->right = NULL;
        return;
    }

    // small value
    if (value < root->data)
    {
        //    left me chala ja
        insertion(root->left, value);
    }
    // greater value
    if (value > root->data)
    {
        // right me insert kerdo
        insertion(root->right, value);
    }
}
// take input for BST
void takeInput(tree *&root)
{

    int value;
    cin >> value;

    while (value != -1)
    {
        insertion(root, value);
        cin >> value;
    }
}

// PreOrder Traversal
void preOrderTraversal(tree *&root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // ROOT -> LEFT -> RIGHT
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
// InOrder Traversal
void inOrderTraversal(tree *&root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // LEFT -> ROOT -> RIGHT
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// PostOrder Traversal
void postOrderTraversal(tree *&root)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    // LEFT -> RIGHT -> ROOT
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
// searching the BST
bool search(tree *&root, int key)
{

    // bas case
    if (root == NULL)
    {
        return false;
    }

    // agar key is less than root then left me check kerna hai
    if (root->data > key)
    {
        bool resLeft = search(root->left, key);
        return resLeft;
    }

    // agar key is greater than root then right me check kerna hai
    else
    {
        bool resRight = search(root->right, key);
        return resRight;
    }
}

// Validate the BST
bool validateBst(tree *&root, int Min, int Max)
{
    // base case
    if (root == NULL)
    {
        return true;
    }

    // checks for smaller and greater
    if (root->data >= Min && root->data <= Max)
    {
        bool leftTraverse = validateBst(root->left, Min, root->data);
        bool rightTravers = validateBst(root->right, root->data, Max);
        return leftTraverse && rightTravers;
    }
    else
        return false;
}
bool checkBst(tree *&root)
{
    // check the minimum and maximum elements
    int leftMin = INT_MIN;
    int rightMax = INT_MAX;
    return validateBst(root, leftMin, rightMax);
}

// Maximum & Minimum Elems of tree
tree *minVal(tree *root)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    // min value only exist in left part of tree
    tree *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    // NULL REACHED JUST 1 NODE AFTER

    return temp;
}
tree *maxiMumVal(tree *&root)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    // max value only exist in right part of tree
    tree *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    // NULL REACHED JUST 1 NODE AFTER

    return temp;
}

// Deletion in BST
tree *DeletionInBst(tree *&root, int key)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        // 0 child case
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child case
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            tree *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->left == NULL && root->right != NULL)
        {
            tree *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child case
        if (root->left != NULL && root->right != NULL)
        {
            // 2 cases yan to left mese maximum value le ao yn right mese min
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = DeletionInBst(root->right, mini);
            return root;
        }
    }
    // left part
    else if (root->data > key)
    {
        // mean key meri left me hai jisse del kerna hai
        root->left = DeletionInBst(root->left, key);
        return root;
    }
    else

        // key bari hai root se
        root->right = DeletionInBst(root->right, key);
    return root;
}

int main()
{
    tree *root = NULL;
    cout << "Enter the value to insert into BST: ";
    takeInput(root);

    cout << endl
         << "Printing inOrder => ";
    inOrderTraversal(root);
    cout << endl
         << "Printing preOrder => ";
    preOrderTraversal(root);
    cout << endl
         << "Printing postOrder => ";
    postOrderTraversal(root);

    if (checkBst(root))
    {
        cout << endl
             << "This is a Valid Binary Search Tree" << endl;
    }
    else
    {
        cout << endl
             << "This is an Invalid Binary Search Tree" << endl;
    }

    tree *min = minVal(root);
    cout << "Minimum Value in the BST: " << min->data << endl;
    tree *max = maxiMumVal(root);
    cout << "Maxi Value in the BST: " << max->data << endl;

    // Deletion
    tree *deletedNode = DeletionInBst(root, 50);
    inOrderTraversal(root);

    return 0;
}