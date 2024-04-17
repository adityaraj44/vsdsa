void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // Your code goes here
    pre = NULL;
    suc = NULL;
    Node *temp = root;
    while (temp->key != key && temp != NULL)
    {
        if (key > temp->key)
        {

            temp = temp->right;
        }
        else
        {

            temp = temp->left;
        }
    }

    Node *leftKey = temp->left;
    while (leftKey != NULL)
    {
        pre = leftKey;
        leftKey = leftKey->right;
    }

    Node *rightKey = temp->right;
    while (rightKey != NULL)
    {
        suc = rightKey;
        rightKey = rightKey->left;
    }
}