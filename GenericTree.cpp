// generic tree implementation

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <typename T>

class Tree
{
public:
    T data;
    vector<Tree<T> *> children;

    Tree(T data)
    {
        this->data = data;
    }

    // desctructor
    ~Tree()
    {
        for (int i = 0; i < this->children.size(); ++i)
        {
            delete children[i];
        }
    }
};

Tree<int> *takeInputLevelWise()
{
    // root element of the tree
    int rootData;
    cout << "Enter root element" << endl;
    cin >> rootData;
    Tree<int> *root = new Tree<int>(rootData);
    queue<Tree<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        Tree<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numOfChild;
        cout << "Enter the number of children of " << front->data << endl;
        cin >> numOfChild;
        for (int i = 0; i < numOfChild; ++i)
        {
            int childData;
            cout << "Enter " << i << " th child of " << front->data << endl;
            cin >> childData;
            Tree<int> *child = new Tree<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printLevelWise(Tree<int> *root)
{
    queue<Tree<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        Tree<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        for (int i = 0; i < front->children.size(); ++i)
        {
            cout << front->children[i]->data << " ";
            pendingNodes.push(front->children[i]);
        }
        cout << "\n";
    }
}

int numberOfNodes(Tree<int> *root)
{
    int countOfNodes = 1;
    for (int i = 0; i < root->children.size(); ++i)
    {
        countOfNodes += numberOfNodes(root->children[i]);
    }
    return countOfNodes;
}

int heightOfTree(Tree<int> *root)
{
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

// print at a specific level
void printAtLevel(Tree<int> *root, int k)
{
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    // recursive
    for (int i = 0; i < root->children.size(); ++i)
    {
        printAtLevel(root->children[i], k - 1);
    }
}

int leafNodeCount(Tree<int> *root)
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
void printPostOrder(Tree<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        printPostOrder(root->children[i]);
    }
    cout << root->data << " ";
}

// following from root to the last node
void printPreOrder(Tree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    for (int i = 0; i < root->children.size(); ++i)
    {
        printPreOrder(root->children[i]);
    }
}

int main()
{
    Tree<int> *root = takeInputLevelWise();
    printLevelWise(root);
    int size = numberOfNodes(root);
    cout << size << endl;
    return 0;
    delete root;
}