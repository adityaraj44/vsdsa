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

Node *buildTree(Node *root)
{
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;
    root = new Node(rootData);

    if (rootData == -1)
    {
        return NULL;
    }
    cout << "Enter the left child of " << rootData << endl;
    root->left = buildTree(root->left);
    cout << "Enter the right child of " << rootData << endl;
    root->right = buildTree(root->right);
    return root;
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
            // check if empty
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

// build from level order or build tree level wise
Node *
buildLevelOrderTree(Node *root)
{
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;

    root = new Node(rootData);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter the left child of " << temp->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            Node *leftChild = new Node(leftData);
            q.push(leftChild);
        }

        int rightData;
        cout << "Enter the right child of " << temp->data << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            Node *rightChild = new Node(rightData);
            q.push(rightChild);
        }
    }

    return root;
}

// InOrder traversal LNR
void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// PreOrder traversal NLR
void preOrderTraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// postOrder traversal LRN
void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void leafC(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    leafC(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    leafC(root->right, count);
}

int leafNodeCount(Node *root)
{
    int count = 0;
    leafC(root, count);
    return count;
}

// height of the binary tree
int height(Node *root)
{
    int ans;
    if (root == NULL)
    {
        return 0;
    }

    int leftAns = height(root->left);
    int rightAns = height(root->right);

    ans = max(leftAns, rightAns) + 1;
    return ans;
}

// diameter of this binary tree
pair<int, int>
diameterFast(Node *root)
{
    pair<int, int> ans;
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> leftAns = diameterFast(root->left);
    pair<int, int> rightAns = diameterFast(root->right);

    int op1 = leftAns.first;
    int op2 = rightAns.first;
    int op3 = leftAns.second + rightAns.second + 1;

    ans.first = max(op1, max(op2, op3));
    ans.second = max(leftAns.second, rightAns.second) + 1;

    return ans;
}

int diameter(Node *root)
{
    int result = diameterFast(root).first;
    return result;
}

pair<bool, int>
isBalancedFast(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> leftAns = isBalancedFast(root->left);
    pair<bool, int> rightAns = isBalancedFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition = abs(leftAns.second - rightAns.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(leftAns.second, rightAns.second) + 1;
    if (left && right && condition)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

bool isBalanced(Node *root)
{
    return isBalancedFast(root).first;
}

// is two trees identical
bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }
    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    bool leftAns = isIdentical(r1->left, r2->left);
    bool rightAns = isIdentical(r1->right, r2->right);

    bool condition = r1->data == r2->data;

    if (leftAns && rightAns && condition)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// check is SUM tree (any node has value equal to sum of val of left and right child)
pair<bool, int>
checkSumTreeFast(Node *root)
{
    pair<bool, int> ans;
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = checkSumTreeFast(root->left);
    pair<bool, int> rightAns = checkSumTreeFast(root->right);

    bool condition = (leftAns.second + rightAns.second) == root->data;

    if (leftAns.first && rightAns.first && condition)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
        ans.second = leftAns.second + rightAns.second;
    }

    return ans;
}

bool checkSumTree(Node *root)
{
    return checkSumTreeFast(root).first;
}

// alternate level order traversal in simple words
void zigzagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    bool isLeftToRight = true;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; ++i)
        {
            Node *temp = q.front();
            q.pop();
            int index = isLeftToRight ? i : size - i - 1;
            ans[index] = temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        isLeftToRight = !isLeftToRight;
        for (auto i : ans)
        {
            cout << i << " ";
        }
    }
}

void traverseLeft(Node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int>
boundaryTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);
    // bring left nodes
    traverseLeft(root->left, ans);
    // bring leaf
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    // bring right
    traverseRight(root->right, ans);

    return ans;
}

vector<int>
verticalOrderTraversal(Node *root)
{
    map<int, vector<int>> result;
    vector<int> ans;
    queue<pair<Node *, int>> q;
    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        int hd = temp.second;
        Node *frontNode = temp.first;
        result[hd].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : result)
    {
        for (auto j : i.second)
        {
            ans.push_back(j);
        }
    }
    return ans;
}

