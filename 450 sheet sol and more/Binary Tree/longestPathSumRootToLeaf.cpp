void solveLongPath(Node *root, int sum, int &maxSum, int len, int &maxLen)
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
int sumOfLongRootToLeafPath(Node *root)
{
    // code here
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    solveLongPath(root, sum, maxSum, len, maxLen);

    return maxSum;
}