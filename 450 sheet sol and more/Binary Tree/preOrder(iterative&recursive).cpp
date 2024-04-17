// recursive
void preorderSolve(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    ans.push_back(root->data);
    preorderSolve(root->left, ans);
    preorderSolve(root->right, ans);
}

vector<int> preorder(Node *root)
{
    // Your code here
    vector<int> ans;
    preorderSolve(root, ans);
    return ans;
}

// iterative
vector<int> preOrderIterative(Node *root)
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
                ans.push_back(current->data);
                pred->right = current;
                current = current->left;
            }
            else
            {
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
