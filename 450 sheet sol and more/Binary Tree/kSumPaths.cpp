public:
int countPaths(Node *root, int targetSum, int currentSum, unordered_map<int, int> &prefixSum)
{
    if (!root)
        return 0;

    currentSum += root->data;
    int count = prefixSum[currentSum - targetSum];

    prefixSum[currentSum]++;

    count += countPaths(root->left, targetSum, currentSum, prefixSum);
    count += countPaths(root->right, targetSum, currentSum, prefixSum);

    prefixSum[currentSum]--;

    return count;
}

int sumK(Node *root, int k)
{
    if (!root)
        return 0;

    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1; // Initialize with 0 to account for paths starting from root

    return countPaths(root, k, 0, prefixSum);
}