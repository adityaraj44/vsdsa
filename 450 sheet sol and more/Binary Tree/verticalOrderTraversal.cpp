vector<int> verticalOrderTraversal(Node *root)
{
    map<int, vector<int>> result;
    vector<int> ans;
    queue<pair<Node *, int>> q;
    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        int hd = temp.second;
        Node *frontNode = temp.first;
        result[hd].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    for (auto i : result)
    {
        for (auto j : i.second)
        {
            ans.push_back(j);
        }
    }
    return ans;
}
