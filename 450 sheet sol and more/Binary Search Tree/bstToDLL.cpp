void bstToDLL(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }
    bstToDLL(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;
    bstToDLL(root->left, head);
}