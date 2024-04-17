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