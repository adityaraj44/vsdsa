#include <bits/stdc++.h>
using namespace std;

// template <typename T>
// I wont use template for now

class GenTree
{
public:
    int data;
    vector<GenTree *> children;

    GenTree(int data)
    {
        this->data = data;
    }

    //  destructor and delete root at the main code
    ~GenTree()
    {
        for (int i = 0; i < this->children.size(); ++i)
        {
            delete children[i];
        }
    }
};

GenTree *takeInputLevelWise()
{
    // root elem
    int rootData;
    cout << "Enter root element" << endl;
    cin >> rootData;
    // create the root node
    GenTree *root = new GenTree(rootData);
    // a queue to add nodes to take children inputs levelwise
    queue<GenTree *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        GenTree *front = pendingNodes.front();
        pendingNodes.pop();
        int numOfChild;
        cout << "Enter number of children of " << front->data << endl;
        cin >> numOfChild;
        for (int i = 0; i < numOfChild; ++i)
        {
            int childData;
            cout << "Enter " << i << " th child of " << front->data << endl;
            cin >> childData;
            GenTree *child = new GenTree(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(GenTree *root)
{
    queue<GenTree *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        GenTree *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); ++i)
        {
            cout << front->children[i]->data << " ";
            pendingNodes.push(front->children[i]);
        }
        cout << "\n";
    }
}

int numberOfNodes(GenTree *root)
{
    int countOfNodes = 1;
    for (int i = 0; i < root->children.size(); ++i)
    {
        countOfNodes += numberOfNodes(root->children[i]);
    }
    return countOfNodes;
}

int heightOfTree(GenTree *root)
{
    // height of the tree is the distance of root to the leaf node
    int height = 1;
    for (int i = 0; i < root->children.size(); ++i)
    {
        int temp = 1 + heightOfTree(root->children[i]);
        if (temp > height)
        {
            height = temp;
        }
    }
    return height;
}

void printAtLevel(GenTree *root, int k)
{
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    // a recursive fuction
    for (int i = 0; i < root->children.size(); ++i)
    {
        printAtLevel(root->children[i], k - 1);
    }
}

int leafNodeCount(GenTree *root)
{
    int count = 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += leafNodeCount(root->children[i]);
    }
    return count;
}

// following from last node to root.. first go to the bottom
void printPostOrder(GenTree *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        printPostOrder(root->children[i]);
    }
    cout << root->data << " ";
}

// following from root to the last node
void printPreOrder(GenTree *root)
{
    // if (root == NULL)
    // {
    //     return;
    // }
    cout << root->data << endl;
    for (int i = 0; i < root->children.size(); ++i)
    {
        printPreOrder(root->children[i]);
    }
}

int main()
{
    GenTree *root = takeInputLevelWise();
    cout << heightOfTree(root) << endl;
    delete root;
}