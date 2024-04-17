int minBST(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

Node *deleteNode(Node *root, int X)
{
    // your code goes here
    if (root == NULL)
    {
        return root;
    }
    if (root->data == X)
    {
        // leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->left != NULL && root->right != NULL)
        {
            int min = minBST(root->right);
            root->data = min;
            root->right = deleteNode(root->right, min);
            return root;
        }
    }
    else if (root->data > X)
    {
        root->left = deleteNode(root->left, X);
    }
    else
    {
        root->right = deleteNode(root->right, X);
    }
    return root;
}