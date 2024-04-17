int solve(Node *root, int &ans)
{
    // Base Case
    if (root == NULL)
        return 0;

    // Traverse left subtree
    int l = solve(root->left, ans);

    // Traverse right subtree
    int r = solve(root->right, ans);

    // Update number of moves
    ans += abs(l) + abs(r);

    // Return number of moves to balance
    // current node
    return root->key + l + r - 1;
}
int distributeCandy(Node *root)
{
    int ans = 0;
    solve(root, ans);
    return ans;
}