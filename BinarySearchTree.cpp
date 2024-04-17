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

Node *insertIntoBST(Node *root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        // right part
        root->right = insertIntoBST(root->right, d);
    }
    else
    {
        // left part
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
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

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// search in a BST return bool
bool search(Node *root, int val)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        if (temp->data > val)
        {
            temp = temp->left;
        }
        else
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

// deletion from a bst
Node *deleteFromBST(Node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int min = minBST(root->right);
            root->data = min;
            root->right = deleteFromBST(root->right, min);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
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
    {
        return false;
    }
}

bool validateBST(Node *root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

int solvekthSmallest(Node *root, int &i, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }
    // L
    int left = solvekthSmallest(root->left, i, k);

    if (left != -1)
    {
        return left;
    }

    // N
    i++;
    if (i == k)
    {
        return root->data;
    }

    // R
    return solvekthSmallest(root->right, i, k);
}

int kthSmallest(Node *root, int k)
{
    int i = 0;
    int ans = solvekthSmallest(root, i, k);
    return ans;
}

int solvekthLargest(Node *root, int &i, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }
    // L
    int right = solvekthLargest(root->right, i, k);

    if (right != -1)
    {
        return right;
    }

    // N
    i++;
    if (i == k)
    {
        return root->data;
    }

    // R
    return solvekthLargest(root->left, i, k);
}

int kthLargest(Node *root, int k)
{
    int i = 0;
    int ans = solvekthLargest(root, i, k);
    return ans;
}

pair<int, int> predecessorSucessor(Node *root, int key)
{
    Node *temp = root;

    int pred = -1;
    int succ = -1;

    while (temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else if (temp->data < key)
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // pred
    Node *leftTree = temp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    // succ
    Node *rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}

Node *lcaRecursive(Node *root, int p, int q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data < p && root->data < q)
    {
        return lcaRecursive(root->right, p, q);
    }

    if (root->data > p && root->data > q)
    {
        return lcaRecursive(root->left, p, q);
    }
    return root;
}

Node *lcaIterative(Node *root, Node *p, Node *q)
{

    while (root != NULL)
    {
        if (root->data < p->data && root->data < q->data)
        {
            root = root->right;
        }
        else if (root->data > p->data && root->data > q->data)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }
}

// Two sum in BST

void inOrderToArray(Node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    inOrderToArray(root->left, in);
    in.push_back(root->data);
    inOrderToArray(root->right, in);
}

void inOrderToNodeArray(Node *root, vector<Node *> &in)
{
    if (root == NULL)
    {
        return;
    }
    inOrderToNodeArray(root->left, in);
    in.push_back(root);
    inOrderToNodeArray(root->right, in);
}

