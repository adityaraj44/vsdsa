Node *LCA(Node *root, int n1, int n2)
{
    // recursive code
    // if(root==NULL) {
    //     return NULL;
    // }
    // if(root->data < n1 && root->data < n2) {
    //     return LCA(root->right,n1,n2);
    // }
    //  if(root->data > n1 && root->data > n2) {
    //     return LCA(root->left,n1,n2);
    // }
    // return root;

    // iterative code
    while (root != NULL)
    {
        if (root->data < n1 and root->data < n2)
        {
            root = root->right;
        }
        else if (root->data > n1 and root->data > n2)
        {
            root = root->left;
        }
        else
            return root;
    }
}