pair<int, int> diameterFast(Node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    pair<int, int> ans;

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

int diameter(Node *root)
{
    // Your code here
    return diameterFast(root).first;
}