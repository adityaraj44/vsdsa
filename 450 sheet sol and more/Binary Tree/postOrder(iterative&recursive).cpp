// recursive
void postOrderSolve(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    postOrderSolve(root->left, ans);
    postOrderSolve(root->right, ans);
    ans.push_back(root->data);
}

vector<int> postOrder(Node *root)
{
    // Your code here
    vector<int> ans;
    postOrderSolve(root, ans);
    return ans;
}

// iterative
vector<int> postOrderIterative(Node *node)
{
    // code here

    // code here
    vector<int> ans;
    Node *current = node;
    while (current != NULL)
    {
        if (current->right != NULL)
        {
            Node *pred = current->right;
            while (pred->left != NULL && pred->left != current)
            {
                pred = pred->left;
            }

            if (pred->left == NULL)
            {
                ans.push_back(current->data);
                pred->left = current;
                current = current->right;
            }
            else
            {
                pred->left = NULL;
                current = current->left;
            }
        }
        else
        {
            ans.push_back(current->data);
            current = current->left;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}