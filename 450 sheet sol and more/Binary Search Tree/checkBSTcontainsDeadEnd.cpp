void solve(Node *root, bool &ans, unordered_map<int, bool> &visited)
{
    if (root == NULL)
        return;

    visited[root->data] = true;
    solve(root->left, ans, visited);
    solve(root->right, ans, visited);

    if (root->left == NULL && root->right == NULL)
    {
        int xp1 = root->data + 1;
        int xm1 = root->data - 1 == 0 ? root->data : root->data - 1;

        if (visited[xp1] && visited[xm1])
        {
            ans = true;

            return;
        }
    }
}

bool isDeadEnd(Node *root)
{
    bool ans = false;
    unordered_map<int, bool> visited;

    solve(root, ans, visited);

    return ans;
}