bool twoSumInBST(Node *root, int target)
{
    vector<int> in;
    inOrderToArray(root, in);
    int i = 0, j = in.size() - 1;
    while (i < j)
    {
        int sum = in[i] + in[j];

        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

// flatted bst to linked list it should be sorted
// can use morris but we can use inorder traversal vector

Node *flatten(Node *root)
{
    vector<Node *> in;
    inOrderToNodeArray(root, in);
    int size = in.size();

    Node *newRoot = new Node(in[0]->data);
    Node *curr = newRoot;
    for (int i = 1; i < size; i++)
    {
        curr->left = NULL;
        curr->right = in[i];
        curr = in[i];
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

// make bst to balances bst
// find inorder, make new bst from inorder with mid as root
Node *inOrderToBST(int s, int e, vector<int> &in)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    Node *newRoot = new Node(in[mid]);
    newRoot->left = inOrderToBST(s, mid - 1, in);
    newRoot->right = inOrderToBST(mid + 1, e, in);
    return newRoot;
}

Node *balancedBST(Node *root)
{
    vector<int> in;
    inOrderToArray(root, in);
    return inOrderToBST(0, in.size() - 1, in);
}

Node *solvePreOrderToBST(vector<int> preOrder, int max, int &i)
{
    if (i >= preOrder.size() || preOrder[i] > max)
    {

        return NULL;
    }

    Node *root = new Node(preOrder[i++]);
    root->left = solvePreOrderToBST(preOrder, root->data, i);
    root->right = solvePreOrderToBST(preOrder, max, i);
    return root;
}

Node *preOrderToBST(vector<int> preOrder)
{

    int max = INT_MAX;
    int i = 0;
    return solvePreOrderToBST(preOrder, max, i);
}

// Combine two bst
//  T.C O(m+n)
// S.C O(m+n)

vector<int> mergeArrays(vector<int> &bst1, vector<int> &bst2)
{
    vector<int> ans(bst1.size() + bst2.size());
    int i = 0, j = 0;
    int k = 0;
    while (i < bst1.size() && j < bst2.size())
    {
        if (bst1[i] < bst2[j])
        {
            ans[k++] = bst1[i];
            i++;
        }
        else
        {
            ans[k++] = bst2[j];
            j++;
        }
    }

    while (i < bst1.size())
    {
        ans[k++] = bst1[i];
    }

    while (j < bst2.size())
    {
        ans[k++] = bst2[j];
    }

    return ans;
}

Node *
mergeBST(Node *root1, Node *root2)
{
    // step I: store inorder
    vector<int> bst1, bst2;
    inOrderToArray(root1, bst1);
    inOrderToArray(root2, bst2);
    // step II: merge two inorder array
    vector<int> mergedArray = mergeArrays(bst1, bst2);
    // use merged array to build bst
    return inOrderToBST(0, mergedArray.size() - 1, mergedArray);
}

// combine two bst optimised with O(H1+H2)
// convert both bst to sorted doubly linked list and merge

// S.C O(H)

void convertIntoSortedDLL(Node *root, Node *&head)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;

    convertIntoSortedDLL(root->left, head);
}

Node *mergeLinkedList(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

// make bst from sorted ll

int countNodes(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node *sortedLLintoBST(Node *&head, int n)
{
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    Node *left = sortedLLintoBST(head, n / 2);
    Node *root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLintoBST(head, n - n / 2 - 1);
    return root;
}

Node *mergeBST1(Node *root1, Node *root2)
{
    // convert bst into sorted dll
    Node *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    Node *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // merge sorted LL
    Node *head = mergeLinkedList(head1, head2);

    // convert sorted LL into bst
    return sortedLLintoBST(head, countNodes(head));
}

// max bst in a binary tree
class info
{
public:
    int max;
    int min;
    bool isBST;
    int size;
};

info solve(Node *root, int &maxSize)
{
    // base case
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, maxSize);
    info right = solve(root->right, maxSize);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.max = max(root->data, right.max);
    currNode.min = min(root->data, left.min);
    if (left.isBST && right.isBST && (root->data > left.max && root->data < right.min))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    if (currNode.isBST)
    {
        maxSize = max(maxSize, currNode.size);
    }
    return currNode;
}

int maxBSTofBT(Node *root)
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main()
{

    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);
    // dummy data: 10 8 21 7 27 5 4 3 -1

    cout << endl;

    cout << "Printing the level order traversal" << endl;
    levelOrderTraversal(root);

    cout << "Inorder Traversal: ";
    inOrder(root);

    cout << endl
         << "Preorder Traversal: ";
    preOrder(root);

    cout << endl
         << "Postorder traversal: ";
    postOrder(root);

    cout << endl;

    // inserting a value in already build Binary search tree
    root = insertIntoBST(root, 6);
    cout << "Inserted 6 in BST" << endl;

    // find a node in bst
    cout << "Is 6 in bst: " << search(root, 6) << endl;

    // minMax in bst
    cout << "Min and max in bst: " << minBST(root) << "," << maxBST(root) << endl;

    root = deleteFromBST(root, 4);
    cout << "Deleted 4 from BST" << endl;

    // check is bst is valid
    cout << "Is this tree valid: " << validateBST(root) << endl;

    // get Kth smallest
    cout << "The third smallest is: " << kthSmallest(root, 3) << endl;

    // get kth largest
    cout << "The third largest is: " << kthLargest(root, 3) << endl;

    cout << "Pred and Succ of 5: " << predecessorSucessor(root, 5).first << " " << predecessorSucessor(root, 5).second << endl;

    // get the lca of two nodes
    cout << "Least common ancestor of 5 and 27: " << lcaRecursive(root, 5, 27)->data << endl;

    // check if two sum
    cout << "Is two sum if target is 9: " << twoSumInBST(root, 9) << endl;

    // vector<int> pre = {10, 8, 7, 5, 4, 3, 21, 27};
    // Node *root1 = preOrderToBST(pre);
    // inOrder(root1);

    vector<int> in = {3, 4, 5, 7, 8, 10, 21, 27};
    Node *root2 = inOrderToBST(0, 7, in);
    levelOrderTraversal(root2);

    // root = mergeBST(root1, root2);
    // levelOrderTraversal(root2);

    cout << endl;
    cout << maxBSTofBT(root);

    return 0;
}