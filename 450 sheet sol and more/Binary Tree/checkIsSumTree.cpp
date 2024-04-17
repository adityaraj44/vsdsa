pair<bool, int> isSumTreeFast(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = isSumTreeFast(root->left);
    pair<bool, int> right = isSumTreeFast(root->right);

    bool leftA = left.first;
    bool rightA = right.first;

    bool condn = root->data == (left.second + right.second);

    pair<bool, int> ans;
    if (leftA && rightA && condn)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
        ans.second = left.second + right.second;
    }
    return ans;
}

bool isSumTree(Node *root)
{
    bool ans = isSumTreeFast(root).first;
    return ans;
}