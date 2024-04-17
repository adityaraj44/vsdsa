void flatten(Node *root)
{
    // code here
    Node *current = root;
    while (current)
    {
        if (current->left)
        {
            Node *pred = current->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        else
        {
            current = current->right;
        }
    }
}