// top view of the tree (the first node we see is the final)
vector<int>
topView(Node *root)
{
    map<int, int> result;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        int hd = temp.second;
        Node *frontNode = temp.first;
        if (result.find(hd) == result.end())
        {
            result[hd] = frontNode->data;
        }
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : result)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// bottom view (what we see last is the ans from going top to bottom)
vector<int>
bottomView(Node *root)
{
    map<int, int> result;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        int hd = temp.second;
        Node *frontNode = temp.first;

        result[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : result)
    {
        ans.push_back(i.second);
    }
    return ans;
}

// left view
void solveLeft(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    solveLeft(root->left, ans, level + 1);
    solveLeft(root->right, ans, level + 1);
}

vector<int>
leftView(Node *root)
{
    vector<int> ans;
    solveLeft(root, ans, 0);
    return ans;
}

// Right view
void solveRight(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    solveRight(root->right, ans, level + 1);
    solveRight(root->left, ans, level + 1);
}

vector<int>
rightView(Node *root)
{
    vector<int> ans;
    solveRight(root, ans, 0);
    return ans;
}

// maximum sum of longest path
void solveLongestPath(Node *root, int &maxSum, int sum, int &maxLen, int len)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxSum = max(sum, maxSum);
            maxLen = len;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum += root->data;
    solveLongestPath(root->left, maxSum, sum, maxLen, len + 1);
    solveLongestPath(root->right, maxSum, sum, maxLen, len + 1);
}

int longestPathSum(Node *root)
{
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    solveLongestPath(root, maxSum, sum, maxLen, len);
    return maxSum;
}

// least common ancestor
Node *
lca(Node *root, int p, int q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == p || root->data == q)
    {
        return root;
    }

    Node *leftAns = lca(root->left, p, q);
    Node *rightAns = lca(root->right, p, q);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else
        return NULL;
}

// kpath sum (required sum can be the sum of any number of nodes and can start anywhere in the tree)
void kSum(Node *root, vector<int> &path, int targetSum, int &count)
{
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    kSum(root->left, path, targetSum, count);
    kSum(root->right, path, targetSum, count);
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; --i)
    {
        sum += path[i];
        if (sum == targetSum)
        {
            count++;
        }
    }
    path.pop_back();
    return;
}

int kSumPath(Node *root, int targetSum)
{
    vector<int> path;
    int count = 0;
    kSum(root, path, targetSum, count);
    return count;
}

// kth ancestor
Node *
solveKthAncestor(Node *root, int n, int &k)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n)
    {
        return root;
    }

    Node *leftAns = solveKthAncestor(root->left, n, k);
    Node *rightAns = solveKthAncestor(root->right, n, k);

    // check after recursion
    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int n)
{
    Node *ans = solveKthAncestor(root, n, k);
    if (ans == NULL || ans->data == n)
    {
        return -1;
    }
    else
        return ans->data;
}

// max sum of non adjacent nodes (DFS approach/recursive)
pair<int, int> solveMaxSum(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> result;
    pair<int, int> left = solveMaxSum(root->left);
    pair<int, int> right = solveMaxSum(root->right);

    result.first = root->data + left.second + right.second;
    result.second = max(left.first, left.second) + max(right.first, right.second);

    return result;
}

int maxSumNonAdjacent(Node *root)
{ 
    pair<int, int> ans = solveMaxSum(root);
    return max(ans.first, ans.second);
}

// construct binary tree from Inorder and Pre order traversal
/*
The first element of PreOrder is the root. So searching its position in InOrder array and splitting the array with the position obtained.
Applying recursion and generating the tree. Map is used to reduce the complexity for finding the position of the element in Inorder.
*/
int findPosition(int in[], int element, int start, int end)
{

    for (int i = start; i <= end; i++)
    {

        if (in[i] == element)
        {

            return i;
        }
    }
    return -1;
}

