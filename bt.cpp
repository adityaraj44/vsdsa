#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        { // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            { // queue still has some child nodes
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

// code for reverse level order traversal hw

// in order
void inOrderTraversal(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// preorder
void preOrderTraversal(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// post order
void postOrderTraversal(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void *buildFromLevelOrder(node *&root) // this can also be said that this function takes BT input level wise
{
    queue<node *> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
// leaf node count using inorder traversal
void in(node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    in(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    in(root->right, count);
}

int leafNodeCount(node *root)
{
    int count = 0;
    in(root, count);
    return count;
}

// height of the binary tree
// comparing subtrees

int height(node *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

pair<int, int> diameterFast(node *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);
    int op1 = left.first;
    int op2 = right.first;

    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

int diameter(node *root)
{
    // bad approach with o(n^2) complexity
    // if (root == NULL)
    // {
    //     return 0;
    // }
    // int op1 = diameter(root->left);
    // int op2 = diameter(root->right);
    // int op3 = height(root->left) + height(root->right) + 1;

    // int ans = max(op1, (max(op2, op3)));
    return diameterFast(root).first;
}

pair<bool, int> isBalancedFast(node *root)
{
    // base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

bool isBalancedTree(node *root)
{
    return isBalancedFast(root).first;
}

bool isIdentical(node *r1, node *r2)
{
    // base case
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }
    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    bool leftA = isIdentical(r1->left, r2->left);
    bool rightA = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if (leftA && rightA && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

pair<bool, int> isSumTreeFast(node *root)
{
    // base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    // leaf node
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool isleft = leftAns.first;
    bool isright = rightAns.first;

    bool condn = root->data == (leftAns.second + rightAns.second);

    pair<bool, int> ans;
    if (isleft && isright && condn)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

bool isSumTree(node *root)
{
    return isSumTreeFast(root).first;
}

vector<int> zigZagTraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return result;
    }
    bool leftToRight = true;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        // level process
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; ++i)
        {
            node *front = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            ans[index] = front->data;
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
        // direction change
        leftToRight = !leftToRight;
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

// boundary traversal
void traverseLeft(node *root, vector<int> &ans)
{
    // base case
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

void traverseLeaf(node *root, vector<int> &ans)
{
    // base case
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

void traverseRight(node *root, vector<int> &ans)
{
    // base case
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

    // store
    ans.push_back(root->data);
}

vector<int> boundary(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // left part print/store
    traverseLeft(root->left, ans);
    // traverse leaf nodes
    // left subtree
    traverseLeaf(root->left, ans);

    // right subtree
    traverseLeaf(root->right, ans);

    // traverse right
    traverseRight(root->right, ans);

    return ans;
}

// vertical traversal
vector<int> verticalOrderTraversal(node *root)
{
    map<int, vector<int>> nodes;
    queue<pair<node *, int>> q;
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second;

        nodes[hd].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {

            ans.push_back(j);
        }
    }
    return ans;
}

vector<int> topView(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> nodes;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second;
        // if one value is present to hd then do nothing
        if (nodes.find(hd) == nodes.end())
        {
            nodes[hd] = frontNode->data;
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
    for (auto i : nodes)
    {
        ans.push_back(i.second);
    }
    return ans;
}
vector<int> bottomView(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> nodes;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second;
        // if one value is present to hd then do nothing

        nodes[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : nodes)
    {
        ans.push_back(i.second);
    }
    return ans;
}

void solveLeft(node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    // we entered into new level
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    solveLeft(root->left, ans, level + 1);
    solveLeft(root->right, ans, level + 1);
}

vector<int> leftView(node *root)
{
    vector<int> ans;
    solveLeft(root, ans, 0);
    return ans;
}

void solveRight(node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    // we entered into new level
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    solveRight(root->right, ans, level + 1);
    solveRight(root->left, ans, level + 1);
}

vector<int> rightView(node *root)
{
    vector<int> ans;
    solveRight(root, ans, 0);
    return ans;
}

void solveLongPath(node *root, int sum, int &maxSum, int len, int &maxLen)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum = sum + root->data;
    solveLongPath(root->left, sum, maxSum, len + 1, maxLen);
    solveLongPath(root->right, sum, maxSum, len + 1, maxLen);
}

// tc O(N)
// sc O(H)
int sumOfLongRootToLeafPath(node *root)
{
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    solveLongPath(root, sum, maxSum, len, maxLen);

    return maxSum;
}

// lowest common ancestor
// tc O(N)
// sc O(H)
node *lowerCommonAncestor(node *root, int n1, int n2)
{
    //  base caes
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    node *leftAns = lowerCommonAncestor(root->left, n1, n2);
    node *rightAns = lowerCommonAncestor(root->right, n1, n2);

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
    {
        return NULL;
    }
}

void solveKpath(node *root, int k, int &count, vector<int> path)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);
    // left
    solveKpath(root->left, k, count, path);
    // right
    solveKpath(root->right, k, count, path);

    // check for ksum in vector
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}

int kSumPath(node *root, int k)
{
    vector<int> path;
    int count = 0;
    solveKpath(root, k, count, path);
    return count;
}

// kth ancestor in a tree
node *solveKthAncestor(node *root, int &k, int n)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n)
    {
        return root;
    }
    node *leftAns = solveKthAncestor(root->left, k, n);
    node *rightAns = solveKthAncestor(root->right, k, n);

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
int kthAncestor(node *root, int k, int n)
{
    node *ans = solveKthAncestor(root, k, n);
    if (ans == NULL || ans->data == n)
    {
        return -1;
    }
    else
        return ans->data;
}

pair<int, int> solveMaxSum(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> leftAns = solveMaxSum(root->left);
    pair<int, int> rightAns = solveMaxSum(root->right);

    pair<int, int> result;
    result.first = root->data + leftAns.second + rightAns.second;
    result.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

    return result;
}

int getMaxSum(node *root)
{
    pair<int, int> ans = solveMaxSum(root);
    return max(ans.first, ans.second);
}

int main()
{
    node *root = NULL;
    // buildFromLevelOrder(root);
    // creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 2 4 -1 -1 5 11 -1 -1 12 -1 -1 3 6 -1 -1 7 -1 8 9 -1 -1 10 -1 -1
    // level order
    cout << "Printing level order traversal output " << endl;
    levelOrderTraversal(root);

    // inorder
    cout << "Printing in order traversal " << endl;
    inOrderTraversal(root);

    // pre order
    cout << endl
         << "Printing pre order traversal " << endl;
    preOrderTraversal(root);

    // post order
    cout << endl
         << "Printing post order traversal " << endl;
    postOrderTraversal(root);

    // // leaf node count
    // cout << endl
    //      << "Leaf nodes : " << leafNodeCount(root);

    cout << endl
         << "Printing height " << height(root) << endl;
    cout << "Printing Diameter " << diameter(root) << endl;
    cout << "Is tree balanced " << isBalancedTree(root) << endl;
    cout << "Is sumTree " << isSumTree(root) << endl;
    cout << "Zigzag traversal " << endl;

    vector<int> ans = zigZagTraversal(root);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }

    cout << endl
         << "Boundary Traversal " << endl;
    vector<int> ans1 = boundary(root);
    for (int i = 0; i < ans1.size(); ++i)
    {
        cout << ans1[i] << " ";
    }

    cout << endl
         << "Vertical order traversal " << endl;
    vector<int> ans2 = verticalOrderTraversal(root);
    for (int i = 0; i < ans2.size(); ++i)
    {
        cout << ans2[i] << " ";
    }

    cout << endl
         << "Top view" << endl;
    vector<int> ans3 = topView(root);
    for (int i = 0; i < ans3.size(); ++i)
    {
        cout << ans3[i] << " ";
    }

    cout << endl
         << "Bottom view" << endl;
    vector<int> ans4 = bottomView(root);
    for (int i = 0; i < ans4.size(); ++i)
    {
        cout << ans4[i] << " ";
    }

    cout << endl
         << "Left view" << endl;
    vector<int> ans5 = leftView(root);
    for (int i = 0; i < ans5.size(); ++i)
    {
        cout << ans5[i] << " ";
    }

    cout << endl
         << "Right view" << endl;
    vector<int> ans6 = rightView(root);
    for (int i = 0; i < ans6.size(); ++i)
    {
        cout << ans6[i] << " ";
    }

    return 0;
}
