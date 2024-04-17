class info
{
public:
    int max;
    int min;
    bool isBST;
    int size;
};

info solve(TreeNode *root, int &maxSize)
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

int largestBST(TreeNode *root)
{
    // Write your code here.
    int maxSize = 0;
    info ans = solve(root, maxSize);
    return maxSize;
}