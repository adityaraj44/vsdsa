vector<int> bottomView(Node *root)
{
    // Your Code Here
    map<int, int> nodes;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *node = temp.first;
        int hd = temp.second;

        nodes[hd] = node->data;

        if (node->left)
        {
            q.push(make_pair(node->left, hd - 1));
        }
        if (node->right)
        {
            q.push(make_pair(node->right, hd + 1));
        }
    }
    for (auto i : nodes)
    {
        ans.push_back(i.second);
    }
}