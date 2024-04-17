Node *getlca(Node *root, int a, int b)
{
    if (root == NULL)
        return NULL;
    if (root->data == a || root->data == b)
    {
        return root;
    }

    Node *left = getlca(root->left, a, b);
    Node *right = getlca(root->right, a, b);

    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left != NULL && right == NULL)
    {
        return left;
    }
    if (left == NULL && right != NULL)
    {
        return right;
    }
    return NULL;
}

int distance(Node *root, int k, int lev)
{
    if (root == NULL)
        return -1;
    if (root->data == k)
    {
        return lev;
    }
    int left = distance(root->left, k, lev + 1);
    int right = distance(root->right, k, lev + 1);

    if (left == -1 && right != -1)
    {
        return right;
    }
    if (left != -1 && right == -1)
    {
        return left;
    }
}

int findDist(Node *root, int a, int b)
{
    Node *lca = getlca(root, a, b);
    int d1 = distance(lca, a, 0);
    int d2 = distance(lca, b, 0);
    return d1 + d2;
}