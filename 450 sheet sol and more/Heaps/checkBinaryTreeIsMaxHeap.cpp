
bool isCBT(Node *root, int index, int totalCount)
{
    if (root == NULL)
    {
        return true;
    }
    if (index >= totalCount)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root->left, 2 * index + 1, totalCount);
        bool right = isCBT(root->right, 2 * index + 2, totalCount);
        return left && right;
    }
}

bool isMaxOrder(Node *root)
{
    if (!root->left && !root->right)
    {
        return true;
    }
    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}

bool isHeap(Node *tree)
{
    int index = 0;
    int totalCount = countNodes(tree);
    if (isCBT(tree, index, totalCount) && isMaxOrder(tree))
    {
        return true;
    }
    else
        return false;
}