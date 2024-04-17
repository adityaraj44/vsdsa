#include <bits/stdc++.h>

using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int n)
{
    if (root == NULL)
    {
        root = new Node(n);
        return root;
    }
    if (root->data > n)
    {
        root->left = insertIntoBST(root->left, n);
    }
    else
    {
        root->right = insertIntoBST(root->right, n);
    }
    return root;
}

void takeInput(Node *&root)
{
    int n;
    cin >> n;
    while (n != -1)
    {
        root = insertIntoBST(root, n);
        cin >> n;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
bool search(Node *root, int target)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return true;
        }
        if (temp->data > target)
        {
            temp = temp->left;
        }
        if (temp->data < target)
        {
            temp = temp->right;
        }
    }
    return false;
}

int maxBST(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

int minBST(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

Node *deleteFromBST(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        // zero child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // if at least one child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // if both child
        if (root->left != NULL && root->right != NULL)
        {
            int min = minBST(root->right);
            root->data = min;
            root->right = deleteFromBST(root->right, min);
            return root;
        }
    }
    else if (root->data < val)
    {
        root->right = deleteFromBST(root->right, val);
    }
    else
    {
        root->left = deleteFromBST(root->left, val);
    }
    return root;
}

bool isBST(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
        return false;
}

bool validateBST(Node *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

int solveKthSmallest(Node *root, int k, int &i)
{
    if (root == NULL)
    {
        return -1;
    }

    // L
    int left = solveKthSmallest(root->left, k, i);

    if (left != -1)
    {
        return left;
    }

    // R
    i++;
    if (i == k)
    {
        return root->data;
    }

    // R
    return solveKthSmallest(root->right, k, i);
}

int kthSmallest(Node *root, int k)
{
    int i = 0;
    int ans = solveKthSmallest(root, k, i);
    return ans;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the elements to be inserted to build BST" << endl;
    takeInput(root);
    // dummy data: 10 8 21 7 27 5 4 3 -1
    cout << endl;
    cout << "Printing level order traversal " << endl;
    levelOrderTraversal(root);

    cout << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);

    cout << endl;
    // find a node in bst
    cout << "Is 6 in bst: " << search(root, 6) << endl;

    root = deleteFromBST(root, 4);
    cout << "Deleted 4 from BST" << endl;

    cout << "Is this tree valid: " << validateBST(root) << endl;

    // get Kth smallest
    cout << "The third smallest is: " << kthSmallest(root, 3) << endl;

    return 0;
}