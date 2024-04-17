void solve(Node *root, vector<vector<int>> &paths, vector<int> &ans, int sum, int target)
{
    if (root == NULL)
        return;

    sum += root->key;
    ans.push_back(root->key);
    if (sum == target)
    {
        paths.push_back(ans);
    }

    if (root->left)
    {
        solve(root->left, paths, ans, sum, target);
    }
    if (root->right)
    {
        solve(root->right, paths, ans, sum, target);
    }
    ans.pop_back();
}

vector<vector<int>> printPaths(Node *root, int sum)
{
    vector<vector<int>> paths;
    vector<int> ans;

    solve(root, paths, ans, 0, sum);
    return paths;
}