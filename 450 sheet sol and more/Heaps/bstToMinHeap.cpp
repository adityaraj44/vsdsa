
void minHeapUtil(BinaryTreeNode *root, vector<int> arr, int &index)
{
    if (root == NULL)
    {
        return;
    }
    root->data = arr[index++];
    minHeapUtil(root->left, arr, index);
    minHeapUtil(root->right, arr, index);
}

void inOrder(BinaryTreeNode *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

BinaryTreeNode *convertBST(BinaryTreeNode *root)
{
    vector<int> arr;
    int index = 0;
    inOrder(root, arr);
    minHeapUtil(root, arr, index);
    return root;
}