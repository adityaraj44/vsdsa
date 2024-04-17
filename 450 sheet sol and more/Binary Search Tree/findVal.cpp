// iterative
bool search(Node *root, int x)
{
    // Your code here
    while (root != NULL)
    {
        if (root->data == x)
        {
            return true;
        }
        if (root->data < x)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return false;
}