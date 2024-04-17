vector<int> zigZagTraversal(Node *root)
{
    // Code here
    vector<int> ans;
    bool isLeftToRight = true;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> v(size);
        for (int i = 0; i < size; ++i)
        {
            Node *front = q.front();
            q.pop();
            int index = isLeftToRight ? i : size - i - 1;
            v[index] = front->data;

            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        isLeftToRight = !isLeftToRight;
        for (auto i : v)
        {
            ans.push_back(i);
        }
    }
    return ans;
}