int solve(Node *root, int &maxSum)
{
    if (root == NULL)
        return 0;

    int currSum = root->data + solve(root->left, maxSum) + solve(root->right, maxSum);

    maxSum = max(maxSum, currSum);

    return currSum;
}

int findLargestSubtreeSum(Node *root)
{
    // Write your code here
    int maxSum = INT_MIN;
    solve(root, maxSum);
    return maxSum;
}