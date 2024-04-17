
// recursive
void inOrderSolve(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    inOrderSolve(root->left, ans);
    ans.push_back(root->data);
    inOrderSolve(root->right, ans);
}

// Function to return a list containing the inorder traversal of the tree.
vector<int> inOrder(Node *root)
{
    vector<int> ans;
    inOrderSolve(root, ans);
    return ans;
}
// iterative
vector<int> inOrderIterative(Node *root)
{
    // code here
    vector<int> ans;
    Node *current = root;
    while (current != NULL)
    {
        if (current->left != NULL)
        {
            Node *pred = current->left;
            while (pred->right != NULL && pred->right != current)
            {
                pred = pred->right;
            }

            if (pred->right == NULL)
            {
                pred->right = current;
                current = current->left;
            }
            else
            {
                ans.push_back(current->data);
                pred->right = NULL;
                current = current->right;
            }
        }
        else
        {
            ans.push_back(current->data);
            current = current->right;
        }
    }
    return ans;
}