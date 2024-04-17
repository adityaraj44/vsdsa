pair<bool, int> check(Node *root)
{
    if (root == NULL)
    {
        return {true, 0};
    }

    pair<bool, int> left = check(root->left);
    pair<bool, int> right = check(root->right);

    bool condition = abs(left.second - right.second) <= 1;
    if (left.first && right.first && condition)
    {
        return {true, max(left.second, right.second) + 1};
    }
    else
    {
        return {false, max(left.second, right.second) + 1};
    }
}

bool isBalanced(Node *root)
{
    //  Your Code here
    return check(root).first;
}