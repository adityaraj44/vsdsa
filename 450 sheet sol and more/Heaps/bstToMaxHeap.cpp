void inorder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void populate(Node *root, vector<int> &arr, int &index)
{
    if (root == NULL)
    {
        return;
    }

    populate(root->left, arr, index);
    populate(root->right, arr, index);
    root->data = arr[index++];
}

void convertToMaxHeapUtil(Node *root)
{
    vector<int> arr;
    inorder(root, arr);
    int index = 0;
    populate(root, arr, index);
}