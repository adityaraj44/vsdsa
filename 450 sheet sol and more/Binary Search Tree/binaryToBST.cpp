void inOrder(Node *root, vector<int> &in)
{
    if (root == NULL)
        return;
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

Node *inOrderToBST(int start, int end, vector<int> &in)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(in[mid]);
    root->left = inOrderToBST(start, mid - 1, in);
    root->right = inOrderToBST(mid + 1, end, in);
    return root;
}

Node *binaryTreeToBST(Node *root)
{
    vector<int> in;
    inOrder(root, in);
    // sort the inorder array before converting inorder to bst
    sort(in.begin(), in.end());
    // can use merge sort if said
    return inOrderToBST(0, in.size() - 1, in);
}