Node *solveInAndPre(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n)
{
    // base case
    if (index >= n || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = pre[index++];
    Node *root = new Node(element);
    int position = findPosition(in, element, inOrderStart, inOrderEnd);

    // recursive calls
    root->left = solveInAndPre(in, pre, index, inOrderStart, position - 1, n);
    root->right = solveInAndPre(in, pre, index, position + 1, inOrderEnd, n);

    return root;
}

Node *buildTreeInAndPre(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    // create a map to decrease time complexity
    Node *ans = solveInAndPre(in, pre, preOrderIndex, 0, n - 1, n);
    return ans;
}

// Construct binary tree from inorder and post order
Node *solveInAndPost(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n)
{
    // base case
    if (index < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = post[index--];
    Node *root = new Node(element);
    int position = findPosition(in, element, inOrderStart, inOrderEnd);

    // recursive calls
    root->right = solveInAndPost(in, post, index, position + 1, inOrderEnd, n);
    root->left = solveInAndPost(in, post, index, inOrderStart, position - 1, n);

    return root;
}

Node *buildTreeInandPost(int in[], int post[], int n)
{
    int postOrderIndex = n - 1;
    Node *ans = solveInAndPost(in, post, postOrderIndex, 0, n - 1, n);
    return ans;
}

/*
Building tree completed
*/

// Burning a binary tree
/*
    Step 1: Create a nodeToParent mapping with nodes as key and their parent as value. Return the targetNode in form of pointer
    Step 2: Burn the tree and calculate the time. Use two data structure first a map named visited to check if the element is already burned with a value type bool. Second use a queue to add current node which is burning and use visited to check burned node. Use a flag bool that keeps the record if nodes are added to queue then time++ otherwise return time.
*/
Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    // create mapping
    // return target node
    nodeToParent[root] = NULL;
    Node *res = NULL;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front->data == target)
        {
            res = front;
        }
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(Node *targetNode, map<Node *, Node *> nodeToParent)
{
    map<Node *, bool> visited; // to keep record of the burned nodes
    queue<Node *> q;           // current burning nodes

    int ans = 0;

    q.push(targetNode);
    visited[targetNode] = true;

    while (!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; ++i)
        {
            // process neighbouring nodes
            Node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }

            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    return ans;
}

int minTime(Node *root, int target)
{
    // algo:
    // step 1: create nodeToParent
    // step 2: find target node
    // step 3: burn the tree in min time

    map<Node *, Node *> nodeToParent;
    Node *targetNode = createParentMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}

/*
Morris traversal : Goal is to find the inorder traversal data in O(1) space complexity
*/

void morrisTraversalInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Node *current = root;
    while (current != NULL)
    {
        if (current->left)
        {
            Node *pred = current->left;
            while (pred->right != NULL && pred->right != current)
            {
                pred = pred->right;
            }
            if (pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }
            else
            {
                pred->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
        else
        {
            cout << current->data << " ";
            current = current->right;
        }
    }
}

// Morris traversal for preorder
void morrisTraversalPreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Node *current = root;
    while (current != NULL)
    {
        if (current->left)
        {
            Node *pred;
            pred = current->left;
            while (pred->right != NULL && pred->right != current)
            {
                pred = pred->right;
            }
            if (pred->right == NULL)
            {
                cout << current->data << " ";
                pred->right = current;
                current = current->left;
            }
            else
            {
                pred->right = NULL;
                current = current->right;
            }
        }
        else
        {
            cout << current->data << " ";
            current = current->right;
        }
    }
}
// Morris traversal for postorder
void morrisTraversalPostorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Node *current = root;
    while (current != NULL)
    {
        if (current->right)
        {
            Node *pred;
            pred = current->right;
            while (pred->left != NULL && pred->left != current)
            {
                pred = pred->left;
            }
            if (pred->left == NULL)
            {
                cout << current->data << " ";
                pred->left = current;
                current = current->right;
            }
            else
            {
                pred->left = NULL;
                current = current->left;
            }
        }
        else
        {
            cout << current->data << " ";
            current = current->left;
        }
    }
}

// Flatten a bt to Linked list using morris traversal

