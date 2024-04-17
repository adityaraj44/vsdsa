void solve(Node *root, vector<int> &ans, int lev)
{
    if (root == NULL)
    {
        return;
    }

    if (ans.size() == lev)
    {
        ans.push_back(root->data);
    }
    solve(root->right, ans, lev + 1);
    solve(root->left, ans, lev + 1);
}

vector<int> rightView(Node *root)
{
    // Your code here
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}