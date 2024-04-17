void solve(Node *&node)
{
    if (node == NULL)
    {
        return;
    }

    solve(node->left);
    solve(node->right);

    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;
}

void mirror(Node *node)
{
    solve(node);
}