void flatten(Node *&root)
{
    Node *current = root;
    while (current != NULL)
    {
        if (current->left)
        {
            Node *pred = current->left;
            while (pred->right)
            {
                pred = pred->right;
            }

            pred->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}

int main()
{
    Node *root = NULL;
    //   Node *root1 = NULL;
    // building the tree
    //  1 2 4 -1 -1 5 11 -1 -1 12 -1 -1 3 6 -1 -1 7 -1 8 9 -1 -1 10 -1 -1
    root = buildTree(root);
    //   1 2 4 -1 -1 5 11 -1 -1 12 -1 -1 3 6 -1 -1 7 -1 8 -1 -1
    //   root1 = buildTree(root1);
    // print levelOrderTraversal
    cout << "The level order traversal " << endl;
    levelOrderTraversal(root);

    // build tree level wise
    //   root = buildLevelOrderTree(root);

    cout << "Inorder Traversal: ";
    inOrderTraversal(root);

    cout << endl
         << "Preorder Traversal: ";
    preOrderTraversal(root);

    cout << endl
         << "Postorder traversal: ";
    postOrderTraversal(root);

    cout << endl;
    // Number of leaf nodes present
    cout << "Leaf nodes in this binary tree are " << leafNodeCount(root) << endl;

    // Height of this binary tree
    cout << "Height of this binary tree is " << height(root) << endl;

    // diameter of this binary tree
    cout << "Diameter of this binary tree is " << diameter(root) << endl;

    // check if this tree is balanced
    cout << "This tree is balanced: " << isBalanced(root) << endl;

    // check is this tree is identical to other tree
    cout << "Is both trees identical " << isIdentical(root, root) << endl;

    // check sum tree
    cout << "Is sum tree " << checkSumTree(root) << endl;

    // zigzagTraversal
    cout << "Zigzag traversal " << endl;
    zigzagTraversal(root);
    cout << endl;

    // boundaryTraversal
    cout << "Boundary traversal " << endl;
    for (auto i : boundaryTraversal(root))
    {
        cout << i << " ";
    }
    cout << endl;

    // Vertical order Traversal
    cout << "Vertical order traversal " << endl;
    for (auto i : verticalOrderTraversal(root))
    {
        cout << i << " ";
    }
    cout << endl;

    // Top view
    cout << "Top view " << endl;
    for (auto i : topView(root))
    {
        cout << i << " ";
    }
    cout << endl;

    // Bottom view
    cout << "Bottom view " << endl;
    for (auto i : bottomView(root))
    {
        cout << i << " ";
    }
    cout << endl;

    // left view
    cout << "Left view " << endl;
    for (auto i : leftView(root))
    {
        cout << i << " ";
    }
    cout << endl;

    // Right view
    cout << "Right view " << endl;
    for (auto i : rightView(root))
    {
        cout << i << " ";
    }
    cout << endl;

    // Longest path sum
    cout << "Longest path sum of this tree is " << longestPathSum(root) << endl;

    // Least common ancestor
    cout << "Least Common Ancestor of 4 and 12 is " << lca(root, 4, 12)->data << endl;

    // kSumPath
    cout << "Number of path for the targetSum 10 is " << kSumPath(root, 10) << endl;

    // kthAncestor
    cout << "The 3rd ancestor of 12: " << kthAncestor(root, 3, 12) << endl;

    // max Sum of non adjacent nodes
    cout << "Max sum of non adjacent nodes: " << maxSumNonAdjacent(root) << endl;

    // build tree from inorder and preorder traversal data
    int in[] = {4, 2, 11, 5, 12, 1, 6, 3, 7, 9, 8, 10};
    int pre[] = {1, 2, 4, 5, 11, 12, 3, 6, 7, 8, 9, 10};
    Node *generatedRootInAndPre = buildTreeInAndPre(in, pre, 12);
    // Printing the post order traversal to check if the tree is correct
    cout << "Generating post order traversal from the Inorder and Preorder: " << endl;
    postOrderTraversal(generatedRootInAndPre);
    cout << endl;
    // build tree from inorder and preorder traversal data
    int post[] = {4, 11, 12, 5, 2, 6, 9, 10, 8, 7, 3, 1};
    Node *generatedRootInAndPost = buildTreeInandPost(in, post, 12);
    // Printing the pre order traversal to check if the tree is correct
    cout << "Generating pre order traversal from the Inorder and Postorder: " << endl;
    preOrderTraversal(generatedRootInAndPost);

    // Burning a tree
    // Minimum time to burn the tree
    cout << "Minimum time to burn the tree if target is 10: " << minTime(root, 10) << endl;

    cout << "Getting inorder traversal using Morris traversal: ";
    morrisTraversalInorder(root);
    cout << endl;
    cout << "Getting preorder traversal using Morris traversal: ";
    morrisTraversalPreorder(root);
    cout << endl;
    cout << "Getting postorder traversal using Morris traversal: ";
    morrisTraversalPostorder(root);

    // Flatten the tree to linked list
    // cout<<"Flatten tree to linked list"

    return 0;
}
