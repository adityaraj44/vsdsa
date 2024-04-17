bool check(Node *root, int min, int max)
{
    if (root == NULL)
        return true;
    if (root->data > min && root->data < max)
    {
        bool left = check(root->left, min, root->data);
        bool right = check(root->right, root->data, max);
        return left && right;
    }
    else
        return false;
}

bool isBST(Node *root)
{
    // Your code here
    return check(root, INT_MIN, INT_MAX);
}